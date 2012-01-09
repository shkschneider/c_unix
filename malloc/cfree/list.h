#ifndef _CFREE_LIST_H_
# define _CFREE_LIST_H_

struct s_cfree
{
  char * info;
  void * data;
  size_t size;
  struct s_cfree * prev;
  struct s_cfree * next;
};

struct s_cfree_c
{
  int cmalloc;
  int crealloc;
  int ccalloc;
  int cfree;
};

# ifndef CFREE_INFO_MAX
#  define CFREE_INFO_MAX 64
# endif /* !CFREE_INFO_MAX */

struct s_cfree * cfree_list_add_first(char *, void *, size_t);
int cfree_list_count(void);

#endif /* !_CFREE_LIST_H_ */
