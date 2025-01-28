#include <math.h>
#include <stdio.h>

int main() {

    int number;

    do {
        printf("Introduce an even number: ");
        scanf("%i", &number);
    } while(number % 2 !=0);

    for(int j=0; j<number +1; j+=2){
        for (int i = j-1; i>0; i-=2){
            printf("%d", i);
        }
        printf("\n");
    }

    return 0;
}