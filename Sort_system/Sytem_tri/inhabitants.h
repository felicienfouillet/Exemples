#ifndef INHABITANTS_H
#define INHABITANTS_H

#define MAX_STR_SIZE 20

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

enum zipcode {
  GUADELOUPE = 971,
  STBARTH = 977,
  STMARTIN
};

struct inhabitant {
  int distance;
  char prenom[MAX_STR_SIZE];
  char nom[MAX_STR_SIZE];
  enum zipcode zip;
};


#endif