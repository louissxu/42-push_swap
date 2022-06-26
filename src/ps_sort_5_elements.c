#include "push_swap.h"

void	ps_sort_5_elements(t_deque *l, t_deque *r, t_list **moves)
{
	ps_pb_val(l, r, moves, 0);
	ps_pb_val(l, r, moves, 1);
	ps_sort_3_elements(l, r, moves);
	ps_pa(l, r, moves);
	ps_pa(l, r, moves);
}