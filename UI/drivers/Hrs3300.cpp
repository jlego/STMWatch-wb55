#include "drivers/Hrs3300.h"
using namespace Pinetime::Drivers;
Hrs3300::Hrs3300(TwiMaster& twiMaster, uint8_t twiAddress) : twiMaster {twiMaster}, twiAddress {twiAddress} {}
void Hrs3300::Init() {}
void Hrs3300::Enable() {}
void Hrs3300::Disable() {}
Hrs3300::PackedHrsAls Hrs3300::ReadHrsAls() { return {0, 0}; }
void Hrs3300::WriteRegister(uint8_t reg, uint8_t data) { (void)reg; (void)data; }
uint8_t Hrs3300::ReadRegister(uint8_t reg) { (void)reg; return 0; }