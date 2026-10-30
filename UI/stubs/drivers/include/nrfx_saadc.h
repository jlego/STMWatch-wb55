#pragma once
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef uint16_t nrf_saadc_value_t;
typedef uint32_t nrf_saadc_input_t;

#define NRF_SAADC_INPUT_DISABLED 0
#define NRF_SAADC_INPUT_AIN0 1
#define NRF_SAADC_INPUT_AIN1 2
#define NRF_SAADC_INPUT_AIN2 3
#define NRF_SAADC_INPUT_AIN3 4
#define NRF_SAADC_INPUT_AIN4 5
#define NRF_SAADC_INPUT_AIN5 6
#define NRF_SAADC_INPUT_AIN6 7
#define NRF_SAADC_INPUT_AIN7 8
#define NRF_SAADC_INPUT_VDD 9

typedef enum {
  NRF_SAADC_RESISTOR_DISABLED = 0,
  NRF_SAADC_RESISTOR_PULLDOWN,
  NRF_SAADC_RESISTOR_PULLUP,
  NRF_SAADC_RESISTOR_VDD1_2
} nrf_saadc_resistor_t;

typedef enum {
  NRF_SAADC_GAIN1_6 = 0,
  NRF_SAADC_GAIN1_5,
  NRF_SAADC_GAIN1_4,
  NRF_SAADC_GAIN1_3,
  NRF_SAADC_GAIN1_2,
  NRF_SAADC_GAIN1,
  NRF_SAADC_GAIN2,
  NRF_SAADC_GAIN4
} nrf_saadc_gain_t;

typedef enum {
  NRF_SAADC_ACQTIME_3US = 0,
  NRF_SAADC_ACQTIME_5US,
  NRF_SAADC_ACQTIME_10US,
  NRF_SAADC_ACQTIME_15US,
  NRF_SAADC_ACQTIME_20US,
  NRF_SAADC_ACQTIME_40US
} nrf_saadc_acqtime_t;

typedef enum {
  NRF_SAADC_REFERENCE_INTERNAL = 0,
  NRF_SAADC_REFERENCE_VDD1_4
} nrf_saadc_reference_t;

typedef enum {
  NRF_SAADC_MODE_SINGLE_ENDED = 0,
  NRF_SAADC_MODE_DIFFERENTIAL
} nrf_saadc_mode_t;

typedef enum {
  NRF_SAADC_BURST_DISABLED = 0,
  NRF_SAADC_BURST_ENABLED
} nrf_saadc_burst_t;

typedef struct {
  nrf_saadc_resistor_t resistor_p;
  nrf_saadc_resistor_t resistor_n;
  nrf_saadc_gain_t gain;
  nrf_saadc_reference_t reference;
  nrf_saadc_acqtime_t acq_time;
  nrf_saadc_mode_t mode;
  nrf_saadc_burst_t burst;
  nrf_saadc_input_t pin_p;
  nrf_saadc_input_t pin_n;
} nrf_saadc_channel_config_t;

typedef struct {
  nrf_saadc_gain_t gain;
  nrf_saadc_reference_t reference;
  nrf_saadc_acqtime_t acq_time;
  nrf_saadc_burst_t burst;
} nrfx_saadc_config_t;

typedef struct {
  nrf_saadc_value_t* p_buffer;
  uint16_t length;
} nrfx_saadc_buffer_t;

typedef enum {
  NRFX_SAADC_EVT_DONE,
  NRFX_SAADC_EVT_BUF_REQ,
  NRFX_SAADC_EVT_CALIBRATEDONE,
  NRFX_SAADC_EVT_FINISHED
} nrfx_saadc_evt_type_t;

typedef struct {
  nrfx_saadc_evt_type_t type;
  union {
    struct {
      nrf_saadc_value_t* p_buffer;
      uint16_t size;
    } done;
    struct {
      nrfx_saadc_buffer_t p_buffer;
    } buf_req;
  } data;
} nrfx_saadc_evt_t;

typedef void (*nrfx_saadc_evt_handler_t)(nrfx_saadc_evt_t const* p_event);

static inline int nrfx_saadc_init(const nrfx_saadc_config_t* config, nrfx_saadc_evt_handler_t handler) {
  (void)config; (void)handler; return 0;
}
static inline void nrfx_saadc_uninit(void) {}
static inline int nrfx_saadc_channel_init(uint8_t channel, const nrf_saadc_channel_config_t* config) {
  (void)channel; (void)config; return 0;
}
static inline int nrfx_saadc_sample(void) { return 0; }
static inline int nrfx_saadc_buffer_convert(nrf_saadc_value_t* buffer, uint16_t size) {
  (void)buffer; (void)size; return 0;
}

#define NRFX_SAADC_DEFAULT_CONFIG { .gain = NRF_SAADC_GAIN1_6, .reference = NRF_SAADC_REFERENCE_INTERNAL, .acq_time = NRF_SAADC_ACQTIME_10US, .burst = NRF_SAADC_BURST_DISABLED }