#include <stdlib.h>

#include "list.h"

t_list		*list_create(void *data)
{
  t_list	*l = malloc(sizeof(t_list));

  l->data = data;
  l->next = 0;
  return (l);
}

t_list		*list_add_first(t_list *l, void *data)
{
  t_list	*new = malloc(sizeof(t_list));

  if (!l)
    return (0);
  new->data = data;
  new->next = l;
  return (new);
}

t_list		*list_add_last(t_list *l, void *data)
{
  t_list	*new = malloc(sizeof(t_list));

  if (!l)
    return (0);
  new->data = data;
  new->next = 0;
  while (l->next)
    l = l->next;
  l->next = new;
  return (new);
}

int	list_count(t_list *l)
{
  int	i;

  if (!l)
    return (0);
  for (i = 0; l; i++)
    l = l->next;
  return (i);
}

t_list		*list_remove_first(t_list *l)
{
  t_list	*first;

  if (!l)
    return ;
  first = l->next;
  free(l);
  return (first);
}

t_list		*list_remove_last(t_list *l)
{
  t_list	*last;
  t_list	*last_last;

  if (!l)
    return ;
  if (list_count(l) == 1)
    {
      free(l);
      return (0);
    }
  last = l;
  last_last = l;
  while (last->next)
    {
      last_last = last;
      last = last->next;
    }
  last_last->next = 0;
  free(last);
  return (l);
}

t_list	*list_empty(t_list *l)
{
  if (!l)
    return ;
  list_empty(l->next);
  free(l);
  return (0);
}

t_list		*list_reverse(t_list *l)
{
  t_list	*t;
  t_list	*cur;

  if (!l)
    return (0);
  cur = 0;
  while (l)
    {
      t = l;
      l = t->next;
      t->next = cur;
      cur = t;
    }
  return (cur);
}
