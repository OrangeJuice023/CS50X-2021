#include <stdio.h>
#include <cs50.h>

//define global variables
#define argument_receiver int argc, string argv[]
#define if_argis_1 argc == 1
#define print_nameuser printf("hello Gervi, ")
#define gets_height h = get_int("what is the Height? : ")
#define limiter h < 1 || h > 8
#define iterate_space int x = 0; x < h ; x++
#define iterate_right int y = h - 1; y > x ; y--
#define print_space printf(" ")
#define iterate_hash int z = 0; z <= x ; z++
#define print_hash printf("#")
#define space printf("\n")

int main(argument_receiver)
{
    //prompts the user of name
    if (if_argis_1)
    {
        print_nameuser;
    }
    // Ask the user for height, inclusively 1~8
    int h;
    do
    {
        gets_height;
    }
    while (limiter);
    
    
    for (iterate_space)
    {
        //print spaces
        //if lets say h=6
        //I will get 5
        //my y should be n-1
        for (iterate_right)
        {
            print_space;
        }
        
        
        // prints hashes
        // if for example first iteration is 7
        // I will get 1 hash afer 6 spaces is printed 
        for (iterate_hash)
        {
            //Print the hashes
            print_hash;
        }
        space;
    }

}