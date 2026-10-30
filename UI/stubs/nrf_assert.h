#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "nrf_errors.h"

#ifdef __cplusplus
extern "C" {
#endif

static inline void AssertionFailed(const char* file, int line) {
  (void)file; (void)line;
}

#ifdef __cplusplus
}
#endif

#define ASSERT(x) do { if(!(x)) { AssertionFailed(__FILE__, __LINE__); } } while(0)
#define APP_ERROR_CHECK(err) do { if((err) != 0) { AssertionFailed(__FILE__, __LINE__); } } while(0)
#define APP_ERROR_CHECK_BOOL(expr) do { if(!(expr)) { AssertionFailed(__FILE__, __LINE__); } } while(0)