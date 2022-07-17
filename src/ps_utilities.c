#include "push_swap.h"

/**
 * @brief Calculate optimal rotate distance in a stack to a value
 * 
 * In a given stack. Calculate whether it is closer to go forward (rotate moves)
 * or backwards (reverse rotate moves) to get to a value being searched for. If
 * it's the same, it prefers forward. If it doesnt exist, it returns 0 (note
 * also returns 0 if the value is at the zero position - ie top of the stack).
 * 
 * @param stack The stack to search for the value
 * @param val The value being searched for
 * @return int The distance to the value (positive for ra/b, negative for rra/b)
 */
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
			break ;
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