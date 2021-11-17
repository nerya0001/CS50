#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string formatkey(string key);
bool valid(string key);
string encrypt(string text, string key);

int main(int argc, string argv[])
{
    //check if there are mor then 1 cammand line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // check if the key is 26 letters
    string key = argv[1];
    int count = 0;

    for (int i = 0; i < strlen(key); count++, i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    if (count != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    key = formatkey(key);

    //check for duplicate letters
    if (!valid(key))
    {
        printf("Key must contain 26 different letters\n");
        return 1;
    }

    string text = get_string("plaintext: ");

    text = encrypt(text, key);
    printf("ciphertext: %s", text);

    printf("\n");

    return 0;


}




//change all the key to lower cese
string formatkey(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!islower(key[i]))
        {
            key[i] = tolower(key[i]);
        }
    }
    return key;
}

//key validity check
bool valid(string key)
{
    //check for duplicate letters
    int valid = 0;
    for (int k = 0, n = strlen(key); k < n; k++, valid = 0)
    {

        for (int j = 0, l = strlen(key); j < n; j++)
        {
            if (key[k] == key[j])
            {
                valid++;
            }
        }
        if (valid != 1)
        {
            return false;
        }
    }
    return true;
}


//encrypt the text using the key
string encrypt(string text, string key)
{
    string alphachanges = key;
    for (int e = 97; e <= 122; e++)
    {
        alphachanges[e - 97] = alphachanges[e - 97] - e;   //idea i've got from a video about keeping trak of the changes of a string;
    }
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (!isalpha(text[i]))
        {
            text[i] = text[i];
            continue;
        }

        if (!isupper(text[i]))
        {
            text[i] = text[i] + alphachanges[text[i] - 97] ;
            continue;
        }

        if (isupper(text[i]))
        {
            text[i] = text[i] + alphachanges[text[i] - 65] ;
            continue;
        }

    }

    return text;
}