#include <stdlib.h>

#include "cfree_list.h"

t_cfree * gl_cfree = NULL;

void cfree(void * p) {
  t_cfree * l;

  if (!gl_cfree)
    return ;
  for (l = gl_cfree; l; l = l->next) {
    if (l->data == p) {
      free(l->info);
      free(l->data);
      if (l->prev)
	l->prev->next = l->next;
      else
	gl_cfree = l->next;
      if (l->next)
	l->next->prev = l->prev;
      free(l);
    }
  }
}
