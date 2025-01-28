#include<stdio.h>

int main() {
    int age;

    printf("Type your age: ");
    scanf("%d", &age);
    printf("You have lived %d seconds, aproximately\n", age*365*24*60*60);

    return 0;
}