#include "MyVehicle.h"

void initializeMyVehicle(MyVehicle *myVehicle, Road road) {
	myVehicle->x = ROAD_WIDTH / 2;
	myVehicle->y = 0;
	putMyVehicleOnRoad(myVehicle, road);
}

void removeMyVehicleFromRoad(MyVehicle *myVehicle, Road road) {
	setElementRoadXY(road, myVehicle->x, myVehicle->y, ROAD_MACADAM);
}

char putMyVehicleOnRoad(MyVehicle *myVehicle, Road road) {
	char lastElementOnRoad = getElementRoadXY(road, myVehicle->x, myVehicle->y);
	setElementRoadXY(road, myVehicle->x, myVehicle->y, MY_VEHICLE);
	return lastElementOnRoad;
}

char moveXYMyVehicle(MyVehicle *myVehicle, int x, int y, Road road) {
	removeMyVehicleFromRoad(myVehicle, road);			// We remove the vehicle //
	myVehicle->x = x;															// The vehicule moves horizontally
	myVehicle->y = y;															// The vehicule moves vertically
	return putMyVehicleOnRoad(myVehicle, road);		// We put again the vehicle
}

// The following three functions use the moveXYMyVehicle() function to really move the car. //
// They all use a modulo to allow the road to curl up on itself. //
char moveForwardMyVehicle(MyVehicle *myVehicle, Road road) {
	return moveXYMyVehicle(myVehicle, myVehicle->x, (myVehicle->y + 1) % ROAD_HEIGHT, road);
}

char moveLeftMyVehicle(MyVehicle *myVehicle, Road road) {
	return moveXYMyVehicle(myVehicle, (myVehicle->x - 1 + ROAD_WIDTH) % ROAD_WIDTH, myVehicle->y, road);
}

char moveRightMyVehicle(MyVehicle *myVehicle, Road road) {
	return moveXYMyVehicle(myVehicle, (myVehicle->x + 1) % ROAD_WIDTH, myVehicle->y, road);
}
