#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED
#include <stdio.h>
#include <windows.h>

#define ROAD_WIDTH		9				// Width of the road, the limits are ditches //
#define ROAD_HEIGHT		40			// Height of the road, road is a circle, when the limit is reached, it starts again at the beginning //
#define ROAD_QUOTA		20			// The quota corresponds to the density of obstacles on the road //
#define ROAD_VIEW			23			// The view represents the number of road's lines show in the console //
#define ROAD_SPEED		300			// The speed is the time in millisecond that put the car to advance of a line//

#define ROAD_MACADAM		' '		// The character represents macadam //
#define ROAD_DITCH			'|'		// The character represents a ditch //
#define ROAD_OBSTACLE		'X'		// The character represents an obstacle //
#define MY_VEHICLE			'H'		// The character represents the insane player's vehicle //

#include "Road.h"
#include "MyVehicle.h"

/**
 * This function does all the work to be able to play the game.
 */
void playInsaneVehicle(void);

#endif // CONFIG_H_INCLUDED
