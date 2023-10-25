#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    int level = 0;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    while (height > level)
    {
        for (int n = height - 1; n > level; n--)
        {
            printf(" ");
        }
        for (int n = 0; n < level + 1; n++)
        {
            printf("#");
        }
        printf("  ");
        for (int n = 0; n < level + 1; n++)
        {
            printf("#");
        }
        printf("\n");
        level++;
    }
}
