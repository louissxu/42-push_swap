#include "push_swap.h"

// Probably remove this. This is a duplicate
int	find_distance_from_val(t_deque *stack, int val)
{
	int		distance;
	t_dlist	*stack_node;

	distance = 0;
	stack_node = stack->head;
	if (stack_node == NULL)
	{
		return (0);
	}
	while (*(int *)(stack_node->content) != val)
	{
		distance++;
		stack_node = stack_node->next;
		if (stack_node == NULL)
		{
			break;
		}
	}
	if (ft_deque_length(*stack) - distance < (size_t)distance)
	{
		distance = distance - ft_deque_length(*stack);
	}
	return (distance);
}

// Probably remove this. This is a duplicate
void	ps_pb_val(t_deque *l, t_deque *r, t_list **moves, int val)
{
	int distance;

	distance = find_distance_from_val(l, val);
	while (distance > 0)
	{
		ps_ra(l, r, moves);
		distance--;
	}
	while (distance < 0)
	{
		ps_rra(l, r, moves);
		distance++;
	}
	ps_pb(l, r, moves);
}

void	ps_sort_4_elements(t_deque *l, t_deque *r, t_list **moves)
{
	ps_pb_val(l, r, moves, 0);
	ps_sort_3_elements(l, r, moves);
	ps_pa(l, r, moves);
}