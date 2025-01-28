#include <stdio.h>
#include <math.h>

float unitConverterKm (float speed);

int main () {

    float number;

    printf("Introduce the speed in km/h: ");
    scanf("%f", &number);

    printf("Your speed in m/s: %.2f\n", unitConverterKm(number));

    return 0;
}

float unitConverterKm(float speed){
    return speed*1000/3600;
}