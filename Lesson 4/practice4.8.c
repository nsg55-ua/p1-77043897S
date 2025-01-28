#include <stdio.h>
#include <math.h>

void calculateRootsSecondDegree(float A, float B, float C);

int main() {
    float coeficientA, coeficientB, coeficientC;

    printf("Introduce the coeficients of your second degree polynomial, separated by spaces: ");
    scanf("%f %f %f", &coeficientA, &coeficientB, &coeficientC);

    calculateRootsSecondDegree(coeficientA, coeficientB, coeficientC);

    return 0;

}

void calculateRootsSecondDegree(float A, float B, float C){
    float root1, root2;

    root1=(-B+sqrt(B*B-4*A*C))/(2*A);
    root2=(-B-sqrt(B*B-4*A*C))/(2*A);

    printf("The roots of your polynomial are %.2f and %.2f\n", root1, root2);
}