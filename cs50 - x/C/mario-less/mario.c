#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("hight: ");
    }
    while (n < 1 || n > 8);

    for (int j = 1; j <= n; j++)
    {
        for (int d = n; d > j; d--)
        {
            printf(" ");
        }
        for (int f = 0; f < j; f++)
        {
            printf("#");
        }
        printf("\n");
    }
}