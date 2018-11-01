#ifndef MEDIAGEN_H
#define MEDIAGEN_H 

#define HEIGHT 500
#define WIDTH 500

typedef enum media_t{UNKOWN, IMAGE, VIDEO} media_t;

media_t media_type(const char* file_name);
int gen_thumbs(const char* dir_name);

#endif /* MEDIAGEN_H */
