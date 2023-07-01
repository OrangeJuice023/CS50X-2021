#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//declares the variables
int cw, cs, cl;

//defined variables
#define argumentreceive int argc, string argv[]
#define argcis1 argc == 1
#define printuser printf("hello Gervi, ")
#define printsnextstring string i = get_string("What is the text? : ")
#define setall_tozero cw = cs = cl = 0
#define iteratethroughstring int x = 0, n = strlen(i); x < n; x++
#define converttobig isalpha(i[x])
#define countsthe_word (x == 0 && i[x] != ' ') || (x != n - 1 &&  i[x] == ' ' && x[i + 1] != ' ')
#define scount i[x] == '.' || i[x] == '!' || i[x] == '?'
#define CLI_L double L = (cl / (float) cw) * 100
#define CLI_S double S = (cs / (float) cw) * 100
#define roundscore int score = round(0.0588 * L - 0.296 * S - 15.8)
//defined functions for printing the grade
#define scoreequalorlessthan_one score  <= 1
#define scoregreaterthanorequal_sixteen score >= 16
#define printbefg1 printf("Before Grade 1\n")
#define printg16 printf("Grade 16+\n")
#define printscore printf("Grade %i\n", score)

int main(argumentreceive)
{
    //greets the user
    if (argcis1)
    {
        printuser;
    }
    
    printsnextstring;
    setall_tozero;
    //counts the number of sentences, letters, and words
    for (iteratethroughstring)
    {
    
        //counts the letters
        if (converttobig)
        {
            cl += 1;
        }
        //counts the words
        if (countsthe_word)
        {
            cw += 1;
        }
        //counts the sentences
        if (scount)
        {
            cs += 1;
        }

    }

    //initiates the Coleman-Liau index
    CLI_L;
    CLI_S;
    roundscore;

    //prints the grading per sentence
    if (scoreequalorlessthan_one)
    {
        printbefg1;
    }
    else if (scoregreaterthanorequal_sixteen)
    {
        printg16;
    }
    else
    {
        printscore;
    }
    
}





