#include<stdio.h>



void main()
{
    int inpt, out = 0;
    int i , j, k;

    scanf("%d", &inpt);

    // Check out 10's currency
    out += inpt / 10;
    inpt = inpt % 10;

    // Checkout 5's currency
    out += inpt / 5;
    inpt = inpt % 5;

    // Checkout's 1's currency

    out += inpt;

    printf("%d",out);

}
