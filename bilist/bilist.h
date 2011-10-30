#ifndef _BILIST_H_
# define _BILIST_H_

typedef struct		s_bilist
{
  void			*data;
  struct s_bilist	*prev;
  struct s_bilist	*next;
}			t_bilist;

t_bilist	*bilist_create(void *);
t_bilist	*bilist_add_first(t_bilist *, void *);
t_bilist	*bilist_add_last(t_bilist *, void *);
int		bilist_count(t_bilist *);
t_bilist	*bilist_remove_first(t_bilist *);
t_bilist	*bilist_remove_last(t_bilist *);
t_bilist	*bilist_empty(t_bilist *);
t_bilist	*bilist_reverse(t_bilist *);

#endif /* !_BILIST_H_ */
