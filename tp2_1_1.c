#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 20


int main () {

  int i, vt[N], *pVt;

  pVt = &vt[0];

  printf("\n");

  for (i = 0; i < N; i++)
    {

      *pVt = 1 + rand()%100;

      printf ("%d - ", *pVt);

      pVt++;

    }

  printf("\n\n");

  return 0;
}
