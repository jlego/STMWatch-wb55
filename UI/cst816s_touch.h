#ifndef CST816S_TOUCH_H
#define CST816S_TOUCH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

/* CST816S I2C地址 (7-bit) */
#define CST816S_I2C_ADDR            0x15

/* CST816S寄存器地址 */
#define CST816S_REG_GESTURE         0x01
#define CST816S_REG_FINGER_NUM      0x02
#define CST816S_REG_XPOS_H          0x03
#define CST816S_REG_XPOS_L          0x04
#define CST816S_REG_YPOS_H          0x05
#define CST816S_REG_YPOS_L          0x06
#define CST816S_REG_WAKEUP          0x15
#define CST816S_REG_SLEEP_MODE      0xA5
#define CST816S_REG_CHIP_ID         0xA7
#define CST816S_REG_VENDOR_ID       0xA8
#define CST816S_REG_FW_VERSION      0xA9
#define CST816S_REG_MOTION_MASK     0xEC
#define CST816S_REG_IRQ_CTRL        0xFA
#define CST816S_REG_AUTO_RESET      0xFB

/* 手势定义 */
#define CST816S_GESTURE_NONE        0x00
#define CST816S_GESTURE_SLIDE_DOWN  0x01
#define CST816S_GESTURE_SLIDE_UP    0x02
#define CST816S_GESTURE_SLIDE_LEFT  0x03
#define CST816S_GESTURE_SLIDE_RIGHT 0x04
#define CST816S_GESTURE_SINGLE_TAP  0x05
#define CST816S_GESTURE_DOUBLE_TAP  0x0B
#define CST816S_GESTURE_LONG_PRESS  0x0C

/* 坐标方向配置：面板与触摸屏安装方向不一致时，修改以下宏 */
#ifndef CST816S_SWAP_XY
#define CST816S_SWAP_XY   0
#endif
#ifndef CST816S_MIRROR_X
#define CST816S_MIRROR_X  0
#endif
#ifndef CST816S_MIRROR_Y
#define CST816S_MIRROR_Y  0
#endif

/* 触摸信息 */
typedef struct {
    uint16_t x;
    uint16_t y;
    uint8_t gesture;
    bool touching;
    bool valid;
} cst816s_touch_info_t;

/* 初始化CST816S触摸驱动 */
bool cst816s_touch_init(void);

/* 获取触摸信息 */
cst816s_touch_info_t cst816s_touch_get_info(void);

/* 读取芯片ID */
uint8_t cst816s_touch_get_chip_id(void);

/* 读取厂商ID */
uint8_t cst816s_touch_get_vendor_id(void);

/* 读取固件版本 */
uint8_t cst816s_touch_get_fw_version(void);

/* 获取探测到的I2C地址 */
uint8_t cst816s_touch_get_i2c_addr(void);

/* 驱动是否已初始化 */
bool cst816s_touch_is_ready(void);

/* 触摸休眠 */
void cst816s_touch_sleep(void);

/* 触摸唤醒 */
void cst816s_touch_wakeup(void);

#ifdef __cplusplus
}
#endif

#endif /* CST816S_TOUCH_H */