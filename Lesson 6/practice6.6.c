#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int matrixRows = 5;
const int matrixColumns = 10;

void fillMatrix(int matrix[matrixRows][matrixColumns]);
void searchMinMaxRows(int matrix[matrixRows][matrixColumns]);
void searchMinMaxCols(int matrix[matrixRows][matrixColumns]);
void printMatrix(int matrix[matrixRows][matrixColumns]);

int main(){
    srand(time(NULL));

    int Matrix[matrixRows][matrixColumns];

    fillMatrix(Matrix);
    printf("Your randomised matrix is:\n");
    printMatrix(Matrix);
    searchMinMaxRows(Matrix);
    searchMinMaxCols(Matrix);

    return 0;
}

void fillMatrix(int matrix[matrixRows][matrixColumns]){
    
    for(int i=0; i<matrixRows; i++){
        for(int j=0; j<matrixColumns; j++){
            matrix[i][j] = 1 + rand() % 100; 
        }
    }

}

void searchMinMaxRows(int matrix[matrixRows][matrixColumns]){

    int minMaxRowsMatrix[matrixRows][2];



    for(int i=0; i<matrixRows; i++){
        int temporaryMax = matrix[i][0];
        int temporaryMin = matrix[i][0];
        for(int j=0; j<matrixColumns; j++){
            if(temporaryMax<matrix[i][j]){
                temporaryMax=matrix[i][j];
            }
            if(temporaryMin>matrix[i][j]){
                temporaryMin=matrix[i][j];
            }            
        } 
        minMaxRowsMatrix[i][0]=temporaryMin;
        minMaxRowsMatrix[i][1]=temporaryMax;
    }

    for(int i=0; i<matrixRows;i++){
        printf("ROW %d => ", i+1);
        for (int j=0; j<2; j++){
            if(j==0){
                printf("MIN: %d ", minMaxRowsMatrix[i][j]);
            }
            if(j==1){
                printf("MAX: %d\n", minMaxRowsMatrix[i][j]);
            }
        }
    }
    printf("\n");
}

void searchMinMaxCols(int matrix[matrixRows][matrixColumns]){

    int minMaxColsMatrix[matrixColumns][2];

    for(int j=0; j<matrixColumns; j++){
        int temporaryMax = matrix[0][j];
        int temporaryMin = matrix[0][j];
        for(int i=0; i<matrixRows; i++){
            if(temporaryMax<matrix[i][j]){
                temporaryMax = matrix[i][j];
            }
            if(temporaryMin>matrix[i][j]){
                temporaryMin = matrix[i][j];
            }
        }
        minMaxColsMatrix[j][0]=temporaryMin;
        minMaxColsMatrix[j][1]=temporaryMax;
    }

    for(int i=0; i<matrixColumns;i++){
        printf("COLUMN %d => ", i+1);
        for (int j=0; j<2; j++){
            if(j==0){
                printf("MIN: %d ", minMaxColsMatrix[i][j]);
            }
            if(j==1){
                printf("MAX: %d\n", minMaxColsMatrix[i][j]);
            }
        }
    }
    printf("\n");
}

void printMatrix(int matrix[matrixRows][matrixColumns]){

    for(int i=0; i<matrixRows;i++){
        printf("\n");
        for(int j=0; j<matrixColumns; j++){
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n\n");
}