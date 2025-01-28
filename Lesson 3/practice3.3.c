#include <stdio.h>
#include <math.h>

int main () {

    float op1, op2;
    char operator;

    printf("Write your first operand: ");
    scanf("%f", &op1);

    printf("Write your second operand: ");
    scanf("%f", &op2);

    printf("Write your operator: ");
    scanf("%s", &operator);

    switch (operator) {
        case '+': 
            printf("The result is: %.2f \n", op1+op2 );
                break;
        case '-':
            printf("The result is: %.2f \n", op1-op2 );
                break;
        case '*':
            printf("The result is: %.2f \n", op1*op2 );
                break;
        case '/': 
            printf("The result is: %.2f \n", op1/op2 );
                break;
    } 

    return 0;
}