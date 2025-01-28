#include <stdio.h>
#include <math.h>

int main () {
    float num1, num2;

    printf("Write the first number: ");
    scanf("%f", &num1); 
    
    printf("Write the second number: ");
    scanf("%f", &num2);
    
    if (num1 == num2) {
        printf("YOur numbers are equal!");
    }
    else if (num1 < num2) {
        printf("The number %f is smaller than %f \n", num1, num2);
    }
    else {
        printf("The number %.2f is greater than %.2f \n", num1, num2);
    }

    return 0;
}