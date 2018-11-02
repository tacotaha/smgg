#include <ImageMagick-7/MagickWand/MagickWand.h>
#include <dirent.h>
#include <ftw.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "smgg.h"

media_t media_type(const char *file_name) {
  char *ext = strchr(file_name, '.');
  const char *image_exts[] = IMAGE_EXTS;
  const char *video_exts[] = VIDEO_EXTS;
  if (!ext || ext == file_name) return UNKOWN;
  ++ext;
  for (size_t i = 0; i < strlen(ext); ++i)
    ext[i] += (ext[i] < 0x5A && ext[i] > 0x40) ? 0x20 : 0;
  for (size_t i = 0; i < sizeof(image_exts) / sizeof(image_exts[0]); ++i)
    if (!strcmp(image_exts[i], ext)) return IMAGE;
  for (size_t i = 0; i < sizeof(video_exts) / sizeof(video_exts[0]); ++i)
    if (!strcmp(video_exts[i], ext)) return VIDEO;
  return UNKOWN;
}

int gen_thumbs(const char *dir) {
  int count = 0;
  char buffer[1024];
  struct dirent *dp;
  MagickWand *wand = NULL;
  DIR *dfd;

  if (!(dfd = opendir(dir))) {
    perror("opendir: ");
    return -1;
  }

  nftw("thumbs", rm, FOPEN_MAX, FTW_DEPTH);
  mkdir("thumbs", 0700);

  MagickWandGenesis();
  wand = NewMagickWand();

  while ((dp = readdir(dfd))) {
    sprintf(buffer, "%s/%s", dir, dp->d_name);
    MagickReadImage(wand, buffer); 
    MagickResizeImage(wand, WIDTH, HEIGHT, LanczosFilter);
    sprintf(buffer, "thumbs/%s", dp->d_name);
    MagickWriteImage(wand, buffer);
    ++count;
  }

  return count;
}

int rm(const char *path, const struct stat *s, int flag, struct FTW *f) {
  return flag == FTW_DP ? rmdir(path) : unlink(path);
}
