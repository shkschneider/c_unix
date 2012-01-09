#include <stdlib.h>

#include "list.h"

extern struct s_cfree * gl_cfree;
extern struct s_cfree_c gl_cfree_c;

/*
  void free(void *ptr);

  free() frees the memory space pointed to by ptr, which must have been returned by a previous call to malloc(), calloc() or realloc().  Otherwise, or if free(ptr) has already been called before, undefined behavior occurs.  If ptr is NULL,  no  operation  is
  performed.

  free() returns no value.
*/

void cfree(void * data)
{
  struct s_cfree * l;

  if (data)
    for (l = gl_cfree; l; l = l->next) {
      if (data == l->data) {
	free(l->info);
	free(l->data);
	if (l->prev)
	  l->prev->next = l->next;
	else
	  gl_cfree = l->next;
	if (l->next)
	  l->next->prev = l->prev;
	free(l);
	gl_cfree_c.cfree++;
      }
    }
}
