#include <stdio.h> // input - output
#include <stdlib.h> 
#include <time.h> // random library and current time

void fillArray(int list[]);
void printArray(int numberList[]);
void minANDmax (int numberList[]);

int main(){
    srand(time(NULL));

    int tenRandNum[10];

    fillArray(tenRandNum);
    printArray(tenRandNum);
    minANDmax(tenRandNum); //prints the max and min of the numberList

    return 0;
}

void fillArray(int numberList[]){

    for (int i=0; i<10;i++){
        numberList[i]= 1 + rand() % 50; //rand between 1 and 50 both included
    }
}

void printArray(int numberList[]){

    for(int i=0; i<10; i++){
        printf("%d\n", numberList[i]);
    }
}

void minANDmax(int numberList[]){
    int maxNumber=numberList[0];
    int minNumber=numberList[0];


    for(int i=1; i<10;i++){
        if(numberList[i]>=maxNumber){
            maxNumber=numberList[i];
        }
        if(numberList[i]<=minNumber){
            minNumber=numberList[i];
        }
    }

    printf("The greatest number in your list is %d\nThe smallest number in your list is %d\n", maxNumber, minNumber);
}