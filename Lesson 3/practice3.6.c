#include <stdio.h>
#include <math.h>

int main () {

    float weight, height, BMI;

    printf("Enter your wieght (kg):");
    scanf("%f", &weight);

    printf("Enter your height (m):");
    scanf("%f", &height);

    BMI = weight / (height*height);

    if (BMI < 18.0) {
        printf("Yuur BMI says you are below normal %.2f \n", BMI);
    } else if ((BMI >= 18.1) && (BMI <= 24.9)) {
        printf("Your BMI says you are normal %.2f \n", BMI);
    } else if ((BMI >= 25.0) && (BMI <= 29.9)) {
        printf("Your BMI says you are overweight %.2f \n", BMI);
    } else {
        printf("Your BMI says you are obeese %.2f \n", BMI);
    }

    return 0;
}