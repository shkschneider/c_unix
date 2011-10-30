#ifndef _LIST_H_
# define _LIST_H_

typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
}		t_list;

t_list	*list_create(void *);
t_list	*list_add_first(t_list *, void *);
t_list	*list_add_last(t_list *, void *);
int	list_count(t_list *);
t_list	*list_remove_first(t_list *);
t_list	*list_remove_last(t_list *);
t_list	*list_empty(t_list *);
t_list	*list_reverse(t_list *);

#endif /* !_LIST_H_ */
