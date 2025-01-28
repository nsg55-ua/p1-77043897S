#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int count = 0;
    int number1 = 4;
    int number2 = 2;
    int number3 = 1;


    do{
        int number1 = 1 + rand() % 5;
        int number2 = 1 + rand() % 5;
        int number3 = 1 + rand() % 5;

        count+=3;

        printf("The numbers generated are: %d %d %d\n", number1, number2, number3);

    } while (number1 == number2 || number2 == number3 || number1 == number3);
    
    printf("Total number acount: %d\n", count);
    
    return 0;
}