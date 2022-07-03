#include "push_swap.h"

void	ps_pa_value_optimal(t_deque *l, t_deque *r, t_list **moves, int value)
{
	int	distance;

	distance = ps_find_distance_to_value(r, value);
	while (distance > 0)
	{
		ps_rb(l, r, moves);
		distance--;
	}
	while (distance < 0)
	{
		ps_rrb(l, r, moves);
		distance++;
	}
	ps_pa(l, r, moves);
}

void	ps_pa_all(t_deque *l, t_deque *r, t_list **moves)
{
	while (r->head)
	{
		ps_pa(l, r, moves);
	}
}