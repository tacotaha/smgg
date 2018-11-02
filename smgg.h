#ifndef MEDIAGEN_H
#define MEDIAGEN_H 

#include <ftw.h>
#include <unistd.h>

/* Height & Width of the generated thumbnails (in pixels) */ 
#define HEIGHT 300 
#define WIDTH 300 

/* Currently supported image and video formats */
#define IMAGE_EXTS {"jpg", "jpeg", "png", "gif", "tif"}
#define VIDEO_EXTS {"mp4", "avi", "mov", "mkv"}

typedef enum media_t{UNKOWN, IMAGE, VIDEO} media_t;

media_t media_type(const char* file_name);
int gen_thumbs(const char* dir_name);
int rm(const char *path, const struct stat *s, int flag, struct FTW *f);

#endif /* MEDIAGEN_H */
