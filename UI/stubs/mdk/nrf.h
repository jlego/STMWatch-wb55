#pragma once
#include <stdint.h>
#include <stddef.h>
typedef struct {
  uint32_t RESERVED0[8];
  uint32_t POUT;
  uint32_t _POUT[3];
  uint32_t PIN_CNF[32];
} NRF_GPIO_Type;
typedef struct {
  uint32_t TASKS_START;
  uint32_t RESERVED0[63];
  uint32_t RR[8];
  uint32_t RESERVED1[47];
  uint32_t CONFIG;
  uint32_t RREN;
} NRF_WDT_Type;
typedef struct {
  uint32_t RESERVED0[1];
  uint32_t RESETREAS;
  uint32_t RESERVED1[9];
  uint32_t RAMSTATUS;
} NRF_POWER_Type;
typedef struct {
  uint32_t POWER;
  uint32_t RESERVED0[5];
  uint32_t CLK_SRC;
  uint32_t CLK_FREQUENCY;
  uint32_t RESERVED1[6];
  uint32_t SHORTS;
  uint32_t INTEN;
  uint32_t INTENSET;
  uint32_t INTENCLR;
  uint32_t RESERVED2[45];
  uint32_t EVENTS_STARTED;
  uint32_t EVENTS_STOPPED;
  uint32_t EVENTS_END;
  uint32_t EVENTS_END_RX;
  uint32_t EVENTS_END_TX;
  uint32_t EVENTS_RXSTARTED;
  uint32_t EVENTS_TXSTARTED;
  uint32_t EVENTS_ERROR;
  uint32_t RESERVED3[56];
  uint32_t RX_AMOUNT;
  uint32_t TX_AMOUNT;
  uint32_t ERRORSRC;
  uint32_t RX_PTR;
  uint32_t TX_PTR;
  uint32_t RX_MAXCNT;
  uint32_t TX_MAXCNT;
  uint32_t RX_FIFO_PUSH;
  uint32_t RX_FIFO_POP;
  uint32_t TX_FIFO_PUSH;
  uint32_t TX_FIFO_POP;
  uint32_t RESERVED4[211];
  uint32_t PSEL_SCL;
  uint32_t PSEL_SDA;
  uint32_t RESERVED5[7];
  uint32_t FREQUENCY;
} NRF_TWIM_Type;
typedef struct {
  uint32_t RESERVED0[4];
  uint32_t CONFIG;
  uint32_t SEQ;
  uint32_t EVEND_PITCH;
  uint32_t EVEND_CROSS;
  uint32_t EVEND_STOP;
  uint32_t RESERVED1[56];
  uint32_t EVENT_END;
  uint32_t RESERVED2[58];
  uint32_t TASKS_STOP;
  uint32_t TASKS_EN;
  uint32_t TASKS_DIS;
  uint32_t RESERVED3[59];
  uint32_t INTEN;
  uint32_t INTENSET;
  uint32_t INTENCLR;
  uint32_t RESERVED4[59];
  uint32_t ENABLE;
  uint32_t RESERVED5[63];
  uint32_t TEEP;
  uint32_t RESERVED6[15];
  uint32_t PSEL;
} NRF_GPIOTE_Type;
extern NRF_GPIO_Type NRF_GPIO;
extern NRF_WDT_Type NRF_WDT;
extern NRF_POWER_Type NRF_POWER;
extern NRF_GPIOTE_Type NRF_GPIOTE;