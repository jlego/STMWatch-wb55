#pragma once
#include <stdint.h>
#include <stddef.h>
typedef enum {
  NRF_GPIO_PIN_NOPULL = 0,
  NRF_GPIO_PIN_PULLDOWN = 1,
  NRF_GPIO_PIN_PULLUP = 3
} nrf_gpio_pin_pull_t;
#define GPIO_PIN_CNF_PULL_Disabled 0
#define NRF_GPIO_PIN_DIR_INPUT 0
#define NRF_GPIO_PIN_DIR_OUTPUT 1
#define NRF_GPIO_PIN_INPUT_DISCONNECT 0
#define NRF_GPIO_PIN_INPUT_CONNECT 1
#define NRF_GPIO_PIN_S0D1 0
#define NRF_GPIO_PIN_S1D0 1
#define NRF_GPIO_PIN_H0H1 2
#define NRF_GPIO_PIN_H0D1 3
#define NRF_GPIO_PIN_D0H1 4
#define NRF_GPIO_PIN_D0S1 5
#define NRF_GPIO_PIN_D1S0 6
#define NRF_GPIO_PIN_H0S1 7
#define NRF_GPIO_PIN_NOSENSE 0
#define NRF_GPIO_PIN_SENSE_HIGH 1
#define NRF_GPIO_PIN_SENSE_LOW 2
static inline void nrf_gpio_cfg_default(uint32_t pin) { (void)pin; }
static inline void nrf_gpio_cfg(uint32_t pin, uint32_t dir, uint32_t input, uint32_t pull, uint32_t drive, uint32_t sense) {
  (void)pin; (void)dir; (void)input; (void)pull; (void)drive; (void)sense;
}
static inline void nrf_gpio_cfg_output(uint32_t pin) { (void)pin; }
static inline void nrf_gpio_cfg_input(uint32_t pin, nrf_gpio_pin_pull_t pull) { (void)pin; (void)pull; }
static inline void nrf_gpio_pin_set(uint32_t pin) { (void)pin; }
static inline void nrf_gpio_pin_clear(uint32_t pin) { (void)pin; }
static inline void nrf_gpio_pin_toggle(uint32_t pin) { (void)pin; }
static inline uint32_t nrf_gpio_pin_read(uint32_t pin) { (void)pin; return 0; }