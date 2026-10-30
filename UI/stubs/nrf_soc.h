#pragma once
#include <stdint.h>
static inline uint32_t nrf_soc_api_svc(uint32_t svc_num, uint32_t* p0, uint32_t* p1, uint32_t* p2, uint32_t* p3, uint32_t* p4, uint32_t* p5) {
  (void)svc_num; (void)p0; (void)p1; (void)p2; (void)p3; (void)p4; (void)p5; return 0;
}
static inline int nrf_soc_app_error_check(int error, const char* file, int line) { (void)error; (void)file; (void)line; return 0; }