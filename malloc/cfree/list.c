#include <stdlib.h>

#include "list.h"

struct s_cfree * gl_cfree = NULL;
struct s_cfree_c gl_cfree_c = { 0, 0, 0, 0 };

struct s_cfree * cfree_list_add_first(char * info, void *data, size_t size)
{
  struct s_cfree * new;

  new = malloc(sizeof(struct s_cfree));
  new->info = info;
  new->data = data;
  new->size = size;
  new->prev = NULL;
  new->next = (gl_cfree ? gl_cfree : NULL);
  if (gl_cfree)
    gl_cfree->prev = new;
  return (new);
}

int cfree_list_count(void)
{
  struct s_cfree * l;
  int i;

  if (!gl_cfree)
    return (0);
  for (i = 0, l = gl_cfree; l->next; i++)
    l = l->next;
  return (i);
}
