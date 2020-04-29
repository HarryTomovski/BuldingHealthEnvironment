#pragma once
#include <stdint.h>

void humidityDriver_initDriver(uint8_t portNo);
uint8_t humidityDriver_getHumidity();