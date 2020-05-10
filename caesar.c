#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // check for key
    if (argc != 2)
    {
        printf("please input a key!\n");
        return 1; 
    }
    
    // validate key 
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("./caesar key\n");
            return 1; 
        }
    }
    
    int key = atoi(argv[1]);
    
    // prompt user for plaintext
    string p; 
    p = get_string("plaintext: ");
    
    // print ciphertext
    printf("ciphertext: "); 
    for (int j = 0; j < strlen(p); j++)
    {
        if (isalpha(p[j]))
        {
            if (isupper(p[j]))
            {
                p[j] -= 65;
                p[j] = (p[j] + key) % 26; 
                printf("%c", p[j] + 65);
            }
            if (islower(p[j]))
            {
                p[j] -= 97; 
                p[j] = (p[j] + key) % 26; 
                printf("%c", p[j] + 97);
            }
        }
        else
        {
            printf("%c", p[j]); 
        }
    }
    printf("\n"); 
    return 0; 
}
