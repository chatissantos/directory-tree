#include <dirent.h>
#import <stdio.h>
#include <string.h>
#include "printDir.h"
#include "printFileStat.h"
#include "printError.h"

void printDir(
        char* executableName
        , char* directory
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
        , int currentIndentSize
) {
    int index;
    struct dirent *de;
    DIR *dr = opendir(directory);
    if (dr == NULL) {
        char str[1000];
        strcpy(str, directory);
        printError(strcat(str, " is not a directory"), executableName);
        return;
    }
    while ((de = readdir(dr)) != NULL) {
        for (index = 0; index < currentIndentSize; index++) {
            printf(" ");
        }
        printf("%s", de->d_name);
        for(index = 0; index < 60 - strlen(de->d_name) - currentIndentSize; index++) {
            printf(" ");
        }
        char newDir[1000];
        strcpy(newDir, directory);
        strcat(newDir, "/");
        strcat(newDir, de->d_name);
        printFileStat(newDir);
        printf("\n");
        if (de->d_type == 4 && (strncmp(de->d_name, ".", 1) != 0) && (strncmp(de->d_name, "..", 2) != 0)) {
            printDir(executableName, newDir, symbolicLinkFlag, timeFlag, gidFlag, numberOfLinksFlag, permissionFlag, sizeFlag, fileTypeFlag, uidFlag, lflag, indentSize, currentIndentSize + indentSize);
        }
    }
    closedir(dr);
    return;
}

