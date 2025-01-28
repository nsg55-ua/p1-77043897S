#include <stdio.h>
#include <math.h>

int main () {

    int num;

    printf("Introduce an integer number: ");
    scanf("%d", &num);

    for (int i=0; i<11; i++) {
        printf("%d x %d = %d \n", num, i, i*num);
    }

    return 0;
}