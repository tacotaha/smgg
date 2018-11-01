#include <string.h>

#include "MediaGen.h"


media_t media_type(const char* file_name){
    const char *image_exts[] = {"jpg", "jpeg", "png", "gif", "tif"};
    const char *video_exts[] = {"mp4", "avi", "mov", "mkv"};
    char* ext = strchr(file_name, '.');
    if(!ext || ext == file_name) return 0;
    ++ext;
    for(int i = 0; i < strlen(ext); ++i)
        ext[i] += (ext[i] < 0x5A && ext[i] > 0x40) ? 0x20 : 0;
    for(int i = 0; i <  sizeof(image_exts)/sizeof(image_exts[0]); ++i)
        if(!strcmp(image_exts[i], ext)) return IMAGE;
    for(int i = 0; i <  sizeof(video_exts)/sizeof(video_exts[0]); ++i)
        if(!strcmp(video_exts[i], ext)) return VIDEO;
    return UNKOWN;
}
