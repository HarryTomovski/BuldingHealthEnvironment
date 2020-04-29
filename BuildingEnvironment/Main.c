#include <time.h>
#include <stdbool.h>
#include "Temperature.h"
#include "Humidity.h"
#include "Room.h"
#include "HealthHandler.h"

bool temperature_metricUnits = true; // Definition

static void _delayMs(int milliseconds)
{
	long _pause;
	clock_t _now, _then;

	_pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	_now = _then = clock();
	while ((_now - _then) < _pause)
		_now = clock();
}

static void _setupApplication(void) {
	healthHandler_create();
	room_t livingRoom = room_create("Living Room", 75);
	/*temperature_t temp0 = temperature_create(0);
	temperature_t temp1 = temperature_create(1);*/
	room_addTemperature(livingRoom, temperature_create(0));
	room_addTemperature(livingRoom, temperature_create(1));
//	humidity_t humidity1 = humidity_create(1);
	room_addHumidity(livingRoom, humidity_create(1));
	healthHandler_addRoom(livingRoom);
	room_t kitchen = room_create("Kitchen", 16);
	//temperature_t temp2 = temperature_create(2);
	room_addTemperature(kitchen, temperature_create(2));
//	humidity_t humidity2 = humidity_create(2);
	room_addHumidity(kitchen, humidity_create(2));
	healthHandler_addRoom(kitchen);
}

static void _runApplication(void) {
	while (1) {
		healthHandler_showBuildingHealth();
		_delayMs(1000);
	}
}

int main(void) {
	_setupApplication();
	_runApplication();

	return 0;
}