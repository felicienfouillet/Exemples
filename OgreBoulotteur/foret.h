#include "ogreboulotteur.h"
#include "enfant.h"
#include "ogre.h"

#ifndef FORET_H_INCLUDED
#define FORET_H_INCLUDED

void initialiserForet(Foret foret);
void afficherForet(Foret foret, Enfants enfants, Ogre *ogre);

void faireVivreForet(Foret foret, Enfants enfants, Ogre *ogre, int state);

#endif