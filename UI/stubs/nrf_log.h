#pragma once
#ifndef NRF_LOG_H_DONE
#define NRF_LOG_H_DONE 1
#include <stdio.h>
#include <stdarg.h>
#define NRF_LOG_INFO(...) do { (void)(__VA_ARGS__); } while(0);
#define NRF_LOG_DEBUG(...) do { (void)(__VA_ARGS__); } while(0);
#define NRF_LOG_WARNING(...) do { (void)(__VA_ARGS__); } while(0);
#define NRF_LOG_ERROR(...) do { (void)(__VA_ARGS__); } while(0);
#define NRF_LOG_PROGRESS(...) do { (void)(__VA_ARGS__); } while(0);
#define NRF_LOG_FLUSH() do {} while(0);
#define NRF_LOG_DEFAULT_BACKENDS_INIT() do {} while(0);
#define NRF_LOG_PROCESS() do {} while(0);
#define NRF_LOG_TIMESTAMP_DEFAULT_FREQUENCY 0
#endif