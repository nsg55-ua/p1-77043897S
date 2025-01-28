#include <stdio.h>
#include <math.h>

int main() {

    int figOption, size;
    

    do {
        printf("MENU \n------------ \n1 - Figure 1 \n2 - Figure 2 \n3 - Figure 3 \n4 - Figure 4 \n5 - Figure 5 \n0 - Exit \n \n Choose an option: ");
        scanf("%d", &figOption);
        if(figOption == 0) {
            return 0;
        }
        printf("Introduce the figure size (4-15): ");
        scanf("%d", &size);
    } while (((figOption < 1) || (figOption > 5)) || ((size < 4) || (size > 15)));

    switch (figOption) {
        case 1: 
            for (int i=0; i<size +1; i++) {
                for (int j=0; j< i; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;
        case 2: 
            for (int i = size*2 -1, h=1; i>-1; i-=2, h++){
                for(int j=0; j<i; j++){
                    printf("*");
                }
                printf("\n");
                for ( int k=0; k<h; k++){
                    printf(" ");
                }
            }
            break;
        case 3:
            for (int i=0; i<size; i++){
                for(int j=0; j<i;j++){
                    printf("*");
                }
                for(int k=(2*size -2)-2*i; k>-1; k--){
                    printf(" ");
                }
                for(int j=0; j<i;j++){
                    printf("*"); 
                }
                printf("\n");
            }
            for(int i=0; i<size*2 -1; i++){
                printf("*");
            }
            printf("\n");
            break;
        case 4: 
            for (int i=4, j=0; j<5; j++, i--) {
                for(int k=0; k<i+1; k++){
                    printf(" ");
                }
                for( int h=0; h<size+1; h++){
                    printf("*");
                }
                printf("\n");
            }
            for( int f=0; f< size+5; f++){
                printf("*");
            }
            printf("\n");
            for (int q=4, a=0; a<5; a++, q--) {
                for(int k=0; k<a+1; k++){
                    printf(" ");
                }
                for(int h=0; h<size+1; h++){
                    printf("*");
                }
                    printf("\n");
            }
            printf("\n");
            break;
        case 5:
            for (int i=0; i< size; i++){
                for(int j=0; j<(((2*size-1) - (2*i-1))/2)+1; j++){
                    printf(" ");
                }
                for(int h=0; h<2*i+1; h++){
                    printf("*");
                }
                for(int j=0; j<(((2*size-1) - (2*i-1))/2)+1; j++){
                    printf(" ");
                }
                printf("\n");
            }
            for (int i=size-2; i>-1; i--){
                for(int j=0; j<(((2*size-1) - (2*i-1))/2)+1; j++){
                    printf(" ");
                }
                for(int h=0; h<2*i+1; h++){
                    printf("*");
                }
                for(int j=0; j<(((2*size-1) - (2*i-1))/2)+1; j++){
                    printf(" ");
                }
                printf("\n");
            }
    }

    return 0;
}