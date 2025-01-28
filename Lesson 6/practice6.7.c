#include <stdio.h> // input - output
#include <stdlib.h> // import random library
#include <time.h> // current time for random number generation

int orderDimension();
void fillMatrix(int dimensions, int matrix[dimensions][dimensions]);
void insertAndRemoveLast(int dimensions, int matrix[dimensions][dimensions], int element, int positionI, int positionJ);
void applyReduction(int dimensions, int matrix[dimensions][dimensions]);
void printMatrix(int dimension, int matrix[dimension][dimension]);

int main(){
    srand(time(NULL)); // initialize random seed depending on current time

    int matrixDimension;

    matrixDimension = orderDimension(); //first get dimension from user
    
    int MatrixCNN[matrixDimension][matrixDimension]; //then create matrix with desired dimensions

    fillMatrix(matrixDimension, MatrixCNN);

    printMatrix(matrixDimension, MatrixCNN);

    applyReduction(matrixDimension, MatrixCNN);

    return 0;
}

int orderDimension(){

    int MatrixDim;
    do{
        printf("Introduce the order of your sqaure matrix (must be a power of 2):");
        scanf("%d", &MatrixDim);
    }while((MatrixDim<0) || (MatrixDim>32) || !((MatrixDim & (MatrixDim - 1)) == 0)); // 1000 & 0111 = 0 check bit by bit if both are one. 2^n is always 100...0

    return MatrixDim;
}

void fillMatrix(int dimensions, int matrix[dimensions][dimensions]){
    
    for(int i=0; i<dimensions; i++){
        for(int j=0; j<dimensions; j++){
            matrix[i][j] = 1 + rand() % 20;
        }
    }

}

void applyReduction(int dimensions, int matrix[dimensions][dimensions]){

    int auxiliaryReducedCNN[dimensions/4][dimensions/4];
    int reducedCNN[dimensions/2][dimensions/2];


    //initialize both matrices

    for(int i=0; i<(dimensions/4); i++){
        for(int j=0; j<(dimensions/4); j++){
            auxiliaryReducedCNN[i][j] = 0;
        }
    }


    for(int i=0; i<(dimensions/2); i++){
        for(int j=0; j<(dimensions/2); j++){
            reducedCNN[i][j] = -1;
        }
    }

    //first quadrant

    for(int i=0; i<(dimensions/2)-1; i++){
        for(int j=0; j<(dimensions/2)-1; j++){
            //primer cuadrante
            for(int I=0; I<(dimensions/4-1); I++){
                printf("%d\n", j);
                for(int J=0; J<(dimensions/4-1); J++){
                    if(matrix[i][j]>auxiliaryReducedCNN[I][J]){
                        insertAndRemoveLast(dimensions/4, auxiliaryReducedCNN, matrix[i][j], I, J);
                        goto exit1;
                    }
                }
            }
            exit1:
        }
    }
    printMatrix(dimensions/4, auxiliaryReducedCNN);


    for(int i=0, I=0; ((i<dimensions/4) - 1) && ((I<dimensions/4) - 1); i++, I++){
        for(int j = 0, J = 0; ((j<dimensions/4) - 1) && ((J<dimensions/4) - 1); j++, J++){
            reducedCNN[i][j]=auxiliaryReducedCNN[I][J];
        }
    }


    for(int i=0; i<(dimensions/4); i++){
        for(int j=0; j<(dimensions/4); j++){
            auxiliaryReducedCNN[i][j] = 0;
        }
    }


    //second quadrant

    for(int i=0; i<(dimensions/2)-1; i++){
        for(int j=0; j>(dimensions/2)-1; j++){
            //segundo cuadrante
            for(int I=0; I<(dimensions/4-1); I++){
                for(int J=0; J<(dimensions/4-1); J++){
                    if(matrix[i][j]>auxiliaryReducedCNN[I][J]){
                        insertAndRemoveLast(dimensions/4, auxiliaryReducedCNN, matrix[i][j], I, J);
                        goto exit2;
                    }
                }
            }
            exit2:
        }
    }
    for(int i=0, I=0; ((i<dimensions/4) - 1) && ((I<dimensions/4) - 1); i++, I++){
        for(int j = 0, J = 0; ((j>dimensions/4) - 1) && ((J<dimensions/4) - 1); j++, J++){
            reducedCNN[i][j]=auxiliaryReducedCNN[I][J];
        }
    }


    for(int i=0; i<(dimensions/4); i++){
        for(int j=0; j<(dimensions/4); j++){
            auxiliaryReducedCNN[i][j] = 0;
        }
    }

    //third quadrant

    for(int i=0; i>(dimensions/2)-1; i++){
        for(int j=0; j<(dimensions/2)-1; j++){
            //tercer cuadrante
            for(int I=0; I<(dimensions/4-1); I++){
                for(int J=0; J<(dimensions/4-1); J++){
                    if(matrix[i][j]>auxiliaryReducedCNN[I][J]){
                        insertAndRemoveLast(dimensions/4, auxiliaryReducedCNN, matrix[i][j], I, J);
                        goto exit3;
                    }
                }
            }
            exit3:
        }
    }
    for(int i=0, I=0; ((i>dimensions/4) - 1) && ((I<dimensions/4) - 1); i++, I++){
        for(int j = 0, J = 0; ((j<dimensions/4) - 1) && ((J<dimensions/4) - 1); j++, J++){
            reducedCNN[i][j]=auxiliaryReducedCNN[I][J];
        }
    }


    for(int i=0; i<(dimensions/4); i++){
        for(int j=0; j<(dimensions/4); j++){
            auxiliaryReducedCNN[i][j] = 0;
        }
    }

    //fourth quadrant

    for(int i=0; i>(dimensions/2)-1; i++){
        for(int j=0; j<(dimensions/2)-1; j++){
            //cuarto cuadrante
            for(int I=0; I<(dimensions/4-1); I++){
                for(int J=0; J<(dimensions/4-1); J++){
                    if(matrix[i][j]>auxiliaryReducedCNN[I][J]){
                        insertAndRemoveLast(dimensions/4, auxiliaryReducedCNN, matrix[i][j], I, J);
                        goto exit4;
                    }
                }
            }
            exit4:
        }
    }
    for(int i=0, I=0; ((i>dimensions/4) - 1) && ((I<dimensions/4) - 1); i++, I++){
        for(int j = 0, J = 0; ((j>dimensions/4) - 1) && ((J<dimensions/4) - 1); j++, J++){
            reducedCNN[i][j]=auxiliaryReducedCNN[I][J];
        }
    }

    printMatrix(dimensions/2, reducedCNN);
}

void insertAndRemoveLast(int dimensions, int matrix[dimensions][dimensions], int element, int positionI, int positionJ){

    int temp;

    for(int i=(dimensions-1); i>(positionI-1); i--){

        if(i!=(dimensions-1)){
            temp=matrix[i][dimensions-1];
        }
        for(int j=(dimensions-1); (i!=positionI) && (j>0); j--){
            matrix[i][j]= matrix[i][j-1];
        }
        for(int j=(dimensions-1); (i==positionI) && (j>positionJ-1); j--){
            matrix[i][j]= matrix[i][j-1];
        }
        if(i!=(dimensions-1)){
            matrix[i+1][0]= temp;
        }
    }

    matrix[positionI][positionJ] = element;
}

void printMatrix(int dimension, int matrix[dimension][dimension]){

    for(int i=0; i<(dimension); i++){
        printf("\n");
        for(int j=0; j<(dimension); j++){
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n\n");
}