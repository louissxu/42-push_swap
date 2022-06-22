#include <stdio.h>
#include "dlist.h"

typedef struct s_deque {
	t_dlist	*head;
	t_dlist	*tail;
}	t_deque;

t_deque ft_deque_new();
void	ft_deque_destroy_list(t_deque *d, void (*del)(void *));
void	ft_deque_append(t_deque *d, void *content);
void	ft_deque_appendleft(t_deque *d, void *content);
void	*ft_deque_pop(t_deque *d);
void	*ft_deque_popleft(t_deque *d);
size_t	ft_deque_length(t_deque d);