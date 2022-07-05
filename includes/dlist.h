#ifndef DLIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_dlist {
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

t_dlist	*ft_dlist_new_node(void *content); 
void	ft_dlist_destroy_node(t_dlist *node, void (*del)(void *));
void	ft_dlist_destroy_list(t_dlist *head, void (*del)(void *)); 
t_dlist *ft_dlist_get_last(t_dlist *head);
void	ft_dlist_remove_first(t_dlist **head, void (*del)(void *));
void	ft_dlist_remove_last(t_dlist **head, void (*del)(void *));
void	ft_dlist_insert_start(t_dlist **head, t_dlist *new_node);
void	ft_dlist_insert_end(t_dlist **head, t_dlist *new_node);
t_dlist *ft_dlist_pop_first(t_dlist **head);
t_dlist *ft_dlist_pop_last(t_dlist **head);
t_dlist	*ft_dlist_pop_at_pointer(t_dlist **head, t_dlist *node);
size_t	ft_dlist_length(t_dlist *head);

#endif