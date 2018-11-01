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
    struct stat st_buff;
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
        if(is_image(dp->d_name)){
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

int is_image(const char* file_name){
    char *ext, *image_exts[] = {"jpg", "jpeg", "png", "gif", "tif"};
    ext = strchr(file_name, '.');
    if(!ext || ext == file_name) return 0;
    ++ext;
    for(int i = 0; i < strlen(ext); ++i)
        ext[i] += (ext[i] < 0x5A && ext[i] > 0x40) ? 0x20 : 0;
    for(int i = 0; i <  sizeof(image_exts)/sizeof(image_exts[0]); ++i)
        if(!strcmp(image_exts[i], ext)) return 1;
    return 0;
}
