#include "ogre.h"

void initialiserOgre(Ogre *ogre, Foret foret){
	int x, y;

	do{
		x=rand()%FORET_LONGUEUR;
		y=rand()%FORET_HAUTEUR;
	}while(foret[y][x] != SOL);

	(*ogre).x=x;
	(*ogre).y=y;
}



Ogre *ogrePresent(Ogre *ogre, int x, int y){
	if((*ogre).x != x || (*ogre).y != y){
		return NULL;
	}else{
		return ogre;
	}
}

void deplacerOgre(Ogre *ogre, Foret foret, Enfants enfants, int state){
	int x, y;
	for(int i=0; i<VITESSE_OGRE; i++){
		Direction direction;
		direction = rand()%4;

		x = (*ogre).x;
		y = (*ogre).y;

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
			(*ogre).x = x;
			(*ogre).y = y;

			boulotterEnfants(ogre, enfants, state);
		}
	}
}

void boulotterEnfants(Ogre *ogre, Enfants enfants, int state){
	for (int i=0; i < NOMBRE_ENFANTS; i++){
		if(enfants[i].etat == VIVANT){
			if((enfants[i].x <= (*ogre).x+1 && (enfants[i].x >= (*ogre).x-1)) && (enfants[i].y <= (*ogre).y+1 && enfants[i].y >= (*ogre).y-1)){
				if((enfants[i].x <= (*ogre).x+1 && (enfants[i].x >= (*ogre).x-1)) && (enfants[i].y <= (*ogre).y+1 && enfants[i].y >= (*ogre).y-1)){
					enfants[i].etat=MORT;
					state--;
				}else{
					int shot = rand()%25;

					if(shot==1){
						enfants[i].etat=MORT;
						state--;
					}
				}
			}
		}
	}
}
