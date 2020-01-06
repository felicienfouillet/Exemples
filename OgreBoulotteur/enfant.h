#include "ogreboulotteur.h"

#ifndef ENFANT_H_INCLUDED
#define ENFANT_H_INCLUDED

void initialiserEnfant(Enfant *enfant, Foret foret);
void initialiserEnfants(Enfants enfants, Foret foret);

void deplacerEnfant(Enfant *enfant, Foret foret);
void deplacerEnfants(Enfants enfants, Foret foret);

Enfant *enfantPresent(Enfants enfants, int x, int y); 

#endif