#pragma once
#include <stdint.h>
#include <stddef.h>
typedef uint32_t nrfx_gpiote_pin_t;
typedef struct {
  uint8_t sense;
  uint8_t polarity;
  uint8_t mode;
} nrfx_gpiote_in_config_t;
typedef struct {
  uint8_t drive;
  uint8_t input;
  uint8_t mode;
  uint8_t pull;
} nrfx_gpiote_out_config_t;
#define NRFX_GPIOTE_CONFIG_IN_SENSE_LOTOHI(x) { .sense = 0, .polarity = 0, .mode = (x ? 1 : 2) }
#define NRFX_GPIOTE_CONFIG_IN_SENSE_HITOLO(x) { .sense = 0, .polarity = 1, .mode = (x ? 1 : 2) }
#define NRFX_GPIOTE_CONFIG_IN_SENSE_TOGGLE(x) { .sense = 0, .polarity = 2, .mode = (x ? 1 : 2) }
static inline int nrfx_gpiote_init(uint8_t interrupt_priority) { (void)interrupt_priority; return 0; }
static inline void nrfx_gpiote_uninit(void) {}
static inline void nrfx_gpiote_in_init(nrfx_gpiote_pin_t pin, const nrfx_gpiote_in_config_t* p_config, void* event_handler) {
  (void)pin; (void)p_config; (void)event_handler;
}
static inline void nrfx_gpiote_in_uninit(nrfx_gpiote_pin_t pin) { (void)pin; }
static inline void nrfx_gpiote_in_event_enable(nrfx_gpiote_pin_t pin, uint8_t int_enable) { (void)pin; (void)int_enable; }
static inline void nrfx_gpiote_in_event_disable(nrfx_gpiote_pin_t pin) { (void)pin; }
static inline void nrfx_gpiote_out_init(nrfx_gpiote_pin_t pin, const nrfx_gpiote_out_config_t* p_config) {
  (void)pin; (void)p_config;
}
static inline void nrfx_gpiote_out_uninit(nrfx_gpiote_pin_t pin) { (void)pin; }
static inline void nrfx_gpiote_out_set(nrfx_gpiote_pin_t pin) { (void)pin; }
static inline void nrfx_gpiote_out_clear(nrfx_gpiote_pin_t pin) { (void)pin; }
static inline void nrfx_gpiote_out_toggle(nrfx_gpiote_pin_t pin) { (void)pin; }
static inline uint32_t nrfx_gpiote_in_event_addr_get(nrfx_gpiote_pin_t pin) { (void)pin; return 0; }