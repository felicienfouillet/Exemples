#include "Road.h"

#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

/**
 * MyVehicle is just a simple struct of two int, the coordinates
 */
typedef struct MyVehicle {
	int x, y;
} MyVehicle;

/**
 * Initialize the myVehicle.
 *	x = ROAD_WIDTH / 2
 *	y = 0
 * The Road is updated with MY_VEHICLE character
 */
void initializeMyVehicle(MyVehicle *myVehicle, Road road);

/**
 * myVehicle is deleted from the road.
 * It is necessary to move it forward
 */
void removeMyVehicleFromRoad(MyVehicle *myVehicle, Road road);

/**
 * The Road is updated with MY_VEHICLE character.
 * It is necessary to move it forward, usually after a removeMyVehicleFromRoad() and an update of x or y
 */
char putMyVehicleOnRoad(MyVehicle *myVehicle, Road road);

/**
 * Move the vehicle to (x,y) on the road
 * the char returned is the content of the table where the vehicle moves
 */
char moveXYMyVehicle(MyVehicle *myVehicle, int x, int y, Road road);

/**
 * Move forward the vehicle on the road.
 *	y++
 * the char returned is the content of the table where the vehicle moves
 */
char moveForwardMyVehicle(MyVehicle *myVehicle, Road road);

/**
 * Move left the vehicle on the road.
 *	x--
 * the char returned is the content of the table where the vehicle moves
 */
char moveLeftMyVehicle(MyVehicle *myVehicle, Road road);

/**
 * Move right the vehicle on the road.
 *	x++
 * the char returned is the content of the table where the vehicle moves
 */
char moveRightMyVehicle(MyVehicle *myVehicle, Road road);

#endif // VEHICLE_H_INCLUDED
