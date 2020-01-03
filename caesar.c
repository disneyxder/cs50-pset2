#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int key(void);
int main(int argc, string argv[])
{
    // check if user entered a key when executing the program
    if (argc != 2)
    {
        key();
    }
    else
    {
        // initialize bool = true
        bool validity = true;
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            // check if digits entered by user are numeric
            if (!isdigit(argv[1][i]))
            {
                // set bool = false and stop the loop if any digit is non-numeric
                validity = false;
                i = n;
            }
        }
        // if bool = false, print error message and quit
        if (!validity)
        {
            key();
        }
        else
        {
            // change key string to int
            int k = atoi(argv[1]);
            string plaintext = get_string("plaintext: ");
            printf("ciphertext: ");
            int len = strlen(plaintext);
            for (int j = 0; j < len; j++)
            {
                if (isalpha(plaintext[j]))
                {
                    int ascii1 = (int) plaintext[j];
                    int ascii2;
                    if (ascii1 + k > 122)
                    {
                        ascii2 = 97 + k - 122 + ascii1 - 1;
                    }
                    else
                    {
                        ascii2 = ascii1 + k;
                    }
                    char ciphertext = (char) ascii2;
                    printf("%c", ciphertext);
                }
                if (isspace(plaintext[j]))
                {
                    printf(" ");
                }
                if (isdigit(plaintext[j]))
                {
                    printf("%i", plaintext[j]);
                }
                if (ispunct(plaintext[j]))
                {
                    printf("%c", plaintext[j]);
                }
            }
            printf("\n");
        }
    }
}

int key(void)
{
    printf("Usage: ./caesar key\n");
    return 1;
}
