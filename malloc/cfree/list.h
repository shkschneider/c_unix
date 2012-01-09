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

# define ALLOC (gl_cfree_c.cmalloc + gl_cfree_c.crealloc + gl_cfree_c.ccalloc)
# define MALLOC (gl_cfree_c.cmalloc)
# define REALLOC (gl_cfree_c.crealloc)
# define CALLOC (gl_cfree_c.ccalloc)
# define FREE (gl_cfree_c.cfree)

# ifndef CFREE_INFO_MAX
#  define CFREE_INFO_MAX 64
# endif /* !CFREE_INFO_MAX */

struct s_cfree * cfree_list_add_first(char *, void *, size_t);
int cfree_list_count(void);

#endif /* !_CFREE_LIST_H_ */
