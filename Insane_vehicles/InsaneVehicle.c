#include "InsaneVehicle.h"

void playInsaneVehicle(void) {
	Road road;
	MyVehicle myVehicle;
	char newPositionOnTheRoad = ROAD_MACADAM;

	initializeRoad(road);
	initializeMyVehicle(&myVehicle, road);

	while((newPositionOnTheRoad != ROAD_OBSTACLE) 								// The vehicle hits an obstacle	//
				&&	(newPositionOnTheRoad != ROAD_DITCH)) { 								// The vehicle hits the ditch	//
		showRoad(road, myVehicle.y);																		// Print the road in the console //
		Sleep(ROAD_SPEED);																							// Wait ROAD_SPEED milliseconds	//

		if(GetAsyncKeyState(VK_LEFT)) {																	// Test the left arrow to move the vehicle left //
			newPositionOnTheRoad = moveLeftMyVehicle(&myVehicle, road);
		}
		if(GetAsyncKeyState(VK_RIGHT)) {																// Test the right arrow to move the vehicle right //
			newPositionOnTheRoad = moveRightMyVehicle(&myVehicle, road);
		}
		newPositionOnTheRoad = moveForwardMyVehicle(&myVehicle, road);	// The vehicle can't stop and allways move forward //
	}
	printf("\nCRASH\n");																							// The only way to get out of the loop is to crash //
	system("PAUSE");
}
