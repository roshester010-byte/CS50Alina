#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // to check if argc is no more than 2 arg(program name and the key itself)
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // to check 1) the length of the key 2) only alphabet letters 3) doesn't repeat itself
    int non_repeat[26] = {0};
    if (strlen(argv[1]) != 26)
    {
        printf("error: should be exactly 26 letters\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("error: all characters should be letters\n");
            return 1;
        }
        int index = toupper(argv[1][i]) - 'A';
        if (non_repeat[index] > 0)
        {
            printf("error: letters should not repeat\n");
            return 1;
        }
        else
        {
            non_repeat[index]++;
        }
    }
    printf("plaintext: ");
    string message = get_string("");

    // get the message and encrypt it
    char encrypted[strlen(message) + 1];
    for (int i = 0; i < strlen(message); i++)
    {
        if (isalpha(message[i]))
        {
            int index = toupper(message[i]) - 'A';
            char substitued = argv[1][index];
            if (isupper(message[i]))
            {
                encrypted[i] = toupper(substitued);
            }
            else
            {
                encrypted[i] = tolower(substitued);
            }
        }
        else
        {
            encrypted[i] = message[i];
        }
    }
    encrypted[strlen(message)] = '\0';
    printf("ciphertext: %s\n", encrypted);
    return 0;
}
