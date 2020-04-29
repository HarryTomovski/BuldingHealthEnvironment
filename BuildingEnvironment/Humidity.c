#include <stdint.h>
#include "HumidityDriver.h"
#include "Humidity.h"
#include <stdlib.h>
typedef struct Humidity
{
	uint8_t latestHumidity;
}Humidity;

humidity_t humidity_create(uint8_t portNo) {
	humidity_t newHumidity = calloc(sizeof(Humidity), 1);
	if (newHumidity!=NULL)
	{
		newHumidity->latestHumidity = 0.0;
		humidityDriver_initDriver(portNo);
		return newHumidity;
	}
	return NULL;
	
}

void humidity_meassure(humidity_t self) {
	self->latestHumidity = humidityDriver_getHumidity();
}

uint8_t humidity_getHumidity(humidity_t self) {
	return self->latestHumidity;
}