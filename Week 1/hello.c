#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    //prompts the user of name
    if (argc == 1)
    {
        printf("hello user, ");
    }
    //Asks for the user's name
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}