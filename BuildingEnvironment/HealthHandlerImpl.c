#include "HealthHandler.h"
#include "Room.h"
#include <stdio.h>
#include <stdlib.h>

	static room_t room[10];
	static int roomIndex;


static void printRoomHealth() {
	for (size_t i = 0; i < roomIndex; i++)
	{
		printf("%s: area: %d m2 Health: %s\n", room_getLocation(room[i]), room_getArea(room[i]), room_getRoomHealthText(room_getRoomHealth(room[i])));
	}
	
}

void healthHandler_create(void) {
	roomIndex=0;
}
void healthHandler_addRoom(room_t self)
{
	if (roomIndex<10)
	{
		room[roomIndex] = self;
		roomIndex++;
		
	}
}

void healthHandler_showBuildingHealth() {
	
		printRoomHealth();
	
}