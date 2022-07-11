#include "push_swap.h"

int	ps_find_distance_to_value(t_deque *stack, int val)
{
	int		distance;
	t_dlist	*elem;

	distance = 0;
	elem = stack->head;
	while (elem)
	{
		if (*(int *)(elem->content) == val)
		{
			(break);
		}
		distance += 1;
		elem = elem->next;
	}
	if (elem == NULL)
	{
		return (0);
	}
	if ((long)ft_deque_length(*stack) - distance < (long)distance)
	{
		return (distance - ft_deque_length(*stack));
	}
	return (distance);
}