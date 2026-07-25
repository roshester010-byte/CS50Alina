#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int count = 0;
    int sum = 0;
    int index = 0;
    long number = get_long("Card Number: ");
    long temporary = number;
    // loops that check and see how many digits number has
    // and get to the first two or first one
    // digit to check which card it is
    while (temporary)
    {
        temporary = temporary / 10;
        count++;
    }
    temporary = number;
    for (int i = 0; i < count - 2; i++)
    {
        temporary = temporary / 10;
    }
    int first_two = temporary;
    int first_one = first_two / 10;
    // main loop that executes Luhn algorithm
    while (number)
    {
        int digit = number % 10;
        if (index % 2 == 1)
        {
            if (digit >= 5)
            {
                digit = digit * 2 - 9;
            }
            else
            {
                digit = digit * 2;
            }
        }
        sum += digit;
        number = number / 10;
        index++;
    }

    if (sum % 10 == 0 && count == 15 && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    else if (sum % 10 == 0 && count == 16 &&
             (first_two == 51 || first_two == 52 || first_two == 53 || first_two == 54 ||
              first_two == 55))
    {
        printf("MASTERCARD\n");
    }
    else if (sum % 10 == 0 && (count == 13 || count == 16) && first_one == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
// originally i had a couple more variables to get through this mind-duckery but they were redundant
// in some places so
// i cleaned it up. i hope i was able to remove all the redundancies and the code looks as clean as
// it can be <3
