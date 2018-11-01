#ifndef MEDIAGEN_H
#define MEDIAGEN_H 

#define HEIGHT 500
#define WIDTH 500

typedef enum media_t{UNKOWN, IMAGE, VIDEO} media_t;

int is_image(const char* file_name);

#endif /* MEDIAGEN_H */
