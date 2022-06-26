#include "push_swap.h"

static int	check_if_first_three_deque_nodes_match(t_deque *d, int e0, int e1, int e2)
{
	t_dlist	*node;

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

void	ps_sort_3_elements(t_deque *l, t_deque *r, t_list **moves)
{
	t_deque	l_clone;

	l_clone = clone_deque(l);
	normalise_in_place(&l_clone);

	if (check_if_first_three_deque_nodes_match(&l_clone, 0, 1, 2) == 1)
		;
	else if (check_if_first_three_deque_nodes_match(&l_clone, 1, 0, 2) == 1)
		ps_sa(l, r, moves);
	else if (check_if_first_three_deque_nodes_match(&l_clone, 2, 1, 0) == 1)
	{
		ps_sa(l, r, moves);
		ps_rra(l, r, moves);
	}
	else if (check_if_first_three_deque_nodes_match(&l_clone, 2, 0, 1) == 1)
		ps_ra(l, r, moves);
	else if (check_if_first_three_deque_nodes_match(&l_clone, 0, 2, 1) == 1)
	{
		ps_sa(l, r, moves);
		ps_ra(l, r, moves);
	}
	else if (check_if_first_three_deque_nodes_match(&l_clone, 1, 2, 0) == 1)
		ps_rra(l, r, moves);
	ft_deque_destroy_list(&l_clone, free);
	UNUSED(r);
	UNUSED(moves);
}