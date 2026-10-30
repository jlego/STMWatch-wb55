#pragma once
#include <stdint.h>
#include <stddef.h>
static inline void nrf_drv_gpiote_init(void) {}
static inline void nrf_drv_gpiote_uninit(void) {}
static inline void nrf_drv_gpiote_in_init(uint32_t pin, void* p_config, void* handler) {
  (void)pin; (void)p_config; (void)handler;
}
static inline void nrf_drv_gpiote_in_uninit(uint32_t pin) { (void)pin; }
static inline void nrf_drv_gpiote_in_event_enable(uint32_t pin, uint8_t int_enable) { (void)pin; (void)int_enable; }
static inline void nrf_drv_gpiote_in_event_disable(uint32_t pin) { (void)pin; }