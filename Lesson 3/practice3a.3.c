#include <stdio.h>
#include <math.h>

int main() {

    int num;

    printf("Introduce a number: ");
    scanf("%d", &num);

    printf("Countdown: ");

    for (int i=num; i>-1; i--) {
        if(i == 0) {
            printf("%d \n", i);
        } else {
            printf("%d, ", i);
        }
    }

    return 0;

}