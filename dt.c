#import <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "helpers/printError.h"
#include "helpers/printDir.h"

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
                break;
            case 'L':
                symbolicLinkFlag = 1;
                break;
            case 'd':
                timeFlag = 1;
                break;
            case 'g':
                gidFlag = 1;
                break;
            case 'i':
                numberOfLinksFlag = 1;
                break;
            case 'p':
                permissionFlag = 1;
                break;
            case 's':
                sizeFlag = 1;
                break;
            case 't':
                fileTypeFlag = 1;
                break;
            case 'u':
                uidFlag = 1;
                break;
            case 'l':
                lflag = 1;
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
    printDir(directory, symbolicLinkFlag, timeFlag, gidFlag, numberOfLinksFlag, permissionFlag, sizeFlag, fileTypeFlag, uidFlag, lflag, indentSize, 1);
    return 0;
}


