#ifndef MEDIAGEN_H
#define MEDIAGEN_H 

#include <ftw.h>
#include <unistd.h>

#define HEIGHT 180 
#define WIDTH 180 

typedef enum media_t{UNKOWN, IMAGE, VIDEO} media_t;

media_t media_type(const char* file_name);
int gen_thumbs(const char* dir_name);
int rm(const char *path, const struct stat *s, int flag, struct FTW *f);

#endif /* MEDIAGEN_H */
