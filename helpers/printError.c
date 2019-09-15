#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "printError.h"

void printError(char* message) {
    char str[1000];
    strcpy(str, "dt: Error: ");
    perror(strcat(str, message));
}
