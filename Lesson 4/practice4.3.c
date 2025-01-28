#include <stdio.h>
#include <math.h>


float LitersPerTravel (float fuelConsumptionL100km, float Distancekm);

int main () {

    float fuelConsumptionL100km, Distancekm;

    printf("Introduce the fuel consumption in L/100km: ");
    scanf("%f", &fuelConsumptionL100km);

    printf("Introduce the distance you want to travel: ");
    scanf("%f", &Distancekm);

    printf("The number of liters required to travel %.2fkm is: %.2f\n", Distancekm,  LitersPerTravel(fuelConsumptionL100km, Distancekm));

    return 0;
}

float LitersPerTravel( float fuelConsumptionL100km, float Distancekm){
    return (Distancekm/100/*[km]*/)*fuelConsumptionL100km;// (km/km)*L=L
}