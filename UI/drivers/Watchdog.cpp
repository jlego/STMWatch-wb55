#include "drivers/Watchdog.h"
using namespace Pinetime::Drivers;
void Watchdog::Setup(uint8_t timeoutSeconds, SleepBehaviour sleepBehaviour, HaltBehaviour haltBehaviour) { (void)timeoutSeconds; (void)sleepBehaviour; (void)haltBehaviour; }
void Watchdog::Start() {}
void Watchdog::Reload() {}
const char* Pinetime::Drivers::ResetReasonToString(Watchdog::ResetReason reason) { (void)reason; return "unknown"; }