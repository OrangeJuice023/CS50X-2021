//header files
#include <stdio.h>
#include <math.h>
#include <cs50.h>

//defined variables
#define prompt_change double d = get_double("Change owed: ")
#define match_the_currency c = round(d * 100)
#define if_currency_lessthanorequal c <= 0 
#define pennies int w = c / 25
#define nickels int x = (c % 25) / 10
#define dimes int y = ((c % 25) % 10) / 5
#define quarters int z = ((c % 25) % 10) % 5
#define add_all  printf("%d\n", w + x + y + z)


int main(void)
{
    int c;

    do
    {
        prompt_change;
        match_the_currency; // rounds input value to dollar currency
    }
    while (if_currency_lessthanorequal); //input must be larger than 0 (0.41 > 0)

    //initiates that Greedy Algorithm
    pennies;
    nickels;
    dimes;
    quarters;
    
    //adds all the denominations together to show the change
    add_all;
}