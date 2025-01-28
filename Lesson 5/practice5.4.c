#include <stdio.h>

void countoddEvenNumbers();

int main() {

    int number;
    int odd = 0;
    int even=-1;
    printf("Introduce a number: ");
    scanf("%d", &number);

    countoddEvenNumbers(number, &odd, &even);
    printf("The # of even digits in your number is: %d\nThe # of odd digits in your number is: %d\n", even, odd);
}

void countoddEvenNumbers(int number, int *odd, int * even){
    if(number>1){
        countoddEvenNumbers(number/10, *&odd, *&even);
    }
    if ((number % 10)%2 == 0){
        *even+=1;
    } else{
        *odd+=1;
    }
}