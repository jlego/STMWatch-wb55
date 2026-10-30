#include "drivers/TwiMaster.h"
using namespace Pinetime::Drivers;
TwiMaster::TwiMaster(NRF_TWIM_Type* module, uint32_t frequency, uint8_t pinSda, uint8_t pinScl)
  : twiBaseAddress(module), module(module), frequency(frequency), pinSda(pinSda), pinScl(pinScl) {}
void TwiMaster::Init() {}
TwiMaster::ErrorCodes TwiMaster::Read(uint8_t deviceAddress, uint8_t registerAddress, uint8_t* buffer, size_t size) {
  (void)deviceAddress; (void)registerAddress; (void)buffer; (void)size; return ErrorCodes::NoError;
}
TwiMaster::ErrorCodes TwiMaster::Write(uint8_t deviceAddress, uint8_t registerAddress, const uint8_t* data, size_t size) {
  (void)deviceAddress; (void)registerAddress; (void)data; (void)size; return ErrorCodes::NoError;
}
void TwiMaster::Sleep() {}
void TwiMaster::Wakeup() {}
TwiMaster::ErrorCodes TwiMaster::Read(uint8_t deviceAddress, uint8_t* buffer, size_t size, bool stop) {
  (void)deviceAddress; (void)buffer; (void)size; (void)stop; return ErrorCodes::NoError;
}
TwiMaster::ErrorCodes TwiMaster::Write(uint8_t deviceAddress, const uint8_t* data, size_t size, bool stop) {
  (void)deviceAddress; (void)data; (void)size; (void)stop; return ErrorCodes::NoError;
}
void TwiMaster::FixHwFreezed() {}
void TwiMaster::ConfigurePins() const {}