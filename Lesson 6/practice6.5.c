#include <stdio.h> //input output

void askDimensions(int * rows, int * columns);
void askMatrixElements(int rows, int columns, int matrix[rows][columns]);
void printMatrix(int rows, int columns, int matrix[rows][columns]);
void addMatrices(int rows, int columns, int matrixA[rows][columns], int matrixB[rows][columns], int matrixSum[rows][columns]);

int main(){

    int row, column;

    askDimensions(&row, &column);

    int matrixA[row][column];
    int matrixB[row][column];
    int matrixAplusB[row][column];

    askMatrixElements(row, column, matrixA);
    askMatrixElements(row, column, matrixB);

    printf("Your matrix A:");
    printMatrix(row, column, matrixA);
    printf("Your matrix B:");
    printMatrix(row, column, matrixB);

    printf("The result matrix (A+B):");
    addMatrices(row, column, matrixA, matrixB, matrixAplusB);
    printMatrix(row, column, matrixAplusB);

    return 0;
}

void askDimensions(int * rows, int * columns){

    do{
        printf("Introduce the number of rows of both matrices (max. 10): ");
        scanf("%d", &*rows);
    } while(*rows<0 || *rows>10);

    do{
        printf("Introduce the number of columns of both matrices (max. 10): ");
        scanf("%d", &*columns);
    } while(*columns<0 || *columns>10);

    printf("\nThe dimension of your matrices: %dx%d\n\n", *rows, *columns);
}

void askMatrixElements(int rows, int columns, int matrix[rows][columns]){

    printf("Introduce the elements of the matrix: \n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int rows, int columns, int matrix[rows][columns]){
    
    for(int i=0; i<rows; i++){
        printf("\n");
        for(int j=0; j<columns; j++){
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n");
}

void addMatrices(int rows, int columns, int matrixA[rows][columns], int matrixB[rows][columns], int matrixSum[rows][columns]){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            matrixSum[i][j]=matrixA[i][j]+matrixB[i][j];
        }
    }
}