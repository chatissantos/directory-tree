#import <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "helpers/printError.h"
#include "helpers/printDir.h"
#include "helpers/printHelp.h"

int main(int argc, char *argv[]) {
    int symbolicLinkFlag = 0, timeFlag = 0, gidFlag = 0, numberOfLinksFlag = 0, permissionFlag = 0, sizeFlag = 0, fileTypeFlag = 0, uidFlag = 0, lflag = 0, indentSize = 4;
    int opt;
    int index;
    char* directory;
    while((opt = getopt(argc, argv, "hI:Ldgipstul")) != -1) {
        switch(opt) {
            case 'h':
                printHelp();
                return 0;
            case 'I':
                if ((indentSize = atoi(optarg)) == 0) {
                    printError("Argument supplied to option I is not a number", argv[0]);
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
            case '?':
                if (optopt == 'I')
                    printError("Option -I requires an argument", argv[0]);
                else
                    printError("unknown option", argv[0]);
                return -1;
        }
    }
    if (optind == argc) {
        strcpy(directory, ".");
    } else {
        strcpy(directory, argv[optind]);
    }
    printDir(argv[0], directory, symbolicLinkFlag, timeFlag, gidFlag, numberOfLinksFlag, permissionFlag, sizeFlag, fileTypeFlag, uidFlag, lflag, indentSize, 1);
    return 0;
}


