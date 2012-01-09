#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

extern struct s_cfree * gl_cfree;
extern struct s_cfree_c gl_cfree_c;

/*
  void *malloc(size_t size);

  malloc() allocates size bytes and returns a pointer to the allocated memory.  The memory is not cleared.  If size is 0, then malloc() returns either NULL, or a unique pointer value that can later be successfully passed to free().

  For  calloc()  and malloc(), return a pointer to the allocated memory, which is suitably aligned for any kind of variable.  On error, these functions return NULL.  NULL may also be returned by a successful call to malloc() with a size of zero, or by a suc-
  cessful call to calloc() with nmemb or size equal to zero.
*/

void * cmalloc(size_t size, const char * func, const char * file, const int line)
{
  void * data;
  char * info;

  if (!size)
    return (NULL);
  if ((data = malloc(size))) {
    info = malloc(sizeof(char) * CFREE_INFO_MAX);
    snprintf(info, CFREE_INFO_MAX, "%s:%s() l.%d", file, func, line);
    gl_cfree = cfree_list_add_first(info, data, size);
    gl_cfree_c.cmalloc++;
  }
  return (data);
}
