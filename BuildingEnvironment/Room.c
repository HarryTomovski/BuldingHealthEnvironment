#include <string.h>
#include "Room.h"
#include "Temperature.h"
#include "Humidity.h"
#include <stdlib.h>

typedef struct Room
{
	char location[30];
	uint16_t squareMeters;
	temperature_t temperature[4];
	humidity_t humidity[2];
	int temperatureIndex;
	int HumidityIndex;
}Room;
room_roomHealth_t _calculateHealth(float temp, uint8_t hum) {
	return (uint16_t)(temp * hum) % 5;// dummy calculation; 
}

room_t room_create(char* location, uint16_t sqMeter) {
	room_t newRoom = calloc(sizeof(Room), 1);
	if (newRoom!=NULL)
	{
		strcpy(newRoom->location, location,sizeof(newRoom->location)-1);
		newRoom->squareMeters = sqMeter;
		newRoom->temperatureIndex = 0;
		newRoom->HumidityIndex = 0;
		return newRoom;
	}
	return NULL;

}
void room_destroy(room_t self)
{
	if (self!=NULL)
	{
		free(self);
	}
}
void room_addTemperature(room_t self, temperature_t temp)
{
	if (self!=NULL)
	{
		if (self->temperatureIndex<4)
		{
			self->temperature[self->temperatureIndex] = temp;
			self->temperatureIndex++;
		}
	}
}
void room_addHumidity(room_t self, humidity_t humidity)
{
	if (self!=NULL)
	{
		if (self->HumidityIndex<2)
		{
			self->humidity[self->HumidityIndex] = humidity;
			self->HumidityIndex++;                                    
		}
	}
}
// calculates health based on all the temperature and humidity values
room_roomHealth_t room_getRoomHealth(room_t self) {
	float temp = 0;
	int number = 0;
	for (size_t i = 0; i < self->temperatureIndex; i++)
	{
		temperature_t t = self->temperature[i];
		
			temperature_meassure(t);
			temp += temperature_getTemperature(t);
			number++;
		
	}
	temp = temp / number;
	number = 0;
	uint8_t humidity=0;
	for (size_t i = 0; i < self->HumidityIndex; i++)
	{
		humidity_t h = (humidity_t)self->humidity[i];
	
			humidity_meassure(h);

			humidity += humidity_getHumidity(h);
			number++;
		
	}
	humidity = humidity / number;
	room_roomHealth_t health = _calculateHealth(temp, humidity);
	return health;
}

char* room_getRoomHealthText(room_roomHealth_t health) {
	static const char* _health_text[] = { "PERFECT", "GOOD", "AVERAGE", "BAD", "DISASTER" };
	return _health_text[health];
}

char* room_getLocation(room_t self) {
	return self->location;
}

uint16_t room_getArea(room_t self) {
	return self->squareMeters;
}