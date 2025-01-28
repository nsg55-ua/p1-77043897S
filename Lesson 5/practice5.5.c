#include <stdio.h> // input/output
#include <stdbool.h> // implement booleans

void isBinary();

int main(){
    int number;
    bool check;
        printf("Introduce a number: ");
        scanf("%d", &number);

        isBinary(number, &check);

        if (check){
            printf("The number is in binary\n");
        } else {
            printf("The number is not in binary\n");
        }

    return 0;
}

void isBinary(int number, bool * check){
    if (number>=10){
        isBinary(number/10, *&check);
    }    
    if (((number%10 == 1) || (number%10 == 0))){
        *check = true;
    } else{
        *check = false;
    }
}