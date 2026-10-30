#include "drivers/InternalFlash.h"
using namespace Pinetime::Drivers;
void InternalFlash::ErasePage(uint32_t address) { (void)address; }
void InternalFlash::WriteWord(uint32_t address, uint32_t value) { (void)address; (void)value; }
void InternalFlash::Wait() {}