#include <stdio.h> //input-output

void swapNumbers(float *num1, float *num2);

int main() {
    float number1, number2;

    printf("Introduce the two numbers to be swapped: ");
    scanf("%f %f", &number1, &number2);

    printf("Your numbers before the swap: a=%.2f, b=%.2f\n", number1, number2);

    swapNumbers(&number1, &number2);

    printf("Your numbers after the swap: a=%.2f, b=%.2f\n", number1, number2);
}

void swapNumbers(float *num1, float *num2){
    float auxiliaryVar;

    auxiliaryVar=*num1;
    *num1= *num2;
    *num2= auxiliaryVar;

}