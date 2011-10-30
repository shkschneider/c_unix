#include <stdlib.h>

#include "bilist.h"

t_bilist	*bilist_create(void *data)
{
  t_bilist	*new = malloc(sizeof(t_bilist));

  new->data = data;
  new->prev = 0;
  new->next = 0;
  return (new);
}

t_bilist	*bilist_add_first(t_bilist *l, void *data)
{
  t_bilist	*new = malloc(sizeof(t_bilist));

  if (!l)
    return (0);
  new->data = data;
  new->prev = 0;
  new->next = l;
  l->prev = new;
  return (new);
}

t_bilist	*bilist_add_last(t_bilist *l, void *data)
{
  t_bilist	*new = malloc(sizeof(t_bilist));

  if (!l)
    return (0);
  new->data = data;
  new->next = 0;
  while (l->next)
    l = l->next;
  l->next = new;
  new->prev = l;
  return (new);
}

int	bilist_count(t_bilist *l)
{
  int	i;

  if (!l)
    return (0);
  while (l->prev)
    l = l->prev;
  for (i = 0; l; i++)
    l = l->next;
  return (i);
}

t_bilist	*bilist_remove_first(t_bilist *l)
{
  t_bilist	*first;

  if (!l)
    return ;
  first = l->next;
  free(l);
  first->prev = 0;
  return (first);
}

t_bilist	*bilist_remove_last(t_bilist *l)
{
  t_bilist	*last;

  if (!l)
    return ;
  if (bilist_count(l) == 1)
    {
      free(l);
      return (0);
    }
  last = l;
  while (last->next)
      last = last->next;
  last->prev->next = 0;
  free(last);
  return (l);
}

t_bilist	*bilist_empty(t_bilist *l)
{
  if (!l)
    return ;
  bilist_empty(l->next);
  free(l);
  return (0);
}

t_bilist	*bilist_reverse(t_bilist *l)
{
  t_bilist	*t;
  t_bilist	*cur;

  if (!l)
    return (0);
  cur = 0;
  while (l)
    {
      t = l;
      l = t->next;
      t->prev = l;
      t->next = cur;
      cur = t;
    }
  cur->prev = 0;
  return (cur);
}
