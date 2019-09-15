#include <sys/stat.h>
#include <sys/types.h>
#import <stdio.h>
#include "printFileStat.h"

void printFileStat(char* fileName) {
    struct stat fileStat;
    if(stat(fileName,&fileStat) < 0)
        return;

    printf("%lld bytes",fileStat.st_size);
    printf(" %d links",fileStat.st_nlink);
    printf(" %llu nodes",fileStat.st_ino);

    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
}
