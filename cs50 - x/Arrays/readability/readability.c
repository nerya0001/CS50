#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string t);
int count_words(string t);
int count_sentences(string t);
int Coleman_index(int l, int w, int s);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);

    printf("number of letters: %i\n", letters);

    int words = count_words(text);

    printf("number of words: %i\n", words);

    int sentences = count_sentences(text);

    printf("number of sentences: %i\n", sentences);

    int grade = Coleman_index(letters, words, sentences);

    if (grade >= 1 && grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        if (grade < 1)
        {
            printf("Before Grade 1\n");
        }
        if (grade >= 16)
        {
            printf("Grade 16+\n");
        }
    }
}




//number of letters function
int count_letters(string t)
{
    int letters = 0;
    int textlen = strlen(t);

    for (int i = 0; i < textlen; i++)
    {
        if (isalpha(t[i]))
        {
            letters++;
        }
    }
    return letters;
}

//number of words function
int count_words(string t)
{
    int words = 0;
    int textlen = strlen(t);

    for (int i = 0; i < textlen; i++)
    {
        if (isspace(t[i]))
        {
            words++;
        }
    }
    words++;
    return words;
}

//number of sentences function
int count_sentences(string t)
{
    int sentences = 0;
    int textlen = strlen(t);

    for (int i = 0; i < textlen; i++)
    {
        if (t[i] == '.' || t[i] == '!' || t[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

//Coleman-Liau index implementation
int Coleman_index(int l, int w, int s)
{
    float al = (float) l / (float) w * 100;                    //average of letters per 100 words
    float as = (float) s / (float) w * 100;                     //average of sentences per 100 words
    float index = 0.0588 * al - 0.296 * as - 15.8;
    int grade = round(index);
    return grade;
}