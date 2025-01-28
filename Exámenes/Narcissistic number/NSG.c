/*This program asks the user for an integer number and returns another random number between 10 and the original one.
It also prints information about if it is narcissistic or not*/

#include <stdio.h> //input/output
#include <stdlib.h> //random library
#include <time.h> //import time for random numbers
#include <stdbool.h> //use of booleans

//Declaration of functions

void askNumber();
void generateNumber();
void isNarcissistic();
void showSumary();

// main

int main(){
    srand(time(NULL)); // start seed with the actual time

    int number;
    int numberCount=0;
    int narcissisticCount=0;

    do{

        int newRandNumber, digitCount=0; 
        int sumOfDigits=0;
        bool Narcissistic=false;
        //^^^these restart everytime the program asks fora new number

        askNumber(&number);
        if(number==0){
            break; //you could do an if(number!=0) for the whole content of the dowhile, but this just makes the code cleaner
        }
        generateNumber(number, &newRandNumber);
        isNarcissistic(newRandNumber, &Narcissistic, &sumOfDigits, &digitCount);

        if(Narcissistic){
            printf("Generated number: %d\n* The number %d has %d digits\n* The number %d is narcissistic because the sum of its digits raised to the number of digits is %d\n", newRandNumber, newRandNumber, digitCount, newRandNumber, sumOfDigits);
            narcissisticCount+=1;
            numberCount+=1;
        } else{
            printf("Generated number: %d\n* The number %d has %d digits\n* The number %d is NOT narcissistic because the sum of its digits raised to the number of digits is %d\n", newRandNumber, newRandNumber, digitCount, newRandNumber, sumOfDigits);
            numberCount+=1;
        }
    
    }while(number!=0);

    showSumary(numberCount, narcissisticCount);

    return 0;
}

// functions

void askNumber(int * number){
        do{
        printf("Enter a number: ");
        scanf("%d", &*number);
        if(*number<0){
            printf("Incorrect number\n");
        }
    } while(*number<0);
}

void generateNumber(int number, int * newNumber){

    if(number<=10){
        *newNumber=number;
    } else{
        *newNumber= 10 + rand() % (number-10)+1; // generates a number between 10 and the number, not inclusive
    }
}

void isNarcissistic(int number, bool * NarcissistCheck, int * sum, int *digitCount){

    int temp;

    for (int i=number; i>=1; i/=10){
        *digitCount+=1;
    }
    for (int i=number; i>=1; i/=10){
        temp=1; // restart for each digit

        /*power function by hand*/
        for(int j=0; j<*digitCount; j++ ){ 
            temp=temp*(i%10);
        }
        *sum+=temp;
        /*end of power function*/
    }

    *NarcissistCheck=(*sum==number) ? true : false; //ternary operator to save lines
}

void showSumary(int numberCount, int NarcciCount){
    printf("****************************\n\n");
    printf("Total numbers entered: %d\nTotal narcissistic numbers: %d\n", numberCount, NarcciCount);
   printf("*****************************\n\n");
}