//header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

//defined variables
#define argumentreceiver int argc, string argv[]
#define argnot2 argc != 2
#define printkey  printf("Usage: ./caesar key\n")
#define requiredno_ofstring int k = atoi(argv[1]) % 26
#define printstring string t = get_string("plaintext: ")
#define cipheredtext printf("ciphertext:")
//defined for stringlength
#define iteratethroughstring int x = 0; x < strlen(t); x++
#define storet_tochar char c = t[x]
#define ifc_isalpha isalpha(c)
#define treat_charu_as_A char u = 'A'
#define ifc_islower islower(c)
//defined functions for mapped out ciphered text
#define mapout printf("%c", (c - u + k) % 26 + u)
#define elseprint_c printf("%c", c) 
#define space printf("\n")

int main(argumentreceiver)
{
    if (argnot2) //argument values should be 2 
    {
        printkey;
        return 1;
    }
    
    // if k less than 26, store this as a remainder instead
    requiredno_ofstring; 
     
    printstring;
     
    cipheredtext;
     
    //initiates the ciphertext formula
    for (iteratethroughstring)
    {
        storet_tochar;
        if (ifc_isalpha)
        {
            treat_charu_as_A;
            if (ifc_islower)
            {
                u = 'a';
            }
            //maps out the text and sees what gets ciphered
            mapout;
        }
        else 
        {
            elseprint_c;
        }
          
    }
    //space
    space;
}