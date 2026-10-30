#pragma once
#include <stdint.h>
#include <stddef.h>
static inline uint32_t nrf_sdh_req_wait(void* name) { (void)name; return 0; }
static inline uint32_t nrf_sdh_req_wait_restart(void* name) { (void)name; return 0; }
static inline void nrf_sdh_init(void* const* stack_ptrs) { (void)stack_ptrs; }