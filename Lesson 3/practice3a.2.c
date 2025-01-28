#include <stdio.h>
#include <math.h>

int main () {

    int num , lastDivisor;

    do {
        printf("Introduce an integer number: ");
        scanf("%d", &num);

    } while (num < 0);

    printf("Divisors of %d: ", num);

    for (int i=1; i< num +1; i++) {
        if (i==num) {
            printf("%d - ", i); 
        } //this if statement is only for stetical purposes
        else if (num % i == 0) {
            printf("%d, ", i);
            lastDivisor = i; //always store the current i value (which is a divisor) to check then if num is prime
        }
    }

    if (lastDivisor == 1) { // if the last i value that was a divisor is 1, then its prime (lastDivisor hasn't stored a number since 1)
        printf("Your number is prime \n");
    } else {
        printf("Your number is not prime \n");
    }

    return 0;
}