#include <stdio.h> // user input/output
#include <stdlib.h>
#include <time.h> // get random cards

/*Module declaration*/

void startGame();
void askForPlayers();
int getCard();

/*Constants*/

const char letterS='s';//used to compare user input when starting game


/*main funct*/

int main(){

    int numberOfPlayers;


    srand(time(NULL));//Start a seed with a random time

    startGame();
    askForPlayers(&numberOfPlayers);



    return 0;
}

/*Modules*/

void startGame(){
    char StartCharacter;
    do{
        printf("Press 's' to start a new game...\n");
        scanf(" %c", &StartCharacter);
        fflush(stdin);
    }while(StartCharacter!=letterS);
    printf("\n");
}

void askForPlayers(int * numberOfPlayers){


    do{
        printf("Introduce the number of players for this game (max. 6)\n");
        scanf("%d", &*numberOfPlayers);
        fflush(stdin);
    } while((*numberOfPlayers<0) || (*numberOfPlayers>6));
    printf("\n");
    extern char players[*numberOfPlayers][8];

    printf("Introduce the name for each player:\n");
    for (int i=0; i<*numberOfPlayers+1; i++){
        printf("Player %d:\n", i);
        for (int j=0; j<9; j++){
            scanf("%c", &players[i][j]);
            fflush(stdin);
        }
    }
    printf("%c", players)

}

int getCard(){
    int card;

    card= 1 + rand() % 10;

    return card;
}