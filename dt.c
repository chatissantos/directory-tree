#import <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <dirent.h>

void printError(char* message);
void printDir(
        char* directory
        , int symbolicLinkFlag
        , int timeFlag
        , int gidFlag
        , int numberOfLinksFlag
        , int permissionFlag
        , int sizeFlag
        , int fileTypeFlag
        , int uidFlag
        , int lflag
        , int indentSize
);
int main(int argc, char *argv[]) {
    int symbolicLinkFlag = 0, timeFlag = 0, gidFlag = 0, numberOfLinksFlag = 0, permissionFlag = 0, sizeFlag = 0, fileTypeFlag = 0, uidFlag = 0, lflag = 0, indentSize = 4;
    int opt;
    int index;
    char* directory;
    while((opt = getopt(argc, argv, "hI:Ldgipstul")) != -1) {
        switch(opt) {
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
                printf("Follow symbolic links flag\n");
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
    if (optind == argc) {
        strcpy(directory, ".");
    } else {
        strcpy(directory, argv[optind]);
    }
    printDir(directory, symbolicLinkFlag, timeFlag, gidFlag, numberOfLinksFlag, permissionFlag, sizeFlag, fileTypeFlag, uidFlag, lflag, indentSize);
    return 0;
}

void printDir(
        char* directory
        , int symbolicLinkFlag
        , int timeFlag
        , int gidFlag
        , int numberOfLinksFlag
        , int permissionFlag
        , int sizeFlag
        , int fileTypeFlag
        , int uidFlag
        , int lflag
        , int indentSize
        ) {
    int index;
    struct dirent *de;
    DIR *dr = opendir(directory);
    if (dr == NULL) {
        char str[1000];
        strcpy(str, directory);
        printError(strcat(str, " is not a directory"));
        return;
    }
    while ((de = readdir(dr)) != NULL) {
        for (index = 0; index < indentSize; index++) {
            printf(" ");
        }
        printf("%s\t\t\t\t\t%hhu\n", de->d_name, de->d_type);
        if (de->d_type == 4 && (strncmp(de->d_name, ".", 1) != 0) && (strncmp(de->d_name, "..", 2) != 0)) {
            char newDir[1000];
            strcpy(newDir, directory);
            strcat(newDir, "/");
            strcat(newDir, de->d_name);
            printDir(newDir, symbolicLinkFlag, timeFlag, gidFlag, numberOfLinksFlag, permissionFlag, sizeFlag, fileTypeFlag, uidFlag, lflag, indentSize + 4);
        }
    }
    closedir(dr);
    return;
}

void printError(char* message) {
    char str[1000];
    strcpy(str, "dt: Error: ");
    perror(strcat(str, message));
}
