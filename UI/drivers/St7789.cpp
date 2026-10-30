#include "drivers/St7789.h"
using namespace Pinetime::Drivers;
St7789::St7789(Spi& spi, uint8_t pinDataCommand, uint8_t pinReset) : spi(spi), pinDataCommand(pinDataCommand), pinReset(pinReset) {}
void St7789::Init() {}
void St7789::Uninit() {}
void St7789::VerticalScrollStartAddress(uint16_t line) { (void)line; }
void St7789::DrawBuffer(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const uint8_t* data, size_t size) {
  (void)x; (void)y; (void)width; (void)height; (void)data; (void)size;
}
void St7789::LowPowerOn() {}
void St7789::LowPowerOff() {}
void St7789::Sleep() {}
void St7789::Wakeup() {}
void St7789::HardwareReset() {}