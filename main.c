#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "smgg.h"

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

  while ((dp = readdir(dfd))) {
    switch (media_type(dp->d_name)) {
      case UNKOWN:
        continue; 
      default:
        printf("<div class=\"responsive\">\n");
        printf("<div class=\"gallery\">\n");
        printf("<a target=\"_blank\" href=\"%s/%s\">\n", dir, dp->d_name);
      case IMAGE:
        printf("<img src=\"thumbs/%s\" alt=\"%s\" width=\"%d\" height=\"%d\">\n",
                dp->d_name, dp->d_name, WIDTH, HEIGHT);
        break;
      case VIDEO:
        printf("<video width=\"%d\" height=\"%d\" controls>\n", WIDTH, HEIGHT);
        printf("<source src=\"%s/%s\" type=\"video/mp4\">", dir, dp->d_name);
        printf("</video>");

        break;
    }
    printf("</a>\n");
    printf("</div>\n");
    printf("</div>\n");
  }
  printf("</body>\n");
  printf("</html>\n");
  return 0;
}
