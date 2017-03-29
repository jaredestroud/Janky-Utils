/*
 * Low-level file I/O copy
 * No C-STD libary
 */

#include <fcntl.h> // File control
#include <errno.h>
#define BUF 10000 // fixed size buffer == buffer overflow.
#define DEBUG 1   // For debug builds.


/* 
 * Name: unbuffered_copy
 * Purpose: Copy a file to user given destination.
 *          This DOES NOT use std C libaries.
 * Parameters: pointer to char array 
 *             (argv for user input) 
 * Return: Nothing.
 */

void unbuffered_copy(char *argv[])
{

    int fin;
    int fout;
    int count;
    char buffer[BUF];

    fin = open(argv[1], O_RDONLY);

    if (fin < 0 && DEBUG == 1)
    {
        printf("[DEBUG] Error %d\n", errno);
        perror("[Jankutils] Low I/O Copy");
        exit(1);
    }

    // Open second argument to copy file to.
    fout = open(argv[2], O_WRONLY | O_CREAT, 0644);

    while ((count = read(fin, buffer, BUF)) > 0)
    {
        write(fout, buffer, count);
    }
}

int main(int argc, char *argv[])
{
    unbuffered_copy(argv);
    return 0;
}
