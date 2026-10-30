#pragma once
#include <stdio.h>
#include <stdarg.h>
static inline void NRF_LOG_INFO(const char* fmt, ...) { (void)fmt; }
static inline void NRF_LOG_DEBUG(const char* fmt, ...) { (void)fmt; }
static inline void NRF_LOG_WARNING(const char* fmt, ...) { (void)fmt; }
static inline void NRF_LOG_ERROR(const char* fmt, ...) { (void)fmt; }
static inline void NRF_LOG_PROGRESS(const char* fmt, ...) { (void)fmt; }
static inline void NRF_LOG_DEFAULT_BACKENDS_INIT(void) {}
#define NRF_LOG_TIMESTAMP_DEFAULT_FREQUENCY 0