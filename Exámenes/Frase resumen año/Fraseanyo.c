#include <stdio.h> //input /output
#include <stdbool.h> // boolean library

bool Bisiesto();

void DiaNombre();

int AnyoEmpiezaEn();

void AnyoDatos();

void frase();

int main(){
    int diasAño, primerDia, año;

    do{
        printf("Introduce un año entre 2000 y 2500: ");
        scanf("%d", &año);
        if((año<2000) || (año>2500)){
            printf("El número %d NO es un dato válido\n", año);
        }
    } while((año<2000) || (año>2500));
    
    AnyoDatos(año, &diasAño, &primerDia);
    frase(año, diasAño, primerDia);
}

bool Bisiesto(int año){
    if(año%4==0){
        return true;
    }else{
        return false;
    }
}

void DiaNombre(int diaSemana){
    switch (diaSemana){
        case 0:
            printf("Lunes\n");
            break;
        case 1:
            printf("Martes\n");
            break;
        case 2:
            printf("Miércoles\n");
            break;
        case 3:
            printf("Jueves\n");
            break;
        case 4:
            printf("Viernes\n");
            break;
        case 5:
            printf("Sábado\n");
            break;
        case 6:
            printf("Domingo\n");
            break;
    }
}

int AnyoEmpiezaEn(int año){
    int diaSemana=5; // el 2000 fue sábado, 5 en el sistema [0,6]
    for(int i=2000; i<año; i++){
        if (Bisiesto(i)){
            diaSemana+=2;
        } else{
            diaSemana+=1;
        }
    }
    if(diaSemana<7){
        return diaSemana;// cuando es menor que siete nos dice el dia
    }
    return diaSemana%7; //equivalente a tenerlo en base 7 y devolver la primera cifra
}

void AnyoDatos(int año, int * diasAño, int * primerDia){

    *primerDia=AnyoEmpiezaEn(año);
    *diasAño =(Bisiesto(año)==true) ? 366 : 365;

}

void frase(int año,int diasAño, int primerDia){
    printf("El año %d tiene %d días y empieza en ", año, diasAño);
    DiaNombre(primerDia); 

}