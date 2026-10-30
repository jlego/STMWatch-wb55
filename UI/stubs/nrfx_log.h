#pragma once
static inline void NRFX_LOG_INFO(const char* fmt, ...) { (void)fmt; }
static inline void NRFX_LOG_DEBUG(const char* fmt, ...) { (void)fmt; }
static inline void NRFX_LOG_WARNING(const char* fmt, ...) { (void)fmt; }
static inline void NRFX_LOG_ERROR(const char* fmt, ...) { (void)fmt; }
#define NRFX_LOG_TIMESTAMP_DEFAULT_FREQUENCY 0