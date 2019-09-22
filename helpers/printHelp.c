#import <stdio.h>
#include "printHelp.h"

void printHelp() {
    printf("The program will be invoked by:\n\t\t dt [-h] [-I n] [-L -d -g -i -p -s -t -u | -l] [dirname]\n");
    printf("\nThe options are to be interpreted as follows:\n");
    printf("h Print a help message and exit.\n");
    printf("I n Change indentation to n spaces for each level.\n");
    printf("L Follow symbolic links, if any. Default will be to not follow symbolic links.\n");
    printf("t Print information on file type.\n");
    printf("p Print permission bits as rwxrwxrwx.\n");
    printf("i Print the number of links to file in inode table.\n");
    printf("u Print the uid associated with the file.\n");
    printf("g Print the gid associated with the file.\n");
    printf("s Print the size of file in bytes. If the size is larger than 1K, indicate the size in KB with a suffix K; if the size is larger than 1M, indicate the size in MB with a suffix M; if the size is larger than 1G, indicate the size in GB with a suffix G.\n");
    printf("d Show the time of last modification.\n");
    printf("l This option will be used to print information on the file as if the options tpiugs are all specified.\n");
    printf("If the user does not specify dirname, run the command using current directory and print the tree accordingly.\n");
    return;
}

