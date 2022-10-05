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

/**
 * @brief Compare two integers and return the difference between them
 *
 * Compares two integers when passed the pointer to them (likely heap integers).
 * Returns the difference between them.
 * Needs to return a long in case *i1 is a large positive and *i2 is a large
 * negative.
 *
 * @param i1 Pointer to the first integer.
 * @param i2 Pointer to the second integer.
 * @returns long The difference between i2 and i2.
 */
long	ft_intcmp(const	int *i1, int *i2)
{
	return ((long)*i1 - *i2);
}

/**
 * @brief Swap the content of two list nodes
 * 
 * @param node_1 First node to swap
 * @param node_2 Second node to swap
 */
static void	list_swap_content(t_list *node_1, t_list *node_2)
{
	void	*temp_content;

	temp_content = node_1->content;
	node_1->content = node_2->content;
	node_2->content = temp_content;
}

/**
 * @brief In-place bubble sort of a list
 * 
 * An implementation of an bubble sort of a list containing heap integers
 * as content
 * 
 * As a design decision, it swaps the /content pointers/ within the list rather
 * than swapping the entire list nodes themselves.
 * 
 * @param l The head of the list to be sorted
 * @return t_list* Returns the head of the list
 */

t_list	*list_sort_bubble_sort(t_list *l)
{
	int	unsorted_element_count;
	int swapped;
	t_list	*node;
	int		node_i;

	unsorted_element_count = ft_lstsize(l);
	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		node = l;
		node_i = 0;
		while (node_i < unsorted_element_count - 1)
		{
			if (ft_intcmp(node->content, node->next->content) > 0)
			{
				list_swap_content(node, node->next);
				swapped = 1;
			}
			node_i++;
			node = node->next;
		}
	}
	return (l);
}

t_deque	*ps_normalise_in_place(t_deque *d)
{
	t_list	*sorted_list_head;
	int		i;
	t_dlist	*d_node;
	t_list	*sorted_list_node;

	sorted_list_head = list_sort_bubble_sort(ft_deque_to_list(*d, clone_heap_integer_void, free));
	d_node = d->head;
	while (d_node != NULL)
	{
		i = 0;
		sorted_list_node = sorted_list_head;
		while (ft_intcmp(sorted_list_node->content, d_node->content) != 0)
		{
			i++;
			sorted_list_node = sorted_list_node->next;
		}
		*(int *)(d_node->content) = i;
		d_node = d_node->next;
	}
	ft_lstclear(&sorted_list_head, free);
	return (d);
}