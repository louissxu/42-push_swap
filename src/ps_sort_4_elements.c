#include "push_swap.h"

// // Probably remove this. This is a duplicate
// int	find_distance_from_val(t_deque *stack, int val)
// {
// 	int		distance;
// 	t_dlist	*stack_node;

// 	distance = 0;
// 	stack_node = stack->head;
// 	if (stack_node == NULL)
// 	{
// 		return (0);
// 	}
// 	while (*(int *)(stack_node->content) != val)
// 	{
// 		distance++;
// 		stack_node = stack_node->next;
// 		if (stack_node == NULL)
// 		{
// 			break ;
// 		}
// 	}
// 	if (ft_deque_length(*stack) - distance < (size_t)distance)
// 	{
// 		distance = distance - ft_deque_length(*stack);
// 	}
// 	return (distance);
// }

void	ps_sort_4_elements(t_ps_data *d)
{
	ps_pb_value_optimal(d, 0);
	ps_sort_3_elements(d);
	ps_pa(d);
}
