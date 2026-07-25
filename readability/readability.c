#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string sentence = get_string("What's your sentence? ");
    printf("%s\n", sentence);

    int letters = 0;
    for (int i = 0; i < strlen(sentence); i++)
    {
        if (isalpha(sentence[i]))
        {
            letters++;
        }
    }

    int words = 1;
    for (int w = 0; w<strlen(sentence); w++)
    {
        if (sentence[w] == ' ')
        {
            words++;
        }
    }

    int sentences = 0;
    for (int s = 0; s<strlen(sentence); s++)
    {
        if (sentence[s] == '.' || sentence[s] == '!' || sentence[s] == '?')
        {
            sentences++;
        }
    }

    float L = ((float)letters / words) * 100;
    float S = (sentences / (float)words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = (int) round(index);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

