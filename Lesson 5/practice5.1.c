#include <stdio.h> // input/output

void printRightTriangle();

int main() {
    int height;
    printf("Introduce the height of your triangle: ");
    scanf("%d", &height);

    printRightTriangle(height);

    return 0;
}


void printRightTriangle(int height){
    if (height>0){
        printRightTriangle(height -1);
    }
    for(int i=height; i>0; i--){
        printf("*");
    }
    printf("\n");

}