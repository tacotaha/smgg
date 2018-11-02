#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MediaGen.h"

int main(int argc, char* argv[]) {
  struct dirent* dp;
  DIR* dfd;

  const char* dir = (argc == 2 ? argv[1] : ".");

  if (!(dfd = opendir(dir))) {
    perror("opendir: ");
    return -1;
  }

  printf("<!DOCTYPE html>\n");
  printf("<html>\n");
  printf("<head>\n");
  printf("<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"/>\n");
  printf("</head>\n");
  printf("<body>\n");

  gen_thumbs(dir);

  while ((dp = readdir(dfd)))
    if (media_type(dp->d_name) == IMAGE) {
      printf("<div class=\"responsive\">\n");
      printf("<div class=\"gallery\">\n");
      printf("<a target=\"_blank\" href=\"%s/%s\">\n", dir, dp->d_name);
      printf("<img src=\"thumbs/%s\" alt=\"%s\" width=\"%d\" height=\"%d\">\n",
             dp->d_name, dp->d_name, WIDTH, HEIGHT);
      printf("</a>\n");
      printf("</div>\n");
      printf("</div>\n");
    }

  printf("</body>\n");
  printf("</html>\n");
  return 0;
}
