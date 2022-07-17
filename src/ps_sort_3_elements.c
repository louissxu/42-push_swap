#include "push_swap.h"

static int check_if_first_three_deque_nodes_match(t_deque *d, int e0, int e1, int e2)
{
	t_dlist *node;

	node = d->head;
	if (ft_intcmp(node->content, &e0) != 0)
	{
		return (0);
	}
	node = node->next;
	if (ft_intcmp(node->content, &e1) != 0)
	{
		return (0);
	}
	node = node->next;
	if (ft_intcmp(node->content, &e2) != 0)
	{
		return (0);
	}
	return (1);
}

void ps_sort_3_elements(t_ps_data *d)
{
	t_deque l_clone;

	l_clone = ft_clone_deque(d->a, clone_heap_integer_void);
	normalise_in_place(&l_clone);
	if (check_if_first_three_deque_nodes_match(&l_clone, 0, 1, 2) == 1)
		;
	else if (check_if_first_three_deque_nodes_match(&l_clone, 1, 0, 2) == 1)
		ps_sa(d);
	else if (check_if_first_three_deque_nodes_match(&l_clone, 2, 1, 0) == 1)
	{
		ps_sa(d);
		ps_rra(d);
	}
	else if (check_if_first_three_deque_nodes_match(&l_clone, 2, 0, 1) == 1)
		ps_ra(d);
	else if (check_if_first_three_deque_nodes_match(&l_clone, 0, 2, 1) == 1)
	{
		ps_sa(d);
		ps_ra(d);
	}
	else if (check_if_first_three_deque_nodes_match(&l_clone, 1, 2, 0) == 1)
		ps_rra(d);
	ft_deque_destroy_list(&l_clone, free);
}