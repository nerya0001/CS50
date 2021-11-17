// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 65536;

int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int x = strlen(word);
    char copy[LENGTH + 1];

    for (int i = 0; i < x; i++)
    {
        copy[i] = tolower(word[i]);
    }

    copy[x] = '\0';
    int hashed = hash(copy);

    for (node *n = table[hashed]; n != NULL; n = n->next)
    {
        if (strcasecmp(n->word, copy) == 0)
        {
            return true;
        }
    }


    return false;
}

// Hashes word to a number
unsigned int hash(const char *word) //Source : https://cp-algorithms.com/string/string-hashing.html
{
    unsigned int hash_value = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash_value = (hash_value << 2) ^ word[i];
    }

    return hash_value % N; //N is size of hashtable
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *f = fopen(dictionary, "r"); //open dictionary for reading
    if (f == NULL)
    {
        printf("could not open dictionary\n");
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(f, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, word);

        int x = hash(word);
        n->next = table[x];

        table[x] = n;

        word_count++;
    }

    fclose(f);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *n = table[i];
        while (n != NULL)
        {
            node *tmp = n;
            n = n->next;
            free(tmp);
        }
    }

    return true;
}
