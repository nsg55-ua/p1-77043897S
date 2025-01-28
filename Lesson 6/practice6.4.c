#include <stdio.h> //input output

void fillArrayANDgetLength(int array[], int * length);
void bubbleSort(int array[], int length);
void printArray(int array[], int length);

int main(){

    int numberList[20];
    int listLength=0;

    printf("Introduce the numbers for the list(max. 20):\n");
    fillArrayANDgetLength(numberList, &listLength);
    bubbleSort(numberList, listLength);
    printArray(numberList, listLength);

    return 0;
}

void fillArrayANDgetLength(int array[], int * length){
    int temp;

    for(int i=0; i<20;i++){
        scanf("%d", &temp);
        if(temp==0){ //if user enters 0 it stops asking
            i=20;
            continue;
        }
        array[i]=temp;
        *length+=1;
    }
}

void bubbleSort(int array[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Interchange array[j] and array[j+1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void printArray(int array[], int length){
    
    for(int i=0; i<length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}