#include <stdio.h>
#include <time.h>
#include <stddef.h>

#include "humidityDriver.h"

void humidityDriver_initDriver(uint8_t portno) {
	srand(time(NULL));
}

uint8_t humidityDriver_getHumidity() {
	return (rand() % (85 - 35 + 1)) + 35;
}