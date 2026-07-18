#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("Height: ");
    while (height < 1)
    {
        height = get_int("Height: ");
    }

    for (int row = 1; row <= height; row++)
    {
        for (int space = 1; space <= height - row; space++)
        {
            printf(" ");
        }
        for (int i = 1; i <= row; i++)
        {
            printf("#");
        }
        printf("  ");
        for (int r = 1; r <= row; r++)
        {
            printf("#");
        }
        printf("\n");
    }
}
