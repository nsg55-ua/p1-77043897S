#include <stdio.h> // use getchar() funct to stop the game
#include <stdlib.h>
#include <time.h> // Produce random numbers for the cards

void startGame();
void continueGame();
int getCard();
void showCards();
void updateScore();
void OneRound();
void EndGame();

const char letterS='s';//used to compare user input when starting game
const char letterC='c';//used to compare user input between rounds

int main(){

    srand(time(NULL));//Start a seed with a random time
    float BankerScore=0;
    float PlayerScore=0;

    startGame();
    while((PlayerScore<=7.5) && (BankerScore<=7.5)){
        OneRound(&PlayerScore, &BankerScore);
    }
    EndGame(&PlayerScore, &BankerScore);
}


void startGame(){
    char StartCharacter;
    do{
        printf("Press 's' to start a new game...\n");
        scanf(" %c", &StartCharacter);
        fflush(stdin);
    }while(StartCharacter!=letterS);
    printf("\n");
}

void continueGame(){
    char ContinueCharacter;
    do{
        printf("Press 'c' for more cards...\n");
        fflush(stdin);
        scanf(" %c", &ContinueCharacter);
    }while(ContinueCharacter!=letterC);
    printf("\n");
}

int getCard(){
    int card;

    card= 1 + rand() % 10;

    return card;
}

void showCards(int card){
    switch(card){
        case 1: 
            printf("(%d) ACE", card);
            break;
        case 2:
            printf("%d", card);
            break;
        case 3:
            printf("%d", card);
            break;
        case 4:
            printf("%d", card);
            break;
        case 5:
            printf("%d", card);
            break;
        case 6:
            printf("%d", card);
            break;
        case 7: 
            printf("%d", card);
            break;
        case 8:
            printf("(%d) JACK", card);
            break;
        case 9:
            printf("(%d) KNIGHT", card);
            break;
        case 10:
            printf("(%d) KING", card);
            break;
    }

}

void updateScore( int lastCard, float *currentScore){
    if((lastCard>=2) && (lastCard<=7)){
        *currentScore+=lastCard;
    }else{
        *currentScore+=0.5;
    }
}

void OneRound(float *PlayerScore, float *BankerScore){

    int currentBankerCard, currentPlayerCard;
    printf("=======================================\n");

    /*Bankers turn*/
        currentBankerCard=getCard();//random card in each round
        updateScore(currentBankerCard, &*BankerScore); //changes score values in main()

        /*layout*/
        printf("Bankers card: ");
        showCards(currentBankerCard);
        printf(" => Score %.1f\n", *BankerScore);

    /*Players turn*/
        currentPlayerCard=getCard();
        updateScore(currentPlayerCard, &*PlayerScore);


        /*layout*/
        printf("Players card: ");
        showCards(currentPlayerCard);
        printf(" => Score %.1f\n\n", *PlayerScore);

    printf("Scores:\n- Banker's score: %.1f\n- Player's score: %.1f\n", *BankerScore, *PlayerScore);
    printf("=======================================\n");
    if((*PlayerScore<=7.5) && (*BankerScore<=7.5)){ //let player continue getting cards only if both players are below limit
        continueGame();
    }
}
/*OneRound() produces a single round of the game. Changes score variables in main(). Also lets user continue 
getting cards by continueGame(). Rest is screen layout and creation of new cards (not saved globaly)*/
void EndGame(float *PlayerScore, float *BankerScore){
    if(*PlayerScore<*BankerScore){
        printf("\nOops, the banker went too far! You are the winner!\n");
    } else if(*PlayerScore>*BankerScore){
        printf("\nOops, you went too far! The Banker is the winner!\n");
    }else{
        printf("\nWow, ya'll went too far! You two are gonna need to play rock, paper, scissors to see who's the winner!\n");
    }
}