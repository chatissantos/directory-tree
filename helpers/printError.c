#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "printError.h"

void printError(char* message, char* executableName) {
    char str[1000];
    strcpy(str, executableName);
    strcat(str, ": Error: ");
    perror(strcat(str, message));
}
