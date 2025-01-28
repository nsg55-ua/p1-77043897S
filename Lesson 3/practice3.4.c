#include <stdio.h>
#include <math.h>

int main () {

    int a,b,c,d;
    d=0;
    printf("Write the first number (a): ");
    scanf("%d", &a);

    printf("Write the second number (b): ");
    scanf("%d", &b);

    printf("Write the first number (c): ");
    scanf("%d", &c);

    if (a>b && a>c) {
        if (b>c) {
        }
        else {
            d=b;
            b=c;
            c=d;
        }
    }
    else if (a<b && a>c) {
        d=b;
        b=a;
        a=d;
    }
    else if (a<b && a<c) {
        if (b>c) {
            d=a;
            a=c;
            c=d;
            d=a;
            a=b;
            b=d;
        }
        else if(b<c) {
            d=a;
            a=c;
            c=d;
        }
    }

    printf("%d %d %d", a, b, c);

    return 0;
}