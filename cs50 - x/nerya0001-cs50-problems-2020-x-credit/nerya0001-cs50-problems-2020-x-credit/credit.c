#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long card;

    //reciving valid input

    do
    {

        card = get_long("number: ");
    }
    while (card <= 0);

    long num = card;
    int digits = 0;
    bool stoper = false;

    //number of digits checkpoint

    while (num > 0)
    {
        num = num / 10;
        digits++;
    }

    if (digits < 12 && digits > 17 && digits != 14)
    {
        printf("INVALID\n");
        stoper = true;
    }

    if (stoper)
    {
        return (0);
    }

    num = card;
    int sum = 0;

    //even digits

    while (num > 0)
    {
        int last = num % 10;
        sum = sum + last;
        num = num / 100;
    }

    //odd digits

    num = card / 10;
    while (num > 0)
    {
        int last = num % 10;
        int multi = last * 2;
        sum = sum + (multi % 10) + (multi / 10);
        num = num / 100;
    }

    int companyFirstTwo = 0;
    int companyFirst = 0;
    num = card;

    while (num > 100)
    {
        num = num / 10;
    }

    companyFirstTwo = num;
    companyFirst = companyFirstTwo / 10;

    // last checkpoint - if it is valid and which company the card is from

    if (sum % 10 == 0)
    {
        if (companyFirstTwo > 50 && companyFirstTwo < 56 && digits == 16)
        {
            printf("MASTERCARD\n");
        }
        else if ((companyFirstTwo == 34 || companyFirstTwo == 37) && (digits == 15))
        {
            printf("AMEX\n");
        }
        else if ((companyFirst == 4) && (digits == 13 || digits == 16))
        {
            printf("VISA\n");
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