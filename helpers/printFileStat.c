#include <sys/stat.h>
#import <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "printFileStat.h"

char* getHumanFriendlySize(double  size, char* buf);
void printPermission(struct stat fileStat);
void printFileStat(char* fileName) {
    struct stat fileStat;
    if(stat(fileName,&fileStat) < 0)
        return;
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printPermission(fileStat);
    printf("  ");
    printf(" %2d",fileStat.st_nlink);
    printf("  ");
    printf("%s",getpwuid(fileStat.st_uid)->pw_name);
    printf("  ");
    printf("%s",getgrgid(fileStat.st_gid)->gr_name);
    printf("  ");
    char buf[10];
    printf("%5s", getHumanFriendlySize(fileStat.st_size, buf));
    printf("  ");
    printf(" %s", ctime(&fileStat.st_mtime));
}
char* getHumanFriendlySize(double  size, char* buf) {
    const char* units[] = {"", "K", "M", "G", "T", "P", "E", "Z", "Y"};
    int i = 0;
    while (size > 1024) {
        size /= 1024;
        i++;
    }
    sprintf(buf, "%.*f%s", i, size, units[i]);
    return buf;
}
void printPermission(struct stat fileStat) {
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