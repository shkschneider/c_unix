#include <stdlib.h>

#include "cfree_list.h"

t_cfree * cfree_list_create(void *data, size_t size, char * info)
{
  t_cfree * l = malloc(sizeof(t_cfree));

  l->info = info;
  l->data = data;
  l->size = size;
  l->prev = NULL;
  l->next = NULL;
  return (l);
}

t_cfree * cfree_list_add_first(t_cfree *l, void *data, size_t size, char * info)
{
  t_cfree * new = malloc(sizeof(t_cfree));

  if (!l)
    return (NULL);
  new->info = info;
  new->data = data;
  new->size = size;
  new->prev = NULL;
  new->next = l;
  l->prev = new;
  return (new);
}

int cfree_list_count(t_cfree *l)
{
  int i;

  if (!l)
    return (0);
  for (i = 0; l; i++)
    l = l->next;
  return (i);
}
