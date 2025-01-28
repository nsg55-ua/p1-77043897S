#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void CalculateGreatestAndLowest(float *a, float *b, float *c);

int main (){

    float a, b, c;
    printf("Introduce three numbers separated by a space: ");
    scanf("%f %f %f", &a, &b, &c);
    CalculateGreatestAndLowest(&a,&b,&c);
    printf("The greatest number is %.2f and the lowest is %.2f\n", a, c);
}

void CalculateGreatestAndLowest(float *A, float *B, float *C){
    float a,b,c,d;
    a=*A;
    b=*B;
    c=*C;
    if (c>b){
        d=b;
        b=c;
        c=d;
    }
    if (b>a){
        d=a;
        a=b;
        b=d;
    }
    if (c>a){
        d=c;
        c=a;
        a=d;

    }
    A=&a;
    B=&b;
    C=&c;
}