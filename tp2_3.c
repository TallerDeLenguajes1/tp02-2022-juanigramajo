#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 5
#define M 7

int main () {

    srand(time(NULL));
    int i, j;
    int mt[N][M];
    int *puntero = &mt[0][0];

    for(i=0;i<N; i++){
        
        for(j=0;j<M; j++){

            *(puntero + (i*7+j)) = 1 + rand()%100;

            printf("%d - ", *(puntero + (i*7+j)));
        }
        
        printf("\n");
    }

  return 0;
}