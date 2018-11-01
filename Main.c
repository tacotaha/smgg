#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

#include "MediaGen.h"

int main(int argc, char* argv[]){
    struct dirent* dp;
    DIR *dfd;

    const char* dir = (argc == 2 ? argv[1] : ".");
    
    if(!(dfd = opendir(dir))){ 
        perror("opendir: ");
        return -1;
    }
    
    printf("<!DOCTYPE html>\n");
    printf("<html>\n");
    printf("<head>\n");
    printf("</head>\n");
    printf("<body>\n");

    while((dp = readdir(dfd)))
        if(media_type(dp->d_name) == IMAGE){
            printf("<div style=\"float: left\">\n");
            printf("<a target=\"_blank\" href=\"%s\">\n", dp->d_name);
            printf("<img src=\"%s\" alt=\"%s\" width=\"%d\" height=\"%d\">\n", dp->d_name, dp->d_name, WIDTH, HEIGHT);
            printf("</a>\n");
            printf("</div>\n"); 
        }
    
    
    printf("</body>\n");
    printf("</html>\n");
    return 0;
}
