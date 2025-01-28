#include <stdio.h>
#include <math.h>

int main () {

    float time;

    printf("what time is it? ");
    scanf("%f", &time);

    if ((time>=7) && (time<=14)) {
        printf("Good morning!\n");
    }
    else if ((time>=15) && (time<=20)) {
        printf("Good afternoon!\n");
    }
    else if ((time >= 20 && time <= 23) || (time >= 0 && time <= 6)) {
        printf("GOod evening!\n");
    }

    return 0;
}