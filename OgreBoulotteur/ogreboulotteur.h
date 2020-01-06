#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef OGREBOULOTTEUR_H_INCLUDED
#define OGREBOULOTTEUR_H_INCLUDED

#define FORET_HAUTEUR 20
#define FORET_LONGUEUR 40

#define DENSITE 7

#define SOL ' '
#define ARBRE 35

#define ENFANT 101
#define NOMBRE_ENFANTS 15
#define ENFANT_MORT 43

#define OGRE 79
#define VITESSE_OGRE 2

typedef char Foret[FORET_HAUTEUR][FORET_LONGUEUR];

typedef enum Etat{VIVANT, MORT} Etat;

typedef struct Enfant{
	int x;
	int y;
	Etat etat;
} Enfant;

typedef Enfant Enfants[NOMBRE_ENFANTS];

typedef struct Ogre{
	int x;
	int y;
} Ogre;

typedef enum Direction{HAUT, DROITE, BAS, GAUCHE} Direction;

#endif


/*
A -> 65
e -> 101
O -> 79
D -> 68
Enfants - > alt + 1 -> ☺
Arbres -> alt + 5 -> ♣
Ogre -> alt + 2 -> ☻
Enfant Mort -> alt + 43 -> +

. -> alt + 46
# -> alt + 35
*/
