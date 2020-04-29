#pragma once
#include <stdint.h>
#include "Temperature.h"
#include "Humidity.h"
typedef enum {
	PERFECT
	, GOOD
	, AVERAGE
	, BAD
	, DISASTER
}room_roomHealth_t;
typedef struct Room* room_t;
room_t room_create(char* location, uint16_t sqMeter);
void room_destroy(room_t self);
void room_addTemperature(room_t self, temperature_t temp);
void room_addHumidity(room_t self, humidity_t humidity);
room_roomHealth_t room_getRoomHealth(room_t self);
char* room_getRoomHealthText(room_roomHealth_t health);
char* room_getLocation(room_t self);
uint16_t room_getArea(room_t self);