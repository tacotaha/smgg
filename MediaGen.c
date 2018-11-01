#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <ImageMagick-7/MagickWand/MagickWand.h>

#include "MediaGen.h"

media_t media_type(const char* file_name){
    const char *image_exts[] = {"jpg", "jpeg", "png", "gif", "tif"};
    const char *video_exts[] = {"mp4", "avi", "mov", "mkv"};
    char* ext = strchr(file_name, '.');
    if(!ext || ext == file_name) return UNKOWN;
    ++ext;
    for(size_t i = 0; i < strlen(ext); ++i)
        ext[i] += (ext[i] < 0x5A && ext[i] > 0x40) ? 0x20 : 0;
    for(size_t i = 0; i <  sizeof(image_exts)/sizeof(image_exts[0]); ++i)
        if(!strcmp(image_exts[i], ext)) return IMAGE;
    for(size_t i = 0; i <  sizeof(video_exts)/sizeof(video_exts[0]); ++i)
        if(!strcmp(video_exts[i], ext)) return VIDEO;
    return UNKOWN;
}

int gen_thumbs(const char* dir){
    int count = 0, status = 0;
    char buffer[1024];
    struct dirent* dp;
    MagickWand *wand = NULL; 
    DIR *dfd;

    if(!(dfd = opendir(dir))){ 
        perror("opendir: ");
        return -1;
    }
    
    system("rm -rf thumbs;mkdir thumbs");
    MagickWandGenesis(); 
    wand = NewMagickWand();

    while((dp = readdir(dfd))){
            sprintf(buffer, "%s/%s", dir,dp->d_name);
        	status = MagickReadImage(wand, buffer);
            if(!status)
                printf("Failed to read: %s\n", dp->d_name);
            status = MagickResizeImage(wand, WIDTH, HEIGHT, LanczosFilter);
            if(!status) 
                printf("Failed to resize: %s\n", buffer);
            sprintf(buffer, "thumbs/%s", dp->d_name);
            MagickWriteImage(wand, buffer); 
            ++count;
        }
  
    return count;
}
