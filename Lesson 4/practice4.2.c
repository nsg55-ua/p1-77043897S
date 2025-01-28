#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


int randomBetweenAB (int A, int B);

int main () {

    int A, B;

    printf("Introduce the lower boundary number: ");
    scanf("%i", &A);

    printf("Introduce the upper boundary number: ");
    scanf("%i", &B);

    printf("Your random number %d\n", randomBetweenAB(A, B));

    return 0;
}

int randomBetweenAB(int A, int B){
    srand(time(NULL));
    return A + rand() % B-A+1;
}