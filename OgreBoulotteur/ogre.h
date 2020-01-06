#include "ogreboulotteur.h"
#include "enfant.h"

#ifndef OGRE_H_INCLUDED
#define OGRE_H_INCLUDED

void initialiserOgre(Ogre *ogre, Foret foret);

void deplacerOgre(Ogre *ogre, Foret foret, Enfants enfants, int state);

Ogre *ogrePresent(Ogre *ogre, int x, int y); 

void boulotterEnfants(Ogre *ogre, Enfants enfants, int state);

#endif