#pragma once
#include <stdint.h>
#include <stddef.h>
static inline void nrf_drv_clock_init(void) {}
static inline int nrf_drv_clock_init_check(void) { return 1; }
static inline int nrf_drv_clock_lfclk_request(void* p_handler) { (void)p_handler; return 0; }
static inline int nrf_drv_clock_hfclk_request(void* p_handler) { (void)p_handler; return 0; }
static inline bool nrf_drv_clock_lfclk_is_running(void) { return true; }
static inline bool nrf_drv_clock_hfclk_is_running(void) { return true; }
static inline int nrf_drv_clock_lfclk_release(void) { return 0; }
static inline int nrf_drv_clock_hfclk_release(void) { return 0; }