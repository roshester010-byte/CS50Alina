#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum = 0;
            sum += image[i][j].rgbtRed;
            sum += image[i][j].rgbtGreen;
            sum += image[i][j].rgbtBlue;

            int average = round(sum / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++) // because we only need to mirror half of the picture
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width]; // creating a copy of picture so that next time we count a pixel
                                   // we are taking a fresh pixel, not changed one
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    // calculating the average of each so we can find what number to make nearby pixels to make it
    // look blurry
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum_red = 0;
            int sum_green = 0;
            int sum_blue = 0;
            int count = 0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        sum_red += copy[k][l].rgbtRed;
                        sum_green += copy[k][l].rgbtGreen;
                        sum_blue += copy[k][l].rgbtBlue;
                        count++;
                    }
                }
            }

            image[i][j].rgbtRed = round((double) sum_red / count);
            image[i][j].rgbtGreen = round((double) sum_green / count);
            image[i][j].rgbtBlue = round((double) sum_blue / count);
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int Gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
 for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum_red_x = 0;
            int sum_red_y = 0;
            int sum_blue_x = 0;
            int sum_blue_y = 0;
            int sum_green_x = 0;
            int sum_green_y = 0;

            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        sum_red_x += Gx[k - i + 1][l - j + 1] * copy[k][l].rgbtRed;
                        sum_red_y += Gy[k - i + 1][l - j + 1] * copy[k][l].rgbtRed;
                        sum_blue_x += Gx[k - i + 1][l - j + 1] * copy[k][l].rgbtBlue;
                        sum_blue_y += Gy[k - i + 1][l - j + 1] * copy[k][l].rgbtBlue;
                        sum_green_x += Gx[k - i + 1][l - j + 1] * copy[k][l].rgbtGreen;
                        sum_green_y += Gy[k - i + 1][l - j + 1] * copy[k][l].rgbtGreen;
                    }
                }
            }

            int value_red = round(sqrt(sum_red_x * sum_red_x + sum_red_y * sum_red_y));
            int value_blue = round(sqrt(sum_blue_x * sum_blue_x + sum_blue_y * sum_blue_y));
            int value_green = round(sqrt(sum_green_x * sum_green_x + sum_green_y * sum_green_y));

            if (value_red > 255)
            {
                value_red = 255;
            }

            if (value_blue > 255)
            {
                value_blue = 255;
            }

            if (value_green > 255)
            {
                value_green = 255;
            }

            image[i][j].rgbtRed = value_red;
            image[i][j].rgbtBlue = value_blue;
            image[i][j].rgbtGreen = value_green;
        }
    }
}
