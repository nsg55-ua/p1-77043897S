#include <stdio.h>

void countDigits();

int main(){
    int digits=-1; //Recursive function prints one more digit, -1 is just to cancel it out
    int number;

    printf("Introduce a number: ");
    scanf("%d", &number);

    countDigits(number, &digits);
    printf("# of digits: %d\n", digits);

    return 0;
}

void countDigits(int number, int *digits){
    if(number>1){
        countDigits(number/10, *&digits);
    }
    *digits +=1;
}

