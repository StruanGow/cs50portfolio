#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;
    int x = 0;
    do
    {
        card = get_long("Number: ");
    }
    while (card < 1);
    long fixed = card;
    int x2 = 0;
    int y = 0;
    int store = 0;
    for (int i = 0; i < 16; i++)
    {
        y = card % 10;
        card /= 10;
        x = card % 10;
        card /= 10;
        x2 = x * 2;
        store += x2 % 10 + (x2 / 10) % 10 + y;
    }
    if (store % 10 == 0)
    {
        if (fixed / 1000000000000 == 4 | fixed / 1000000000000000 == 4)
        {
            printf("VISA\n");
        }
        else if (fixed / 10000000000000 == 34 | fixed / 10000000000000 == 37)
        {
            printf("AMEX\n");
        }
        else if (fixed / 100000000000000 == 51 | fixed / 100000000000000 == 52 | fixed / 100000000000000 == 53 | fixed / 100000000000000 == 54 | fixed / 100000000000000 == 55)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
