#include <stdlib.h>
#include "inhabitants.h"
#include "sort.h"

void read(FILE *s, struct inhabitant **h, int *m) {
  int i, ntok;
  struct inhabitant *tmph;

  ntok = fscanf(s, "%d", m);
  if(ntok != 1 || *m < 0) {
    fprintf(stderr, "Unable to read file.\n");
    exit(-1);
  }

  if((*h = (struct inhabitant *)malloc(sizeof(struct inhabitant) * (*m))) == NULL) {
    fprintf(stderr, "Unable to allocate space for inhabitants.\n");
    exit(-1);
  }

  tmph = *h;
  for(i = 0; i < (*m); ++i) {
    ntok = fscanf(s, "%d %s %s %d", &(tmph[i].distance), (char *)&(tmph[i].prenom), (char *)&(tmph[i].nom), (int *)&(tmph[i].zip));
    if(ntok != 4) {
      fprintf(stderr, "File wrongly formatted.\n");
      exit(-1);
    }
  }

}

int compare_inhabitants_by_distance(struct inhabitant *a, struct inhabitant *b) {
  return a->distance < b->distance ? -1 : a->distance > b->distance;
}

int compare_inhabitants_by_zipcode(struct inhabitant *a, struct inhabitant *b) {
  return a->zip < b->zip ? -1 : a->zip > b->zip;
}

void show(int n, struct inhabitant *a) {
  int i;
  for(i = 0; i < n; ++i) {
    printf("%d, %s, %s, %d\n", a[i].distance, a[i].prenom, a[i].nom, a[i].zip);
  }
}

void printout(FILE *s, int n, struct inhabitant *a) {
  int i;
  for(i = 0; i < n; ++i) {
    fprintf(s, "%d %s %s %d\n", a[i].distance, a[i].prenom, a[i].nom, a[i].zip);
  }
}

#define PERSONS_TO_SAVE_FILE_IN "../Evacuation_plan/evacuation_plan0.txt"
#define PERSONS_TO_SAVE_FILE_OUT "../Evacuation_plan/better_evacuation_plan0.txt"

int main(int argc, char **argv) {
  FILE *s;
  int n;
  /*For testing purpose :*/
  /*struct inhabitant inhabs[] = {
                                { 100, "Jean", "France", GUADELOUPE },
                                { 10, "Ameni", "Braminia", STBARTH },
                                { 12, "Mathieu", "Krister", GUADELOUPE },
                                { 23, "Hilaire", "Blanchi", STMARTIN }
                              };

  n = sizeof(inhabs) / sizeof(*inhabs);*/

  struct inhabitant *inhabs0;


  if((s = fopen(PERSONS_TO_SAVE_FILE_IN, "r")) == NULL) {
    fprintf(stderr, "Unable to open file.");
    exit(-1);
  }

  //scanf("Saisir le nombre de peresonnes à trier : %i", &n);
  read(s, &inhabs0, &n);
  sort(n, inhabs0, &compare_inhabitants_by_distance);
  sort(n, inhabs0, &compare_inhabitants_by_zipcode);



  if((s = fopen(PERSONS_TO_SAVE_FILE_OUT, "w+")) == NULL) {
    fprintf(stderr, "Unable to open file.");
    exit(-1);
  }
  printout(s, n, inhabs0);
  fclose(s);

  free(inhabs0);

  return EXIT_SUCCESS;
}
