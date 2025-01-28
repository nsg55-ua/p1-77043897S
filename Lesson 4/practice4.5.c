#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool countDigits(int digit);
int addEvenFigures(int digit);
int addOddFigures(int digit);

int main() {

    int digit;

    do{
        printf("Introduce a seven digit number: ");
        scanf("%d", &digit);
    } while (!countDigits(digit));

    printf("The sum of the even positions of your number is: %i\n", addEvenFigures(digit));
    printf("The sum of the odd positions of your number is: %i\n", addOddFigures(digit));


    return 0;
}

bool countDigits(int digit){
    if (digit / 1000000 < 10 && digit / 1000000 >= 1 ){
        return true;
    } else{
        return false;
    }
}

int addEvenFigures(int digit){
    int sum = 0;
    for(int i=digit, j=7; i>-1; i/=10, j--){
        if (j%2 == 0){
            sum += (int) i/(pow(10.0, (double) j-1));
        } 
    }
    return sum;
}

int addOddFigures(int digit){
    int sum = 0;
    for(int i=digit, j=7; i>-1; i/=10, j--){
        if (j%2 != 0){
            sum += (int) i/(pow(10.0, (double) j-1));
        } 
    }
    return sum;
}