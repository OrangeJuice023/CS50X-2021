//header files
#include <cs50.h>
#include <stdio.h>

//defined variables
#define argumentreceiver int argc, string argv[]
#define ifarg_is1 argc == 1
#define printname printf("hello Gervi , ")
#define promptstart_size p = get_int("What is the Start size? : ")
#define if_lessthan_9 p < 9
#define promptend_size e = get_int("What is the End size? :")
#define ifendlessthenstart e < p
#define ifstartgreaterthanend e > p
#define numberofyearscalculator p = p + (p / 3) - (p / 4)
#define printyears printf("Years: %i", y)
#define space printf("\n")

int main(argumentreceiver)
{
    //prompts the user of name
    if (ifarg_is1)
    {
        printname;
    }
    // TODO: Ask for start size (should be minimum of 9)
    
    int p = 0;
    do
    {
        promptstart_size;
    }
    while (if_lessthan_9);
    

    // TODO: Prompt for end size
      
    int e, y = 0;
    do
    {
        promptend_size;
    }
    while (ifendlessthenstart);

    // TODO: Calculate number of years 

    while (ifstartgreaterthanend)
    {
        numberofyearscalculator;
        y++;
    }

    // TODO: Print number of years
    printyears;
    space;
}
