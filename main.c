#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

#include "header.h"

void main() {
  struct stat metadata;
  stat("README.md", &metadata);
  printf("st_size: %d\n", metadata.st_size);
  printf("st_mode: %o\n", metadata.st_mode);
  printf("st_atime: %s", ctime(&(metadata.st_atime)));
  convertsize((float) metadata.st_size);
  convertperms(metadata.st_mode);
}
