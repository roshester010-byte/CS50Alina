#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int compute_score(string word);
int main(void)
{
    // Prompts the user for two words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute the score of each word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // checks if we are not out of bounds of the alphabet
    // isalpha checks if letter is a letter and not something else,
    // automatically removes any "'" or spaces
    // toupper converts any letter to upper straight away
    int points[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        char letter = word[i];
        if (isalpha(letter))
        {
            score += points[toupper(letter) - 'A'];
        }
    }
    return score;
}
