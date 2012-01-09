#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

extern struct s_cfree * gl_cfree;
extern struct s_cfree_c gl_cfree_c;

/*
  void *calloc(size_t nmemb, size_t size);

  calloc()  allocates  memory  for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory.  The memory is set to zero.  If nmemb or size is 0, then calloc() returns either NULL, or a unique pointer value that can later be
  successfully passed to free().

  For  calloc()  and malloc(), return a pointer to the allocated memory, which is suitably aligned for any kind of variable.  On error, these functions return NULL.  NULL may also be returned by a successful call to malloc() with a size of zero, or by a suc-
  cessful call to calloc() with nmemb or size equal to zero.
*/

void * ccalloc(size_t nmemb, size_t size, const char * func, const char * file, const int line)
{
  void * data;
  char * info;

  if (!(nmemb * size))
    return (NULL);
  info = malloc(sizeof(char) * CFREE_INFO_MAX);
  snprintf(info, CFREE_INFO_MAX, "%s:%s() l.%d", file, func, line);
  data = calloc(nmemb, size);
  gl_cfree = cfree_list_add_first(info, data, nmemb * size);
  gl_cfree_c.ccalloc++;
  return (data);
}
