#include <stdio.h>
#include <math.h>

int main() {

    int originalNumber, number, even, total = 0;
    float remainder;
    printf("Introduce an integer number: ");
    scanf("%d", &originalNumber);
    number = originalNumber;

    while(number > 1) {
        remainder = number % 10;
        
        if ((int) remainder % 2 == 0){
            even++;
        }
        number /= 10;
        total++;
    }
    printf("Your number: %d\n", originalNumber);
    printf("Digits of your number: %d\n", total);
    printf("# of even digits: %d\n", even);
    printf("# of odd digits: %d\n", total - even);

    return 0;
}