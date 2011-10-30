#include <stdio.h>

#include "bilist.h"

void	bilist_print(t_bilist *l)
{
  if (!l)
    return ;
  if (!(l->prev))
    printf("%d: 0x%x       < 0x%X > 0x%x\n", l->data, l->prev, l, l->next);
  else
    printf("%d: 0x%x < 0x%X > 0x%x\n", l->data, l->prev, l, l->next);
  bilist_print(l->next);
}

int		main(void)
{
  t_bilist	*l;

  printf("creating\n");
  l = bilist_create((void *)1);
  printf("adding as last\n");
  bilist_add_last(l, (void *)2);
  bilist_add_last(l, (void *)3);
  bilist_add_last(l, (void *)4);
  bilist_print(l);
  putchar('\n');
  printf("adding as first\n");
  l = bilist_add_first(l, (void *)0);
  bilist_print(l);
  putchar('\n');
  printf("reverse\n");
  l = bilist_reverse(l);
  bilist_print(l);
  putchar('\n');
  printf("remove first\n");
  l = bilist_remove_first(l);
  bilist_print(l);
  putchar('\n');
  printf("remove last\n");
  l = bilist_remove_last(l);
  bilist_print(l);
  putchar('\n');
  printf("remove last\n");
  l = bilist_remove_last(l);
  bilist_print(l);
  putchar('\n');
  printf("remove last\n");
  l = bilist_remove_last(l);
  bilist_print(l);
  putchar('\n');
  printf("remove all\n");
  l = bilist_empty(l);
  return (0);
}
