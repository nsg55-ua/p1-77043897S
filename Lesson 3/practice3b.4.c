#include <stdio.h>
#include <math.h>

int main () {

    float number, sum;
    int count;

    do{
        printf("Introduce a real number: ");
        scanf("%f", &number);
        
        if (number != 0){
            sum += number;
            count++;
        }

    } while (number != 0);

    printf("# of numbers introduced: %d\n", count);
    printf("The arithmetic mean of them is %.2f\n", sum/count);    
    
    return 0;
}