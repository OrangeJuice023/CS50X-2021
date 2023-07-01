// Modifies the volume of an audio file
#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//defined variables
typedef  int16_t ba;
#define commandlinechecker int argc, char *argv[]
#define argc_not4 argc != 4
#define printerrorvolume printf("Usage: ./volume input.wav output.wav factor\n")
#define returnerrorfirst return 1
#define openfilepntr FILE *input
#define openfile fopen(argv[1], "r")
#define inputis_null input == NULL
#define notopen_file  printf("Could not open file.\n")
#define returnerrorsecond return 1
#define outputfilepntr FILE *output
#define openfilesecond fopen(argv[2], "w")
#define if_outputnull output == NULL
#define returnerrorthird return 1
#define third_file  float factor = atof(argv[3])
#define allocpntr uint8_t *header
#define allocatedsize malloc(sizeof(uint8_t) * HEADER_SIZE)
#define headernull header == NULL
#define returnerrorfourth return 1 
#define readinputfile fread(header, sizeof(uint8_t), HEADER_SIZE, input)
#define writeoutputfile fwrite(header, sizeof(uint8_t), HEADER_SIZE, output)
#define readsampleinputfile fread(&buffer, sizeof(ba), 1, input)
#define readsampleoutputfile fwrite(&buffer, sizeof(ba), 1, output)
#define freeh free(header)
#define closef fclose(input)
#define closeo fclose(output)
// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(commandlinechecker)
{
    // Check command-line arguments
    if (argc_not4)
    {
        printerrorvolume;
        returnerrorfirst;
    }

    // Open files and determine scaling factor
    openfilepntr = openfile;
    if (inputis_null)
    {
        notopen_file;
        returnerrorsecond;
    }

    outputfilepntr = openfilesecond;
    if (if_outputnull)
    {
        notopen_file;
        returnerrorthird;
    }

    third_file;

    // TODO: Copy header from input file to output file

    allocpntr = allocatedsize;
    if (headernull)
    {
        returnerrorfourth;
    }
    readinputfile;
    writeoutputfile;

    // TODO: Read samples from input file and write updated data to output file
    ba buffer;
    while (readsampleinputfile)
    {
        buffer *= factor;
        readsampleoutputfile;
    }

    //frees up the memory of the buffer
    freeh;

    // Close files
    closef;
    closeo;
}
