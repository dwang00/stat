#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

void convertsize(float size) {
  int i = 0;
  while (size > 1024) {
    size /= 1024.0;
    i++;
  }
  if (i > 3) {
    printf("%.2f GB\n", size);
  }
  else if (i > 2) {
    printf("%.2f MB\n", size);
  }
  else if (i > 1) {
    printf("%.2f KB\n", size);
  }
  else {
    printf("%.2f B\n", size);
  }
}

char * numtols(int i, char * ans) {
  strcpy(ans, "---");
  if (i >= 4) {
    i -= 4;
    ans[0] = 'r';
  }
  if (i >= 3 || i == 2) {
    i -= 2;
    ans[1] = 'w';
  }
  if (i == 1) {
    i -= 1;
    ans[2] = 'x';
  }
  return ans;
}

void convertperms(mode_t perms) {
  int octal = 0, i = 1;
  while (perms != 0) {
      octal += (perms % 8) * i;
      perms /= 8;
      i *= 10;
  }
  while (octal > 1000) {
    octal -= 1000;
  }
  int u = octal / 100, g = (octal - (u * 100)) / 10, o = (octal - (u * 100) - (g * 10));
  char ans[3] = "";
  printf("%s%s%s\n", numtols(u, ans), numtols(g, ans), numtols(o, ans));
}
