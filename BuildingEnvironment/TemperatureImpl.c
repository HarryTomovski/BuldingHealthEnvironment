#include "Temperature.h"
#include "TemperatureDriver.h"
#include <stdbool.h>
#include<stdlib.h>
extern bool temperature_metricUnits; // Declaration

typedef struct Temperature
{
	float latestTemperature;
	uint8_t portNo;
}Temperature;



static float _calculateTemp(float voltage) {
	return 15.0 + (voltage * 5.0); // dummy calc
}

temperature_t temperature_create(uint8_t portNo) {
	temperature_t newTemp = calloc(sizeof(Temperature), 1);
	if (newTemp!=NULL)
	{
		newTemp->latestTemperature = 0.0;
		newTemp->portNo = portNo;
	}
	temperatureDriver_initDriver(portNo);
	return newTemp;
	
}
void temperature_destroy(temperature_t self)
{
	if (self!=NULL)
	{
		free(self);
	}
}
void temperature_meassure(temperature_t self) {
	self->latestTemperature = _calculateTemp(temperatureDriver_getVoltage());
}

float temperature_getTemperature(temperature_t self) {
	float _tmp = self->latestTemperature;
	if (temperature_metricUnits) {
		_tmp *= 0.2; // dummy conversion
	}

	return _tmp;
}

