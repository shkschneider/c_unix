#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "core.h"
#include "list.h"

extern struct s_cfree * gl_cfree;
extern struct s_cfree_c gl_cfree_c;

/*
  void *realloc(void *ptr, size_t size);

  realloc()  changes  the  size  of  the memory block pointed to by ptr to size bytes.  The contents will be unchanged to the minimum of the old and new sizes; newly allocated memory will be uninitialized.  If ptr is NULL, then the call is equivalent to mal-
  loc(size), for all values of size; if size is equal to zero, and ptr is not NULL, then the call is equivalent to free(ptr).  Unless ptr is NULL, it must have been returned by an earlier call to malloc(), calloc() or realloc().  If the area pointed  to  was
  moved, a free(ptr) is done.

  realloc() returns a pointer to the newly allocated memory, which is suitably aligned for any kind of variable and may be different from ptr, or NULL if the request fails.  If size was equal to 0, either NULL or a pointer suitable to be passed to free()  is
  returned.  If realloc() fails the original block is left untouched; it is not freed or moved.
*/

void * crealloc(void * data, size_t size, const char * func, const char * file, const int line)
{
  struct s_cfree * l;
  char * info;

  if (!size) {
    cfree(data);
    return (NULL);
  }
  for (l = gl_cfree; l; l = l->next) {
    if (data == l->data) {
      free(l->info);
      info = malloc(sizeof(char) * CFREE_INFO_MAX);
      snprintf(info, CFREE_INFO_MAX, "%s:%s() l.%d", file, func, line);
      l->info = info;
      gl_cfree_c.crealloc++;
      /* data = realloc(data, size); */
      return (data);
    }
  }
  return (NULL);
}
