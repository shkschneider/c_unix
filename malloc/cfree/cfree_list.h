#ifndef _CFREE_LIST_H_
# define _CFREE_LIST_H_

typedef struct s_cfree
{
  char * info;
  void * data;
  size_t size;
  struct s_cfree * prev;
  struct s_cfree * next;
} t_cfree;

t_cfree * cfree_list_create(void *, size_t, char *);
t_cfree * cfree_list_add_first(t_cfree *, void *, size_t, char *);
int cfree_list_count(t_cfree *);

#endif /* !_CFREE_LIST_H_ */
