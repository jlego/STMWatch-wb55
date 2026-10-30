#include "drivers/Spi.h"
using namespace Pinetime::Drivers;
Spi::Spi(SpiMaster& spiMaster, uint8_t pinCsn) : spiMaster(spiMaster), pinCsn(pinCsn) {}
bool Spi::Init() { return true; }
bool Spi::Write(const uint8_t* data, size_t size, const std::function<void()>& preTransactionHook) {
  (void)data; (void)size; (void)preTransactionHook; return true;
}
bool Spi::Read(uint8_t* cmd, size_t cmdSize, uint8_t* data, size_t dataSize) {
  (void)cmd; (void)cmdSize; (void)data; (void)dataSize; return true;
}
bool Spi::WriteCmdAndBuffer(const uint8_t* cmd, size_t cmdSize, const uint8_t* data, size_t dataSize) {
  (void)cmd; (void)cmdSize; (void)data; (void)dataSize; return true;
}
void Spi::Sleep() {}
void Spi::Wakeup() {}