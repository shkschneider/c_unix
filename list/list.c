#include <stdlib.h>

#include "list.h"

t_list *list_create(void *data)
{
  t_list *l = malloc(sizeof(t_list));

  l->data = data;
  l->next = NULL;
  return (l);
}

t_list *list_add_first(t_list *l, void *data)
{
  t_list *new = malloc(sizeof(t_list));

  if (!l)
    return (NULL);
  new->data = data;
  new->next = l;
  return (new);
}

t_list *list_add_last(t_list *l, void *data)
{
  t_list *new = malloc(sizeof(t_list));

  if (!l)
    return (NULL);
  new->data = data;
  new->next = NULL;
  while (l->next)
    l = l->next;
  l->next = new;
  return (new);
}

int list_count(t_list *l)
{
  int i;

  if (!l)
    return (0);
  for (i = 0; l; i++)
    l = l->next;
  return (i);
}

t_list *list_remove_first(t_list *l)
{
  t_list *first;

  if (!l)
    return (NULL);
  first = l->next;
  free(l);
  return (first);
}

t_list *list_remove_last(t_list *l)
{
  t_list *last = NULL;
  t_list *last_last = NULL;

  if (!l)
    return (NULL);
  if (list_count(l) == 1)
    {
      free(l);
      return (NULL);
    }
  last = l;
  last_last = l;
  while (last->next)
    {
      last_last = last;
      last = last->next;
    }
  last_last->next = NULL;
  free(last);
  return (l);
}

t_list	*list_clear(t_list *l)
{
  if (!l)
    return (NULL);
  list_empty(l->next);
  free(l);
  return (NULL);
}

t_list *list_reverse(t_list *l)
{
  t_list *t = NULL;
  t_list *cur = NULL;

  if (!l)
    return (NULL);
  cur = NULL;
  while (l)
    {
      t = l;
      l = t->next;
      t->next = cur;
      cur = t;
    }
  return (cur);
}
