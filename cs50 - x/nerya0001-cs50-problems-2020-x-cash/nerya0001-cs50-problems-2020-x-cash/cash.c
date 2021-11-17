#include <cs50.h>
#include <stdio.h>
#include <math.h> 

int main(void)
{
    float change;
    do
    {
        change = get_float("change owed: ");
    }
    while (change <= 0.00);
    
    int cents = round(change * 100);
    int counter = 0;
    
    while (cents >= 25)
    {
        counter++;
        cents = cents - 25;
    }
    while (cents >= 10)
    {
        counter++;
        cents = cents - 10;
    }
    while (cents >= 5)
    {
        counter++;
        cents = cents - 5;
    }
    while (cents >= 1)
    {
        counter++;
        cents = cents - 1;
    }
    
    printf("%i\n", counter);
    
}