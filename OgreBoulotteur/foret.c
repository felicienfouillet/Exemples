#include "foret.h"

void initialiserForet(Foret foret){
	int x, y;

	srand(time(NULL));

	for(y=0; y < FORET_HAUTEUR; y++){
		for(x=0; x < FORET_LONGUEUR; x++){
			if(y==0 || y==FORET_HAUTEUR-1 || x==0 || x==FORET_LONGUEUR-1 || rand()%DENSITE==0){
				foret[y][x]=ARBRE;
			}else{
				foret[y][x]=SOL;
			}
		}
	}
}

void afficherForet(Foret foret, Enfants enfants, Ogre *ogre){
	int x, y;

	system("CLS");

	for(y=0; y < FORET_HAUTEUR; y++){
		for(x=0; x < FORET_LONGUEUR; x++){
			if(ogrePresent(ogre, x, y)){
				printf("%c", OGRE);
			}else{
				Enfant *enfant = enfantPresent(enfants, x, y);

				if(enfant==NULL){
						printf("%c", foret[y][x]);
				}else{
					if ((*enfant).etat==VIVANT){
						printf("%c", ENFANT);
					}else{
						printf("%c", ENFANT_MORT);
					}
				}
			}
		}
		printf("\n");
	}
}

void faireVivreForet(Foret foret, Enfants enfants, Ogre *ogre, int state){
	for(;;){
		afficherForet(foret, enfants, ogre);
		deplacerEnfants(enfants, foret);
		deplacerOgre(ogre, foret, enfants, state);
	}
}