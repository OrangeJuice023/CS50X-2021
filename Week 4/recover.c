//header files
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include <string.h>
#include <stdbool.h>

// global variables
typedef uint8_t BYTE;
const int bufferblock = 512;
const int filen = 8;
#define error_printer fprintf(stderr, "Usage error\n")
#define exit_inerror exit(1)
#define arg_value_and_cntr_receiver int argc, char *argv[]
#define argv_counter char *check = argv[1]
#define argc_not_2 argc != 2
#define file_node FILE *rfile
#define file_node_open fopen(check, "r")
#define file_node_null rfile == NULL
#define block  BYTE buffer[bufferblock]
#define outputimg_null FILE *open = NULL
#define jpeg_holder char f[filen]
#define read_file fread(buffer, bufferblock, 1, rfile)
#define reader buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0
#define imgnamer sprintf(f, "%03i.jpg", imgcntr)
#define open_new_file open = fopen(f, "a")
#define imgcntr_inc imgcntr++
#define open_file_not_null open != NULL
#define writeblock fwrite(buffer, bufferblock, 1, open)
#define close_first_file  fclose(rfile)
#define close_second_file fclose(open)
//int nJPEG(BYTE buffer[]);
//#define OPENFILE FILE *file
//int openfile(FILE *file);

//returns an error
int inerror()
{
    error_printer;
    exit_inerror;

}

int main(arg_value_and_cntr_receiver)
{
    argv_counter;
    if (argc_not_2)
    {
        return inerror();
    }

    file_node = file_node_open;
    if (file_node_null)
    {
        return inerror();
    }


    // Allocate necessary memory and initialize variables:

    //points to the block of 512 chunks array
    block;
    // initializes the output image
    outputimg_null;

    // array that holds the name of the JPEG
    jpeg_holder;

    // check if we've found a jpeg yet
    int imgcntr = 0;

    while (read_file)
    {
        if (reader)
        {
            // makes name for picture
            imgnamer;
            // opens new
            open_new_file;
            imgcntr_inc;
        }

        if (open_file_not_null)
        {
            // write 512 bytes to file once we start finding jpgs
            writeblock;
        }
    }

    //close files
    close_first_file;
    close_second_file;

    return 0;

}


