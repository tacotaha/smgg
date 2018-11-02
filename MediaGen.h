#ifndef MEDIAGEN_H
#define MEDIAGEN_H 

#include <ftw.h>
#include <unistd.h>

// Change in style.css as well
#define HEIGHT 300 
#define WIDTH 300 

typedef enum media_t{UNKOWN, IMAGE, VIDEO} media_t;

media_t media_type(const char* file_name);
int gen_thumbs(const char* dir_name);
int rm(const char *path, const struct stat *s, int flag, struct FTW *f);

#endif /* MEDIAGEN_H */
