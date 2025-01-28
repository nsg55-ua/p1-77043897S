#include <stdio.h>
#include <math.h>
#include <stdbool.h>

float calculateArea(float side);
float calculatePerimeter(float side);

int main() {
    float side;

    printf("Introduce the side of your square: ");
    scanf("%f", &side);
    printf("The Area of your square is: %.2f\nThe Perimeter of your square is: %.2f\n", calculateArea(side), calculatePerimeter(side));
}

float calculateArea(float side){
    float Area=side*side;
    return Area; 
}

float calculatePerimeter(float side){
    float Perimeter=4*side;
    return Perimeter; 
}