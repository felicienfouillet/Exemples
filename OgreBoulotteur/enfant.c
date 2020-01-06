#include "enfant.h"

void initialiserEnfants(Enfants enfants, Foret foret){
	for(int i=0; i < NOMBRE_ENFANTS; i++){
		initialiserEnfant(&enfants[i], foret);
	}
}

void initialiserEnfant(Enfant *enfant, Foret foret){
	int x, y;

	do{
		x=rand()%FORET_LONGUEUR;
		y=rand()%FORET_HAUTEUR;
	}while(foret[y][x] != SOL);

	(*enfant).x=x;
	(*enfant).y=y;
	(*enfant).etat=VIVANT;
}

Enfant *enfantPresent(Enfants enfants, int x, int y){
	int i=0;

	while(((enfants[i].x !=x) || (enfants[i].y != y)) && (i < NOMBRE_ENFANTS)){
		i++;
	}

	if (i >= NOMBRE_ENFANTS){
		return NULL;
	}else{
		return &enfants[i];
	}
}

void deplacerEnfants(Enfants enfants, Foret foret){
	for(int i = 0; i < NOMBRE_ENFANTS; i++){
		if(enfants[i].etat==VIVANT){
			deplacerEnfant(&enfants[i], foret);
		}
	}
}

void deplacerEnfant(Enfant *enfant, Foret foret){
	int x, y;

	Direction direction;
	direction = rand()%4;

	x = (*enfant).x;
	y = (*enfant).y;

	switch(direction){
		case HAUT :
			y--;
			break;

		case DROITE :
			x++;
			break;

		case BAS :
			y++;
			break;

		case GAUCHE :
			x--;
			break;
	}

	if (foret[y][x] == SOL){
		(*enfant).x = x;
		(*enfant).y = y;
	}
}