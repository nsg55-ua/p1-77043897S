#include <stdio.h>
#include<math.h>

const float pi = 3.141596;

float calculateCircunference(float radius);
float calculateArea(float radius);

int main() {

    float radius;

    printf("Introduce the radius of your circunference: ");
    scanf("%f", &radius);

    printf("The perimeter of your circle of radius %.2f is %.2f,and the area of it is %.2f\n", radius, calculateCircunference(radius), calculateArea(radius));

    return 0;
}


float calculateCircunference(float radius){
    return 2*pi*radius;
}

float calculateArea(float radius){
    return pi*radius*radius;
}