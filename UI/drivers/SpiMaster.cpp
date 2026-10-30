#include "drivers/SpiMaster.h"
using namespace Pinetime::Drivers;
SpiMaster::SpiMaster(const SpiModule spi, const Parameters& params) : spiBaseAddress(nullptr), params(params), pinCsn(0) { (void)spi; }
bool SpiMaster::Init() { return true; }
bool SpiMaster::Write(uint8_t pinCsn, const uint8_t* data, size_t size, const std::function<void()>& preTransactionHook) {
  (void)pinCsn; (void)data; (void)size; (void)preTransactionHook; return true;
}
bool SpiMaster::Read(uint8_t pinCsn, uint8_t* cmd, size_t cmdSize, uint8_t* data, size_t dataSize) {
  (void)pinCsn; (void)cmd; (void)cmdSize; (void)data; (void)dataSize; return true;
}
bool SpiMaster::WriteCmdAndBuffer(uint8_t pinCsn, const uint8_t* cmd, size_t cmdSize, const uint8_t* data, size_t dataSize) {
  (void)pinCsn; (void)cmd; (void)cmdSize; (void)data; (void)dataSize; return true;
}
void SpiMaster::Sleep() {}
void SpiMaster::Wakeup() {}