#include <stdio.h>
#include <stdbool.h>

void askString(char phrase[]);
void printStringInfo(char phrase[]);

int main(){
    char mander[200];

    askString(mander);
    printStringInfo(mander);
}

void askString(char phrase[]){

    printf("Introduce a phrase of maximum 200 characters: ");
    scanf(" %[^\n]s", phrase);
}

void printStringInfo(char phrase[]){
    bool final = false;
    int vocales, consonantes, palabras, i;
    vocales=0;
    consonantes=0;
    palabras=1;
    i=0;

    while(i<200 && !final){
        switch (phrase[i]){
            case 'a': vocales+=1; break;
            case 'o': vocales+=1; break;
            case 'i': vocales+=1; break;
            case 'u': vocales+=1; break;
            case 'e': vocales+=1; break;
            case 'A': vocales+=1; break;
            case 'O': vocales+=1; break;
            case 'I': vocales+=1; break;
            case 'U': vocales+=1; break;
            case 'E': vocales+=1; break;
            case ' ': palabras+=1; break;
            case '\0': final = true; break;
            default: consonantes+=1; break;
        };
        i++;
    }
    printf("*Number of words: %d\n*Number of vowels: %d\n*Number of consonants: %d\n", palabras, vocales, consonantes);
}