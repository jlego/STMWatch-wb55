#pragma once
static inline void NRF_LOG_PROCESS(void) {}
static inline int NRF_LOG_PROCESS_IN_THREAD(void) { return 0; }
static inline int NRF_LOG_INIT(void* param) { (void)param; return 0; }