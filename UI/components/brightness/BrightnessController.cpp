#include "components/brightness/BrightnessController.h"
#include "drivers/PinMap.h"
using namespace Pinetime::Controllers;
void BrightnessController::Init() {}
void BrightnessController::Set(Levels level) { (void)level; }
BrightnessController::Levels BrightnessController::Level() const { return Levels::Medium; }
void BrightnessController::Lower() {}
void BrightnessController::Higher() {}
void BrightnessController::Step() {}
void BrightnessController::ApplyBrightness(uint16_t val) { (void)val; }