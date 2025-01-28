#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int main () {

    srand(time(NULL));
    int guess;
    int number = 1 + rand() % 100;

    printf("Guess the number in as little tries as possible \n");
    do{
        printf("Introduce a number: ");
        scanf("%d", &guess);
        if(guess > number) {
            printf("The unknown number is lower than yours!\n");
        } else if(guess < number){
            printf("The unknown number is greater than yours!\n");
        } else {
            printf("You guessed it! The number is %d\n", guess);
        }
    } while (guess != number);

    return 0;
}