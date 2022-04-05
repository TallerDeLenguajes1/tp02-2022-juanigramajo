#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 20


int main () {

  int i;
  int vt[N];

  printf("\n");

  for (i = 0; i < N; i++)
    {

      vt[i] = 1 + rand()%100;

      printf ("%d - ", vt[i]);

    }

  printf("\n\n");

  return 0;
}
