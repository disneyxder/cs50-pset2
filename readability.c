#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{

    string input = get_string("Text: ");

    // counting letters, words & sentences
    float letters = 0, words = 0, sentences = 0;
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isalpha(input[i]))
        {
            letters++;
        }
        if ((isalpha(input[i]) && isspace(input[i + 1])) || (isalpha(input[i]) && ispunct(input[i + 1])) || (isalpha(input[i]) &&
                input[i + 1] == '\0'))
        {
            words++;
        }
        if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            sentences++;
        }
        if (isalpha(input[i]) && ispunct(input[i + 1]) && isalpha(input[i + 2]))
        {
            words--;
        }
    }

    // average number of letters || sentences per 100 words
    float L = letters / words * 100;
    float S = sentences / words * 100;

    // print grade
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int index1 = round(index);
    if (index1 >= 1 && index1 <= 16)
    {
        printf("Grade %i\n", index1);
    }
    else
    {
        if (index1 < 1)
        {
            printf("Before Grade 1\n");
        }
        if (index1 > 16)
        {
            printf("Grade 16+\n");
        }
    }
}
