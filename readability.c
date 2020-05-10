#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // variables
    string s = get_string("Text: ");
    int letter, word, sentence; 
    letter = 0;
    word = 1; 
    sentence = 0; 
    
    // count the letters, words and sentences
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            letter++; 
        }
        if (s[i] == ' ' && isalpha(s[i+1]))
        {
            word++;
        }
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentence++;
        }
    }
    
    // calculate index of text
    float L, S, indexf; 
    L = letter / word * 100; 
    S = sentence / word * 100; 
    indexf = 0.0588 * L - 0.296 * S - 15.8;
    int index; 
    index = round(indexf);
    
    // print grade
    if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", index);
        return 0; 
    }
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0; 
    }
    if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0; 
    }
}
