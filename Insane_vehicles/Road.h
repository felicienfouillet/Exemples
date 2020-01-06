#include "InsaneVehicle.h"
#include <time.h>

#ifndef ROAD_H_INCLUDED
#define ROAD_H_INCLUDED

/**
 * Road is just a two-dimensional array of characters
 */
typedef char Road[ROAD_HEIGHT][ROAD_WIDTH];

/**
 * This function initialize a road.
 * It fills road with ROAD_MACADAM and ROAD_OBSTACLE. It depends of ROAD_QUOTA.
 * The horizontal edges are filled with ROAD_DITCH.
 */
void initializeRoad(Road road);

/**
 * Returns the element (char) that is at the x and y coordinates in the road array
 */
char getElementRoadXY(Road road, int x, int y);

/**
 * Puts the element (char) at the x and y coordinates in the road array
 */
void setElementRoadXY(Road road, int x, int y, char element);

/**
 * Prints the road array in the console.
 * The yStart represents the start of the road. The end is represented by ROAD_VIEW
 */
void showRoad(Road road, int yStart);

#endif // ROAD_H_INCLUDED
