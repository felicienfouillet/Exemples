#include "ogreboulotteur.h"

int main(){
    Foret foret;
    Enfants enfants;
    Ogre ogre;

    int state;
    state = NOMBRE_ENFANTS - 1;

    initialiserForet(foret);
    initialiserEnfants(enfants, foret);
    initialiserOgre(&ogre, foret);

    do{
    	faireVivreForet(foret, enfants, &ogre, state);	
    }while(state != 0);

    return 0;
}