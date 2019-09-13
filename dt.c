#import <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

void printError(char* message);

int main(int argc, char *argv[]) {
    int symbolicLinkFlag = 0, timeFlag = 0, gidFlag = 0, numberOfLinksFlag = 0, permissionFlag = 0, sizeFlag = 0, fileTypeFlag = 0, uidFlag = 0, lflag = 0, indentSize = 4;
    int opt;
    while((opt = getopt(argc, argv, "hI:Ldgipstul")) != -1)
    {
        switch(opt)
        {
            case 'h':
                printf("print help and exit\n");
                return 0;
            case 'I':
                if ((indentSize = atoi(optarg)) == 0) {
                    printError("Argument supplied to option I is not a number");
                    return -1;
                }
                printf("indent size: %d\n", indentSize);
                break;
            case 'L':
                symbolicLinkFlag = 1;
                printf("L flag\n");
                break;
            case 'd':
                timeFlag = 1;
                printf("time last modified flag\n");
                break;
            case 'g':
                gidFlag = 1;
                printf("g flag\n");
                break;
            case 'i':
                numberOfLinksFlag = 1;
                printf("i flag\n");
                break;
            case 'p':
                permissionFlag = 1;
                printf("p flag\n");
                break;
            case 's':
                sizeFlag = 1;
                printf("s flag\n");
                break;
            case 't':
                fileTypeFlag = 1;
                printf("t flag\n");
                break;
            case 'u':
                uidFlag = 1;
                printf("u flag\n");
                break;
            case 'l':
                lflag = 1;
                printf("l flag\n");
                break;
            case ':':
                printError("option needs a value");
                return -1;
            case '?':
                printf("unknown option: %c\n", optopt);
                return -1;
        }
    }
    return 0;
}

void printDir(symbolicLinkFlag, timeFlag, gidFlag, numberOfLinksFlag, permissionFlag, sizeFlag, fileTypeFlag, uidFlag, lflag, indentSize) {

}

void printError(char* message) {
    char str[1000];
    strcpy(str, "dt: Error: ");
    perror(strcat(str, message));
}
