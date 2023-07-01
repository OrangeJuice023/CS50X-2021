//header files
#include "helpers.h"
#include <math.h>
#include <cs50.h>

//global variables
const int max = 255;
const int rflct = 1;
const int CTL = -1;
const int CTR = 1;
float averageg;
int cp;
float tri = 3.0;
//defintion for grayscale
#define iterate_width int i = 0; i < width; i++
#define iterate_height int j = 0; j < height; j++
#define getimgred double r = image[i][j].rgbtRed
#define getimggreen double g = image[i][j].rgbtGreen
#define getimgblue double b = image[i][j].rgbtBlue
#define averager averageg = round((r + b + g) / tri)
#define averagerg image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = averageg
//definition for sepia
#define iterate_h_sepia int i = 0; i < height; i++
#define iterate_w_sepia int j = 0; j < width; j++
#define sepiared_formula double slogr = 1 * .393 * r + .769 * g + .189 * b
#define sepiagreen_formula double slogg = 1 * .349 * r + .686 * g + .168 * b
#define sepiablue_formula double slogb = 1 * .272 * r + .534 * g + .131 * b
#define sepiared_rounder int sepiaRed = border(round(slogr))
#define sepiagreen_rounder int sepiaGreen = border(round(slogg))
#define sepiablue_rounder int sepiaBlue = border(round(slogb))
#define storered_sepia image[i][j].rgbtRed = sepiaRed
#define storegreen_sepia image[i][j].rgbtGreen = sepiaGreen
#define storeblue_sepia image[i][j].rgbtBlue = sepiaBlue
//definition for reflect
#define iterate_row_reflect int i = 0; i < height; i = i + 1
#define width_divider double ls = width / 2
#define column_iterater int j = 0; j < ls; j = j + 1
#define storeimg strg = image[i][j]
#define reflect_img image[i][j] = image[i][width - j - rflct]
#define store_relfected_img  image[i][width - j - rflct] = strg
#define return_boolean return x >= 0 && x  < h && y >= 0 && y < w
//definition for blur
#define tempblur RGBTRIPLE temp[height][width]
#define iterate_blurh int i = 0; i < height; i++
#define iterate_blurw int j = 0; j < width; j++
#define cntrimg double cntr = 0.00
#define blurneighborH int cx = i - 1; cx < (i + 2); cx++
#define blurneighborW int cy = j - 1; cy < (j + 2); cy ++
#define check_n_pexels cx < 0 || cy < 0 || cx >= height || cy >= width
#define countred rv += image[cx][cy].rgbtRed
#define countgreen  gv += image[cx][cy].rgbtGreen
#define countblue bv += image[cx][cy].rgbtBlue
//definition for average
#define average_neighorred int imgr = round(rv / cntr)
#define average_neighborgreen int imgg = round(gv / cntr)
#define average_neighborblue int imgb = round(bv / cntr)
#define storetempr_toimgr temp[i][j].rgbtRed = imgr
#define storetempr_toimgg temp[i][j].rgbtGreen = imgg
#define storetempr_toimgb temp[i][j].rgbtBlue = imgb
#define storeimg_totempred  image[i][j].rgbtRed = temp[i][j].rgbtRed
#define storeimg_totempgreen image[i][j].rgbtGreen = temp[i][j].rgbtGreen
#define storeimg_totempblue image[i][j].rgbtBlue = temp[i][j].rgbtBlue

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (iterate_width)
    {
        for (iterate_height)
        {
            getimgred;
            getimggreen;
            getimgblue;
            // averages the color intensity and then applies the same value to all the colors to get gray
            averager;
            averagerg;

        }
    }
    return;
}

int border(int c)
{
    return c > max ? max : c;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (iterate_h_sepia)
    {
        for (iterate_w_sepia)
        {
            getimgred;
            getimggreen;
            getimgblue;

            sepiared_formula;
            sepiagreen_formula;
            sepiablue_formula;

            sepiared_rounder;
            sepiagreen_rounder;
            sepiablue_rounder;

            storered_sepia;
            storegreen_sepia;
            storeblue_sepia;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE strg;
    width_divider;
    // Iterate over every row of the image
    for (iterate_row_reflect)
    {
        // Iterate over every column that are less than width / 2
        for (column_iterater)
        {
            storeimg;
            reflect_img;
            store_relfected_img;
        }
    }
    return;
}

//checks if the pixel is valid
bool valid(double x, double y, double h, double w)
{
    return_boolean;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create a temporary image to implement blurred algorithm on it.
    tempblur;
    for (iterate_blurh)
    {
        for (iterate_blurw)
        {
            int gv, bv, rv;
            gv = bv = rv = 0;
            cntrimg;

            for (blurneighborH)
            {
                for (blurneighborW)
                {
                    //check for valid neighbouring pexels
                    if (check_n_pexels)
                    {
                        continue;
                    }

                    //ints the rgb 
                    countred;
                    countgreen;
                    countblue;

                    cntr++;
                }
            }

            //do the average of neigbhouring pexels
            average_neighorred;
            average_neighborgreen;
            average_neighborblue;

            storetempr_toimgr;
            storetempr_toimgg;
            storetempr_toimgb;
        }
    }
    //copy the blurr image to the original image
    for (iterate_blurh)
    {
        for (iterate_blurw)
        {
            //sotres img to temp
            storeimg_totempred;
            storeimg_totempgreen;
            storeimg_totempblue;
        }
    }
    return;
}
