#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "cfree_list.h"

#define INFO_MAX 64

extern t_cfree * gl_cfree;

void * cmalloc(size_t size, const char * func, const char * file, const int line) {
  void * p;
  char * s;

  p = malloc(size);
  s = malloc(sizeof(char) * INFO_MAX);
  snprintf(s, INFO_MAX, "%s:%s() l.%d", file, func, line);
  if (!gl_cfree)
    gl_cfree = cfree_list_create(p, size, s);
  else
    gl_cfree = cfree_list_add_first(gl_cfree, p, size, s);
  return (p);
}
