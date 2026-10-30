#include "cst816s_touch.h"
#include "stm32wbxx_hal.h"
#include "core_cm4.h"
#include "lvgl_stm32.h"

extern I2C_HandleTypeDef hi2c1;

/* 触摸中断 / 复位引脚 (与 ST7789 的 TP_INT/TP_RST 复用) */
#define CST816S_INT_PIN   GPIO_PIN_3
#define CST816S_INT_PORT  GPIOA
#define CST816S_RST_PIN   GPIO_PIN_2
#define CST816S_RST_PORT  GPIOA

/* 驱动状态 */
static bool     s_ready      = false;
static uint8_t  s_i2c_addr   = CST816S_I2C_ADDR;
static uint8_t  s_chip_id    = 0xFF;
static uint8_t  s_vendor_id  = 0xFF;
static uint8_t  s_fw_version = 0xFF;

/* DWT 周期计数器延迟 - 不依赖 SysTick */
static void cst816s_delay_ms(uint32_t ms)
{
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;

    uint32_t start = DWT->CYCCNT;
    uint32_t target = ms * (SystemCoreClock / 1000u);

    while ((DWT->CYCCNT - start) < target) {
        if ((DWT->CYCCNT - start) > 100000000u) break;
    }
}

/* I2C 总线恢复：释放被从机拉死的 SDA */
static void cst816s_bus_recover(void)
{
    HAL_I2C_DeInit(&hi2c1);

    __HAL_RCC_GPIOB_CLK_ENABLE();
    GPIO_InitTypeDef g = {0};
    g.Pin = GPIO_PIN_6 | GPIO_PIN_7;
    g.Mode = GPIO_MODE_OUTPUT_OD;
    g.Pull = GPIO_PULLUP;
    g.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &g);

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
    for (int i = 0; i < 9; i++) {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
        for (volatile int d = 0; d < 100; d++) __NOP();
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
        for (volatile int d = 0; d < 100; d++) __NOP();
    }

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
    for (volatile int d = 0; d < 100; d++) __NOP();
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
    for (volatile int d = 0; d < 100; d++) __NOP();
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
    for (volatile int d = 0; d < 100; d++) __NOP();
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
    for (volatile int d = 0; d < 100; d++) __NOP();

    g.Pin = GPIO_PIN_6 | GPIO_PIN_7;
    g.Mode = GPIO_MODE_AF_OD;
    g.Pull = GPIO_PULLUP;
    g.Speed = GPIO_SPEED_FREQ_HIGH;
    g.Alternate = GPIO_AF4_I2C1;
    HAL_GPIO_Init(GPIOB, &g);

    HAL_I2C_Init(&hi2c1);
}

static bool cst816s_read(uint8_t reg, uint8_t *data, uint16_t len)
{
    if (hi2c1.State != HAL_I2C_STATE_READY) {
        cst816s_bus_recover();
    }
    if (HAL_I2C_Mem_Read(&hi2c1, (uint16_t)(s_i2c_addr << 1), reg,
                         I2C_MEMADD_SIZE_8BIT, data, len, 50) != HAL_OK) {
        cst816s_bus_recover();
        return false;
    }
    return true;
}

static bool cst816s_write(uint8_t reg, uint8_t val)
{
    if (hi2c1.State != HAL_I2C_STATE_READY) {
        cst816s_bus_recover();
    }
    if (HAL_I2C_Mem_Write(&hi2c1, (uint16_t)(s_i2c_addr << 1), reg,
                          I2C_MEMADD_SIZE_8BIT, &val, 1, 50) != HAL_OK) {
        cst816s_bus_recover();
        return false;
    }
    return true;
}

/* 硬件复位：RST 拉低 5ms，释放后等待 50ms */
static void cst816s_hard_reset(void)
{
    HAL_GPIO_WritePin(CST816S_RST_PORT, CST816S_RST_PIN, GPIO_PIN_RESET);
    cst816s_delay_ms(5);
    HAL_GPIO_WritePin(CST816S_RST_PORT, CST816S_RST_PIN, GPIO_PIN_SET);
    cst816s_delay_ms(50);
}

/* 探测芯片：CST816S 默认地址 0x15，部分批次为 0x2E */
static bool cst816s_probe_addr(uint8_t addr)
{
    uint8_t dummy = 0;
    s_i2c_addr = addr;
    if (HAL_I2C_Mem_Read(&hi2c1, (uint16_t)(addr << 1), CST816S_REG_WAKEUP,
                         I2C_MEMADD_SIZE_8BIT, &dummy, 1, 50) != HAL_OK) {
        return false;
    }
    cst816s_delay_ms(5);
    if (HAL_I2C_Mem_Read(&hi2c1, (uint16_t)(addr << 1), CST816S_REG_CHIP_ID,
                         I2C_MEMADD_SIZE_8BIT, &dummy, 1, 50) != HAL_OK) {
        return false;
    }
    return true;
}

bool cst816s_touch_init(void)
{
    GPIO_InitTypeDef gpio = {0};

    s_ready = false;
    s_chip_id = 0xFF;
    s_vendor_id = 0xFF;
    s_fw_version = 0xFF;

    /* 重新初始化 I2C1，确保总线处于干净状态 */
    HAL_I2C_DeInit(&hi2c1);
    HAL_I2C_Init(&hi2c1);
    HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE);
    HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0);

    __HAL_RCC_GPIOA_CLK_ENABLE();

    /* RST: 推挽输出 */
    gpio.Pin = CST816S_RST_PIN;
    gpio.Mode = GPIO_MODE_OUTPUT_PP;
    gpio.Pull = GPIO_NOPULL;
    gpio.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(CST816S_RST_PORT, &gpio);

    /* INT: 下降沿中断 + 上拉 */
    gpio.Pin = CST816S_INT_PIN;
    gpio.Mode = GPIO_MODE_IT_FALLING;
    gpio.Pull = GPIO_PULLUP;
    gpio.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(CST816S_INT_PORT, &gpio);

    HAL_NVIC_SetPriority(EXTI3_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(EXTI3_IRQn);

    /* 硬件复位 */
    cst816s_hard_reset();

    /* 唤醒并确认通信：优先 0x15，失败则尝试 0x2E（部分模块出厂地址不同） */
    s_i2c_addr = CST816S_I2C_ADDR;
    if (!cst816s_probe_addr(CST816S_I2C_ADDR)) {
        if (!cst816s_probe_addr(0x2E)) {
            /* 探测失败不阻断初始化，仍按默认地址尝试配置 */
            s_i2c_addr = CST816S_I2C_ADDR;
        }
    }

    /* 读取设备标识（读取失败不影响后续配置） */
    cst816s_read(CST816S_REG_CHIP_ID, &s_chip_id, 1);
    cst816s_read(CST816S_REG_VENDOR_ID, &s_vendor_id, 1);
    cst816s_read(CST816S_REG_FW_VERSION, &s_fw_version, 1);

    /*
     * [2] EnConLR - 连续左右滑动
     * [1] EnConUD - 连续上下滑动
     * [0] EnDClick - 双击
     */
    cst816s_write(CST816S_REG_MOTION_MASK, 0x05);

    /*
     * [6] EnTouch  - 触摸状态变化时产生低脉冲
     * [5] EnChange - 触摸状态改变时产生低脉冲
     * [4] EnMotion - 检测到手势时产生低脉冲
     */
    cst816s_write(CST816S_REG_IRQ_CTRL, 0x70);

    /* 关闭 5 秒无手势自动复位（自动复位会打断持续触摸） */
    cst816s_write(CST816S_REG_AUTO_RESET, 0x00);

    cst816s_delay_ms(10);

    s_ready = true;
    return true;
}

cst816s_touch_info_t cst816s_touch_get_info(void)
{
    cst816s_touch_info_t info = {0};
    uint8_t buf[6] = {0};

    info.valid = false;

    if (!s_ready) {
        return info;
    }

    /* 从 0x01 开始连续读取 6 字节：手势 / 点数 / XH / XL / YH / YL */
    if (!cst816s_read(CST816S_REG_GESTURE, buf, sizeof(buf))) {
        return info;
    }

    uint8_t fingers = buf[1] & 0x0F;
    uint16_t raw_x = (uint16_t)(((buf[2] & 0x0F) << 8) | buf[3]);
    uint16_t raw_y = (uint16_t)(((buf[4] & 0x0F) << 8) | buf[5]);
    uint8_t gesture = buf[0];

    uint16_t x = raw_x;
    uint16_t y = raw_y;

#if CST816S_SWAP_XY
    x = raw_y;
    y = raw_x;
#endif
#if CST816S_MIRROR_X
    x = (uint16_t)((LV_HOR_RES_MAX - 1) - x);
#endif
#if CST816S_MIRROR_Y
    y = (uint16_t)((LV_VER_RES_MAX - 1) - y);
#endif

    info.x = x;
    info.y = y;
    info.gesture = gesture;
    info.touching = (fingers > 0);
    info.valid = true;

    return info;
}

uint8_t cst816s_touch_get_chip_id(void)
{
    return s_chip_id;
}

uint8_t cst816s_touch_get_vendor_id(void)
{
    return s_vendor_id;
}

uint8_t cst816s_touch_get_fw_version(void)
{
    return s_fw_version;
}

uint8_t cst816s_touch_get_i2c_addr(void)
{
    return s_i2c_addr;
}

bool cst816s_touch_is_ready(void)
{
    return s_ready;
}

void cst816s_touch_sleep(void)
{
    if (!s_ready) return;
    cst816s_hard_reset();
    cst816s_write(CST816S_REG_SLEEP_MODE, 0x03);
}

void cst816s_touch_wakeup(void)
{
    if (!s_ready) return;
    cst816s_touch_init();
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == CST816S_INT_PIN) {
        lvgl_touch_irq_handler();
    }
}