#pragma once
#include <stdint.h>
static inline uint32_t nrf_rtc_counter_get(uint32_t rtc_index) { (void)rtc_index; return 0; }
static inline void nrf_rtc_task_trigger(uint32_t rtc_index, uint32_t task) { (void)rtc_index; (void)task; }
static inline uint32_t nrf_rtc_event_address_get(uint32_t rtc_index, uint32_t event) { (void)rtc_index; (void)event; return 0; }
static inline void nrf_rtc_event_clear(uint32_t rtc_index, uint32_t event) { (void)rtc_index; (void)event; }
static inline void nrf_rtc_prescaler_set(uint32_t rtc_index, uint32_t prescaler) { (void)rtc_index; (void)prescaler; }
static inline void nrf_rtc_int_enable(uint32_t rtc_index, uint32_t mask) { (void)rtc_index; (void)mask; }
#define NRF_RTC_TASK_START 0
#define NRF_RTC_TASK_STOP 1
#define NRF_RTC_TASK_CLEAR 2
#define NRF_RTC_TASK_TRIGGER_OVERFLOW 3
#define NRF_RTC_EVENT_TICK 0
#define NRF_RTC_EVENT_OVERFLOW 1
#define NRF_RTC_EVENT_COMPARE_0 2
#define NRF_RTC_EVENT_COMPARE_1 3
#define NRF_RTC_EVENT_COMPARE_2 4
#define NRF_RTC_EVENT_COMPARE_3 5
#ifndef portNRF_RTC_REG
#define portNRF_RTC_REG 0
#endif
#ifndef portNRF_RTC_MAXTICKS
#define portNRF_RTC_MAXTICKS 0xFFFFFF
#endif
#ifndef portNRF_RTC_PRESCALER
#define portNRF_RTC_PRESCALER 0
#endif