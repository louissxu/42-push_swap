#include "push_swap.h"

void	ps_sort_2_elements(t_deque *l, t_deque *r, t_list **moves)
{
	// if (ft_intcmp(l->head->content, 0) == 0)
	if (*(int *)(l->head->content) == 0)
	{
		;
	}
	else
	{
		ps_sa(l, r, moves);
	}
}