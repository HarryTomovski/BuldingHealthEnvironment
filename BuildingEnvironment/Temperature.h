#pragma once
#include <stdint.h>
typedef struct Temperature* temperature_t;
temperature_t temperature_create(uint8_t portNo);
void temperature_destroy(temperature_t self);
void temperature_meassure(temperature_t self);
float temperature_getTemperature(temperature_t self);