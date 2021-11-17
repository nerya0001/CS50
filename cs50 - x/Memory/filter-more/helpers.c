#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int grey = round(((float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtRed) / 3);

            image[i][j].rgbtBlue = grey;
            image[i][j].rgbtGreen = grey;
            image[i][j].rgbtRed = grey;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

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
            image[i][width - j - 1] = copy[i][j];
        }
    }
    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

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
            float sumb = 0;
            float sumg = 0;
            float sumr = 0;
            int count = 0;

            //case #1
            sumb += copy[i][j].rgbtBlue;
            sumg += copy[i][j].rgbtGreen;
            sumr += copy[i][j].rgbtRed;
            count++;

            //case #2
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                sumb += copy[i - 1][j - 1].rgbtBlue;
                sumg += copy[i - 1][j - 1].rgbtGreen;
                sumr += copy[i - 1][j - 1].rgbtRed;

                count++;
            }

            //case #3
            if (i - 1 >= 0)
            {
                sumb += copy[i - 1][j].rgbtBlue;
                sumg += copy[i - 1][j].rgbtGreen;
                sumr += copy[i - 1][j].rgbtRed;
                count++;
            }

            //case #4
            if (j - 1 >= 0)
            {
                sumb += copy[i][j - 1].rgbtBlue;
                sumg += copy[i][j - 1].rgbtGreen;
                sumr += copy[i][j - 1].rgbtRed;
                count++;
            }

            //case #5
            if (i + 1 < height)
            {
                sumb += copy[i + 1][j].rgbtBlue;
                sumg += copy[i + 1][j].rgbtGreen;
                sumr += copy[i + 1][j].rgbtRed;
                count++;
            }

            //case #6
            if (j + 1 < width)
            {
                sumb += copy[i][j + 1].rgbtBlue;
                sumg += copy[i][j + 1].rgbtGreen;
                sumr += copy[i][j + 1].rgbtRed;
                count++;
            }

            //case #7
            if (i + 1 < height && j + 1 < width)
            {
                sumb += copy[i + 1][j + 1].rgbtBlue;
                sumg += copy[i + 1][j + 1].rgbtGreen;
                sumr += copy[i + 1][j + 1].rgbtRed;
                count++;
            }

            //case #8
            if (i + 1 < height && j - 1 >= 0)
            {
                sumb += copy[i + 1][j - 1].rgbtBlue;
                sumg += copy[i + 1][j - 1].rgbtGreen;
                sumr += copy[i + 1][j - 1].rgbtRed;
                count++;
            }

            //case #9
            if (i - 1 >= 0 && j + 1 < width)
            {
                sumb += copy[i - 1][j + 1].rgbtBlue;
                sumg += copy[i - 1][j + 1].rgbtGreen;
                sumr += copy[i - 1][j + 1].rgbtRed;
                count++;
            }

            image[i][j].rgbtBlue = round(sumb / (count * 1.0));
            image[i][j].rgbtGreen = round(sumg / (count * 1.0));
            image[i][j].rgbtRed = round(sumr / (count * 1.0));
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
