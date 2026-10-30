#pragma once
#include <stdint.h>
#define NRF_PPI_CHANNELS_USED 0
#define NRF_PPI_CHANNELS_SKIP 0xFFFFFFFF
#ifndef NRF_PPI_CHANNEL0
#define NRF_PPI_CHANNEL0 0
#endif
#ifndef NRF_PPI_CHANNEL1
#define NRF_PPI_CHANNEL1 1
#endif
#ifndef NRF_PPI_CHANNEL2
#define NRF_PPI_CHANNEL2 2
#endif
#ifndef NRF_PPI_CHANNEL3
#define NRF_PPI_CHANNEL3 3
#endif
typedef uint32_t nrf_ppi_channel_t;
static inline void nrf_ppi_channel_endpoint_setup(nrf_ppi_channel_t channel, uint32_t eep, uint32_t tep) {
  (void)channel; (void)eep; (void)tep;
}
static inline void nrf_ppi_channel_enable(nrf_ppi_channel_t channel) { (void)channel; }
static inline void nrf_ppi_channel_disable(nrf_ppi_channel_t channel) { (void)channel; }
static inline int nrfx_ppi_channel_alloc(nrf_ppi_channel_t* p_channel) { (void)p_channel; return 0; }
static inline int nrfx_ppi_channel_free(nrf_ppi_channel_t channel) { (void)channel; return 0; }
static inline int nrfx_ppi_channel_assign(nrf_ppi_channel_t channel, uint32_t eep, uint32_t tep) {
  (void)channel; (void)eep; (void)tep; return 0;
}
static inline int nrfx_ppi_channel_enable(nrf_ppi_channel_t channel) { (void)channel; return 0; }
static inline int nrfx_ppi_channel_disable(nrf_ppi_channel_t channel) { (void)channel; return 0; }