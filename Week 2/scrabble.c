#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//definition for all variables
#define assign_points int points_per_letter[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}
#define calculate_thewinner int calculate_winner(string w)
#define argumentreceiver int argc, string argv[]
#define ifargis1 argc == 1
#define printhellouser printf("hello Gervi, ")
#define getplayer1 string w1 = get_string(" What word for Player 1? : ")
#define getplayer2 string w2 = get_string("What word for Player 2? : ")
#define calculateplayer1 int s1 = calculate_winner(w1)
#define calculateplayer2 int s2 = calculate_winner(w2)
#define ifplayer1greaterthan2 s1 > s2
#define printwinplayer1 printf("Player 1 wins!\n")
#define ifplayer2greatherthan1 s2 > s1
#define printwinplayer2 printf("Player 2 wins!\n")
#define printtie printf("Tie!\n")
//definied variables for calculating winner
#define initatetto_zero int t = 0
#define countthelength_ofwords int y = strlen(w)
#define iterate_each_char int x = 0; x < y; x++
#define asciicodelow islower(w[x])
#define determine_ascii_low t = t + points_per_letter[w[x] - 'a']
#define asciicodeupper isupper(w[x])
#define determine_ascii_upper t = t + points_per_letter[w[x] - 'A']

// Points assigned to each letter of the alphabet 
assign_points;

calculate_thewinner;

int main(argumentreceiver)
{
    //prompts the user of name
    if (ifargis1)
    {
        printhellouser;
    }
    // Get input words from both players
    getplayer1;
    getplayer2;

    // Score both words
    calculateplayer1;
    calculateplayer2;

    // TODO: Print the winner
    // Decide scores by comparing
    if (ifplayer1greaterthan2)
    {
        printwinplayer1;
    }
    else if (ifplayer2greatherthan1)
    {
        printwinplayer2;
    }
    else 
    {
        printtie;
    }
}

int calculate_winner(string w)
{
    // TODO: Compute and return score for string
    //Total scores
    initatetto_zero;
    
    countthelength_ofwords;
    
    //Loop every char through the word
    for (iterate_each_char)
    {
        ///Determines the scrabble position through the ASCII code
        if (asciicodelow)
        {
            determine_ascii_low;
        }
        else if (asciicodeupper)
        {
            determine_ascii_upper;
        }
    }
    return t;
}    