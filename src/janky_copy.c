
/*
 * Low-level file I/O copy
 * No C-STD libary
 */

#include <fcntl.h> // File control
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#define BUF 10000 // fixed size buffer == buffer overflow.
#define DEBUG 1   // For debug builds.


void create_file(char *fileName)
{

    int fd = open(fileName, O_WRONLY | O_CREAT, 0644);

    if (fd < 0)
    {
        printf("Error number %d\n", errno);
        perror("foo");
        exit(1);
    }
    else
    {
        write(fd, "Hello World", 11);
        close(fd);
    }
}


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
    int fseek;
    int count;
    char buffer[BUF];

    // Add exception handling and junk.
    if (fin < 0 && DEBUG == 1)
    {
        printf("[DEBUG] Error %d\n", errno);
        perror("[Jankutils] Low I/O Copy");
        exit(1);
    }
    else
    {
        fin = open(argv[1], O_RDONLY);
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

    char *fName = "data.log";
    create_file(fName);
    unbuffered_copy(argv);

    return 0;
}
