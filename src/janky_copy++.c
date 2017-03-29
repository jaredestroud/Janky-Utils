/*
 * Standard file I/O copy
 */
#include <errno.h>
#include <stdio.h>

#define BUFFER 10000
#define DEBUG 1   // For debug builds.


/* 
 * Name: std_copy
 * Purpose: Copy a file to user given destination.
 * Parameters: pointer to char array 
 *             (argv for user input) 
 * Return: Nothing.
 */

void std_copy(char *argv[])
{

    FILE *fin;
    FILE *fout;
    char buf[BUFFER];
    int count;

    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");

    while (( count = fread(buf, 1, BUFFER, fin)) > 0)
    {
        fwrite(buf, 1, count, fout);
    }
}

int main(int argc, char *argv[])
{

    if (argc != 3) // jcpp file_src file_dst
    {
        perror("Two arguments are required.");
        return 1;
    }
    else 
    {
        std_copy(argv);
    }

    return 0;
}
