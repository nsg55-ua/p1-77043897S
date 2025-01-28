#include <stdio.h> // input/output

int powerf();

int main(){
    int base, power;

    printf("Introduce a number and its power: ");
    scanf("%d %d", &base, &power);

    powerf(base, power);

    printf("The result of %d^%d is: %d\n", base, power, powerf(base, power));
}

int powerf(int base, int power){
    if(power>1){
       return base*powerf(base, power-1);
    }
    return base;
}