#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int avg = round(((float) red + (float) blue + (float) green) / 3);
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int total_blue;
            int total_green;
            int total_red;
            float counter;
            total_blue = total_green = total_red = counter = 0;
            if (i >= 0 && j >= 0)
            {
                total_red += temp[i][j].rgbtRed;
                total_green += temp[i][j].rgbtGreen;
                total_blue += temp[i][j].rgbtBlue;
                counter++;
            }
            if (i >= 0 && j - 1 >= 0)
            {
                total_red += temp[i][j - 1].rgbtRed;
                total_green += temp[i][j - 1].rgbtGreen;
                total_blue += temp[i][j - 1].rgbtBlue;
                counter++;
            }
            if (i - 1 >= 0 && j >= 0)
            {
                total_red += temp[i - 1][j].rgbtRed;
                total_green += temp[i - 1][j].rgbtGreen;
                total_blue += temp[i - 1][j].rgbtBlue;
                counter++;
            }
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                total_red += temp[i - 1][j - 1].rgbtRed;
                total_green += temp[i - 1][j - 1].rgbtGreen;
                total_blue += temp[i - 1][j - 1].rgbtBlue;
                counter++;
            }
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                total_red += temp[i][j + 1].rgbtRed;
                total_green += temp[i][j + 1].rgbtGreen;
                total_blue += temp[i][j + 1].rgbtBlue;
                counter++;
            }
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                total_red += temp[i - 1][j + 1].rgbtRed;
                total_green += temp[i - 1][j + 1].rgbtGreen;
                total_blue += temp[i - 1][j + 1].rgbtBlue;
                counter++;
            }
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                total_red += temp[i + 1][j].rgbtRed;
                total_green += temp[i + 1][j].rgbtGreen;
                total_blue += temp[i + 1][j].rgbtBlue;
                counter++;
            }
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                total_red += temp[i + 1][j - 1].rgbtRed;
                total_green += temp[i + 1][j - 1].rgbtGreen;
                total_blue += temp[i + 1][j - 1].rgbtBlue;
                counter++;
            }
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                total_red += temp[i + 1][j + 1].rgbtRed;
                total_green += temp[i + 1][j + 1].rgbtGreen;
                total_blue += temp[i + 1][j + 1].rgbtBlue;
                counter++;
            }
            image[i][j].rgbtRed = round(total_red / counter);
            image[i][j].rgbtGreen = round(total_green / counter);
            image[i][j].rgbtBlue = round(total_blue / counter);
        }
    }
    return;
}
