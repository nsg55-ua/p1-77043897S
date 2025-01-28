#include <stdio.h> //input-output
#include <stdbool.h> // boolean values

const int MAX_LENGTH=20;

bool isPalindrome(char word[MAX_LENGTH]);

int main(){

    char word[20];

    printf("Introduce a word (max. 20 characters): ");
    scanf("%s", word);

    if(isPalindrome(word)){
        printf("%s is palindrome!\n", word);
    } else{
        printf("%s is NOT palindrome!\n", word);
    }

    return 0;
}

bool isPalindrome(char word[MAX_LENGTH]){
    bool palindrome=true; // suppose the given word is a palindrome
    int character_count=0;

    for (int character=0; word[character]!='\0'; character++){ //count the length of the word
        character_count++;
    }

    for(int i=0, j=character_count-1; i<character_count && palindrome; i++, j--){ // for each iteration, go from the end and the begining cheking them at once. It should hold that for the end and the first, second and last-1... are all equal
        if(word[i]!=word[j]){
            palindrome=false;
        }
    }

    return palindrome;
}