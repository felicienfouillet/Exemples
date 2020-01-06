#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "inhabitants.h"

void sort(int n, struct inhabitant *a, int (cmp)(struct inhabitant *, struct inhabitant *));

#endif