#include <math.h>
#include <stdio.h>

int main () {

    int number;


    do{
        printf("Introduce a number between 50 and 100: ");
        scanf("%d", &number);
    } while(number < 50 || number > 100);

    int i=0;
    printf("The perfect squares smaller (or equal) than your number are:\n");
    while (i*i <= number){
        printf("%d (%d x %d)\n", i*i, i, i);
        i++;
    }
    
    return 0;
}