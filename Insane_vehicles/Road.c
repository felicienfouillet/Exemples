#include "Road.h"

void initializeRoad(Road road) {
	int x, y;

	srand(time(NULL));
	for(y=0; y < ROAD_HEIGHT; y++){
		for(x=0; x < ROAD_WIDTH; x++){
			if ((x==0) || (x==ROAD_WIDTH-1)) {							// A test to know if one is on the edge to put a ditch or not //
				setElementRoadXY(road, x, y, ROAD_DITCH);			// We put a ditch on this road //
			} else if(rand()%ROAD_QUOTA == 0){							// Just a small modulo based on a random to have an obstacle or not //
				setElementRoadXY(road, x, y, ROAD_OBSTACLE);	// An obstacle is placed on the road //
			}else{
				setElementRoadXY(road, x, y, ROAD_MACADAM);		// We just put macadam on the road //
			}
		}
	}
}

char getElementRoadXY(Road road, int x, int y) {
	return road[y][x];
}

void setElementRoadXY(Road road, int x, int y, char element) {
	road[y][x] = element;
}

void showRoad(Road road, int yStart) {
	int x, y, view;

	system("CLS");																												// Clear screen	//
	for(y=yStart, view=0; view < ROAD_VIEW; y=(y+1)%ROAD_HEIGHT, view++){	// A modulo to allow the road to start again at the beginning //
		for(x=0; x < ROAD_WIDTH; x++){
			printf("%c", getElementRoadXY(road, x, y));												// The character present in the array is displayed in the console //
		}
		printf("\n");																												// A carriage return to prepare the new line of road //
	}
}
