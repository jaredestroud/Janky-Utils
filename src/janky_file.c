/*
 * Standard file I/O copy
 */
#include <errno.h>
#include <stdio.h>
#include <string.h>

#define BUFFER 10000
#define DEBUG 1   // For debug builds.

// Structure containing a few filetypes.
struct FileTypes{

      char *elf[8];
      char *pdf[8]; 
      char *pe[8]
};


/* 
 * Name: std_file
 * Purpose: Read in first 8 'magic bytes'
 * Parameters: pointer to char array 
 *             (argv for user input) 
 * Return: Nothing.
 */

void std_file(char *argv[])
{
    FILE *fin;
    size_t magic_bytes = 0;
    char *buf[BUFFER];
    char *test = "464c457f";// Elf
    struct FileTypes ft;

    int count = 8;

    fin = fopen(argv[1], "rb");

    magic_bytes = fread(buf, 8, 8, fin);

    if (DEBUG)
    {
        printf("%8x\n", *buf);
    }
    if (strncmp(buf, ft->elf, 8))
    {
        printf("ELF");
    }

}

int main(int argc, char *argv[])
{

    if (argc != 2) // jcpp file_src file_dst
    {
        perror("Two arguments are required.");
        return 1;
    }
    else 
    {
        std_file(argv);
    }

    return 0;
}
