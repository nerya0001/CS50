#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./ceasar key\n");
        return 1;
    }

    // check if the key is all numbers
    string keyCheck = argv[1];

    for (int i = 0; i < strlen(keyCheck); i++)
    {
        if (!isdigit(keyCheck[i]))
        {
            printf("Usage: ./ceasar key\n");
            return 1;
        }
    }

    int k = atoi(argv[1]) % 26; // so if the key is more then 26 it will keep the remainder

    string text = get_string("text: ");

    printf("ciphertext: ");


    for (int i = 0; i < strlen(text); i++)
    {
        if (!isalpha(text[i]))
        {
            printf("%c", text[i]);
            continue;
        }
        //check if the letter is upper or lower case then change the ofSet accordingly
        int offSet;

        if (isupper(text[i]))
        {
            offSet = 65;
        }
        else
        {
            offSet = 97;
        }

        int pi = text[i] - offSet;
        int ci = (pi + k) % 26;

        printf("%c", ci + offSet);
    }

    printf("\n");

    return 0;
}
