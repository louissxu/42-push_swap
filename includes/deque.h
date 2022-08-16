#ifndef DEQUE_H

# include <stdlib.h>
# include "dlist.h"

/**
 * @struct t_deque
 * A double ended queue
 *
 * A double ended queue. Consists of a double ended list. Stores the pointers to
 * the head and tail of the deque for fast (constant time) access/modification
 * to either end of the queue.
 *
 * @var t_deque::head
 *     Pointer to the head of the deque. NULL if the deque is empty.
 * @var t_deque::tail
 *     Pointer to the tail of the deque. NULL if the deque is empty.
 */
typedef struct s_deque {
	t_dlist	*head;
	t_dlist	*tail;
}	t_deque;

t_deque	ft_deque_new(void);
void	ft_deque_destroy_list(t_deque *d, void (*del)(void *));
void	ft_deque_append(t_deque *d, void *content);
void	ft_deque_appendleft(t_deque *d, void *content);
void	*ft_deque_pop(t_deque *d);
void	*ft_deque_popleft(t_deque *d);
size_t	ft_deque_length(t_deque d);

#endif