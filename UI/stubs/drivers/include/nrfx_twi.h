#pragma once
#include <stdint.h>
#include <stddef.h>
#define NRFX_TWI_ERR_DROPPING_START 0x00000001
#define NRFX_TWI_ERR_MISSING_ACK 0x00000002
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
  NRF_TWIM_Type* p_reg;
  uint32_t frequency;
  uint8_t sda;
  uint8_t scl;
  uint8_t interrupt_priority;
} nrfx_twi_config_t;
typedef struct {
  uint8_t address;
  const uint8_t* p_data;
  size_t length;
} nrfx_twi_xfer_desc_t;
static inline int nrfx_twi_init(int instance_id, const nrfx_twi_config_t* p_config, void* event_handler, void* p_context) {
  (void)instance_id; (void)p_config; (void)event_handler; (void)p_context; return 0;
}
static inline void nrfx_twi_uninit(int instance_id) { (void)instance_id; }
static inline void nrfx_twi_enable(int instance_id) { (void)instance_id; }
static inline void nrfx_twi_disable(int instance_id) { (void)instance_id; }
static inline int nrfx_twi_xfer(int instance_id, const nrfx_twi_xfer_desc_t* p_xfer_desc, uint32_t flags) {
  (void)instance_id; (void)p_xfer_desc; (void)flags; return 0;
}