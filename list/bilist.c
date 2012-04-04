#include <stdlib.h>

#include "bilist.h"

t_bilist *bilist_create(void *data)
{
  t_bilist *new = malloc(sizeof(t_bilist));

  new->data = data;
  new->prev = NULL;
  new->next = NULL;
  return (new);
}

t_bilist *bilist_add_first(t_bilist *l, void *data)
{
  t_bilist *new = malloc(sizeof(t_bilist));

  if (!l)
    return (NULL);
  new->data = data;
  new->prev = NULL;
  new->next = l;
  l->prev = new;
  return (new);
}

t_bilist *bilist_add_last(t_bilist *l, void *data)
{
  t_bilist *new = malloc(sizeof(t_bilist));

  if (!l)
    return (NULL);
  new->data = data;
  new->next = NULL;
  while (l->next)
    l = l->next;
  l->next = new;
  new->prev = l;
  return (new);
}

int bilist_count(t_bilist *l)
{
  int i;

  if (!l)
    return (0);
  while (l->prev)
    l = l->prev;
  for (i = 0; l; i++)
    l = l->next;
  return (i);
}

t_bilist *bilist_remove_first(t_bilist *l)
{
  t_bilist *first;

  if (!l)
    return (NULL);
  first = l->next;
  free(l);
  first->prev = NULL;
  return (first);
}

t_bilist *bilist_remove_last(t_bilist *l)
{
  t_bilist *last;

  if (!l)
    return (NULL);
  if (bilist_count(l) == 1)
    {
      free(l);
      return (NULL);
    }
  last = l;
  while (last->next)
      last = last->next;
  last->prev->next = NULL;
  free(last);
  return (l);
}

t_bilist *bilist_clear(t_bilist *l)
{
  if (!l)
    return (NULL);
  bilist_clear(l->next);
  free(l);
  return (NULL);
}

t_bilist *bilist_reverse(t_bilist *l)
{
  t_bilist *t = NULL;
  t_bilist *cur = NULL;

  if (!l)
    return (NULL);
  while (l)
    {
      t = l;
      l = t->next;
      t->prev = l;
      t->next = cur;
      cur = t;
    }
  cur->prev = NULL;
  return (cur);
}
