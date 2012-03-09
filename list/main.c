#include <stdio.h>

#include "list.h"

void list_print(t_list *l)
{
  if (!l)
    return ;
  printf("%d: 0x%X > 0x%x\n", l->data, l, l->next);
  list_print(l->next);
}

int main(void)
{
  t_list *l = NULL;

  printf("creating\n");
  l = list_create((void *)1);
  printf("adding as last\n");
  list_add_last(l, (void *)2);
  list_add_last(l, (void *)3);
  list_add_last(l, (void *)4);
  list_print(l);
  putchar('\n');
  printf("adding as first\n");
  l = list_add_first(l, (void *)0);
  list_print(l);
  putchar('\n');
  printf("reverse\n");
  l = list_reverse(l);
  list_print(l);
  putchar('\n');
  printf("remove last\n");
  l = list_remove_last(l);
  list_print(l);
  putchar('\n');
  printf("remove first\n");
  l = list_remove_first(l);
  list_print(l);
  putchar('\n');
  printf("remove last\n");
  l = list_remove_last(l);
  list_print(l);
  putchar('\n');
  printf("remove last\n");
  l = list_remove_last(l);
  list_print(l);
  putchar('\n');
  printf("remove last\n");
  l = list_remove_last(l);
  list_print(l);
  putchar('\n');
  printf("remove all\n");
  l = list_empty(l);
  return (0);
}
