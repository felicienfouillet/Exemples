#include "sort.h"

void fuse(struct inhabitant *a, struct inhabitant *tmp, int s0, int e0, int s1, int e1, int (cmp)(struct inhabitant *, struct inhabitant *)){
  int i0 = s0;
	for(; i0 < e1; ++i0) {
		if(s1 == e1 || (s0 < e0 && (cmp(&a[s0], &a[s1]) <= 0))) {
			tmp[i0] = a[s0];
			s0++;
		}
		else {
			tmp[i0] = a[s1];
			s1++;
		}
	}
}

void sort(int n, struct inhabitant *a, int (cmp)(struct inhabitant *, struct inhabitant *)) {
	int p0, e0, e1, strd = 1;

	struct inhabitant *tmp, *tmp0, *orig = a;

  if((tmp = malloc(n * sizeof(struct inhabitant))) == NULL) {
    fprintf(stderr, "Unable to malloc enough memory in sorting function.\n");
    exit(-1);
  }

	for(;strd < n;) {
		for(p0 = 0; p0 < (n - (2 * strd)) + 1; p0 = p0 + 2 * strd) {
			e0 = p0 + strd;
			e1 = e0 + strd;

			fuse(a, tmp, p0, e0, e0, e1, cmp);
		}
		if(p0 < n) {
			e0 = p0 + strd;
			e1 = e0 + strd;

			if(e0 > n) e0 = n;
			if(e1 > n) e1 = n;

			fuse(a, tmp, p0, e0, e0, e1, cmp);
		}

		tmp0 = a;
		a = tmp;
		tmp = tmp0;

		strd *= 2;
	}

	if(n >= 2 && tmp == orig) {
		for(p0 = 0; p0 < n; ++p0) {
			orig[p0] = a[p0];
		}
	}
}
