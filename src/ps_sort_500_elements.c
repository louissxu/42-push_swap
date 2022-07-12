#include "push_swap.h"

// void	ps_pre_split_into_buckets(t_deque *l, t_deque *r, t_list **moves, int num_pre_groups, int num_groups)
void	ps_pre_split_into_buckets(t_ps_data *d, int num_pre_groups, int num_groups)
{
	int	group_size;
	int	groups_per_pre_group;
	int	high_cut;
	int	low_cut;
	int	i;

	// Clean up. this should be able to be done with math rather than walking up and down the block sizes
	group_size = (ft_deque_length(d->l) + num_groups - 1) / num_groups;
	groups_per_pre_group = (num_groups + num_pre_groups - 1) / num_pre_groups;
	high_cut = ft_deque_length(d->l) - (group_size * groups_per_pre_group / 2);
	low_cut = high_cut;
	while (low_cut > 0)
	{
		low_cut -= group_size * groups_per_pre_group / 2;
	}
	low_cut += group_size * groups_per_pre_group / 2;
	while (low_cut < high_cut)
	{
		low_cut += group_size * groups_per_pre_group / 2;
		high_cut -= group_size * groups_per_pre_group / 2;
	}
	low_cut -= group_size * groups_per_pre_group / 2;
	high_cut += group_size * groups_per_pre_group / 2;
	while (d->l.head)
	{
		i = ft_deque_length(d->l);
		while (i > 0)
		{
			// Check this value. Should it be <= or < and >= or >. I cant remember if it should include or not the edges
			if (*(int *)(d->l.head->content) > low_cut && (*(int *)(d->l.head->content) <= high_cut))
			{
				ps_pb(&d->l, &d->r, &d->m);
			}
			else
			{
				ps_ra(&d->l, &d->r, &d->m);
			}
			i--;
		}
		high_cut += group_size * groups_per_pre_group / 2;
		low_cut -= group_size * groups_per_pre_group / 2;
	}
}

int	ps_deque_contains_value_in_range(t_deque *stack, int low, int high)
{
	t_dlist	*node;

	node = stack->head;
	while (node)
	{
		if (low <= *(int *)(node->content) && *(int *)(node->content) <= high)
		{
			return (1);
		}
		else
		{
			node = node->next;
		}
	}
	return (0);
}

int	ps_is_forward_closer_to_value_range(t_deque *stack, int low, int high)
{
	t_dlist	*forward;
	t_dlist	*reverse;

	if (low <= *(int *)(stack->head->content) && *(int *)(stack->head->content) <= high)
	{
		return (1);
	}
	forward = stack->head;
	reverse = stack->tail;
	while (forward && reverse)
	{
		if (low <= *(int *)(forward->content) && *(int *)(forward->content) <= high)
		{
			return (1);
		}
		if (low <= *(int *)(reverse->content) && *(int *)(reverse->content) <= high)
		{
			return (0);
		}
		if (forward == reverse)
		{
			break;
		}
		if (forward->next == reverse)
		{
			break;
		}
		forward = forward->next;
		reverse = reverse->prev;
	}
	return (1);
}

void	ps_split_into_buckets_double_with_reverse_rotate(t_ps_data *d, int num_groups)
{
	int	group_size;
	int	high_high;
	int	low_low;

	group_size = (ft_deque_length(d->l) + num_groups - 1) / num_groups;
	high_high = (num_groups / 2 * group_size) + group_size;
	low_low = (num_groups / 2 * group_size) - group_size;
	while (d->l.head)
	{
		while (ps_deque_contains_value_in_range(&d->l, low_low, high_high) == 1)
		{
			if (high_high - group_size <= *(int *)(d->l.head->content) && *(int *)(d->l.head->content) <= high_high)
			{
				ps_pb(&d->l, &d->r, &d->m);
			}
			else if (low_low <= *(int *)(d->l.head->content) && *(int *)(d->l.head->content) <= low_low + group_size)
			{
				ps_pb(&d->l, &d->r, &d->m);
				ps_rb(&d->l, &d->r, &d->m);
			}
			else
			{
				if (ps_is_forward_closer_to_value_range(&d->l, low_low, high_high))
				{
					ps_ra(&d->l, &d->r, &d->m);
				}
				else
				{
					ps_rra(&d->l, &d->r, &d->m);
				}
			}
		}
		high_high += group_size;
		low_low -= group_size;
	}
}

void	ps_pa_val_optimal_with_banking(t_deque *l, t_deque *r, t_list **moves, int current_target, int *low_target)
{
	int	distance_target;

	if (*(int *)r->head->content == current_target)
	{
		ps_pa(l, r, moves);
		return ;
	}
	distance_target = ps_find_distance_to_value(r, current_target);
	while (*(int *)r->head->content != current_target)
	{
		if (*(int *)r->head->content == *low_target && *low_target < current_target - 1)
		{
			ps_pa(l, r, moves);
			ps_ra(l, r, moves);
			*low_target += 1;
		}
		else if (distance_target > 0)
		{
			ps_rb(l, r, moves);
			distance_target -= 1;
		}
		else if (distance_target < 0)
		{
			ps_rrb(l, r, moves);
			distance_target += 1;
		}
		else
		{
			;
		}
	}
	ps_pa(l, r, moves);
}

void	ps_selection_sort_back_with_doubles_and_banking_low_val(t_ps_data *d, int num_groups)
{
	int	group_size;
	int	bracket_low_bound;
	int	current_target;
	int	next_target;
	int	low_target;

	group_size = (ft_deque_length(d->r) + num_groups - 1) / num_groups;
	bracket_low_bound = ft_deque_length(d->r) - group_size;
	current_target = ft_deque_length(d->r) - 1;
	low_target = bracket_low_bound;
	while (d->r.head)
	{
		next_target = current_target - 1;
		if (next_target < 0)
		{
			next_target = 0;
		}
		// if (bracket_low_bound < 0)
		// {
		// 	bracket_low_bound = 0;
		// }
		if (ft_math_abs(ps_find_distance_to_value(&d->r, current_target)) <= ft_math_abs(ps_find_distance_to_value(&d->r, next_target)) || current_target == next_target || next_target < low_target)
		{
			ps_pa_val_optimal_with_banking(&d->l, &d->r, &d->m, current_target, &low_target);
			current_target -= 1;
		}
		else
		{
			ps_pa_val_optimal_with_banking(&d->l, &d->r, &d->m, next_target, &low_target);
			ps_pa_val_optimal_with_banking(&d->l, &d->r, &d->m, current_target, &low_target);
			ps_sa(&d->l, &d->r, &d->m);
			current_target -= 2;
		}
		if (low_target > current_target)
		{
			while (low_target > bracket_low_bound)
			{
				ps_rra(&d->l, &d->r, &d->m);
				low_target -= 1;
			}
			current_target = bracket_low_bound - 1;
			bracket_low_bound -= group_size;
			if (bracket_low_bound < 0)
			{
				bracket_low_bound = 0;
			}
			low_target = bracket_low_bound;
		}
	}
}

t_deque	ft_deque_clone(t_deque d, void *(clone_element)(void *))
{
	t_deque	cloned_deque;
	t_dlist	*d_node;

	cloned_deque = ft_deque_new();
	d_node = d.head;
	while (d_node)
	{
		ft_deque_append(&cloned_deque, clone_element(d_node->content));
		d_node = d_node->next;
	}
	return (cloned_deque);
}

size_t	ps_try_500_bracket_sort(t_ps_data *d)
{
	t_dlist	*new_moves_dlist;
	size_t	new_number_of_moves;

	t_ps_data	new_d;

	new_d.l = ft_deque_clone(d->l, clone_heap_integer_void);
	new_d.r = ft_deque_clone(d->r, clone_heap_integer_void);
	new_d.m = NULL;
	new_moves_dlist = NULL;

	ps_pre_split_into_buckets(&new_d, 4, 32);
	ps_pa_all(&new_d.l, &new_d.r, &new_d.m);
	ps_split_into_buckets_double_with_reverse_rotate(&new_d, 32);
	ps_selection_sort_back_with_doubles_and_banking_low_val(&new_d, 32);
	new_moves_dlist = ps_remove_duplicates(new_d.m);
	new_number_of_moves = ft_dlist_length(new_moves_dlist);

	ft_deque_destroy_list(&new_d.l, free);
	ft_deque_destroy_list(&new_d.r, free);
	ft_lstclear(&new_d.m, free);
	ft_dlist_destroy_list(new_moves_dlist, free);

	return new_number_of_moves;
}

size_t	ps_try_500_radix_sort(t_deque *l, t_deque *r, t_list **moves)
{
	t_deque	new_l;
	t_deque	new_r;
	t_list	*new_moves;
	t_dlist	*new_moves_dlist;
	size_t	new_number_of_moves;

	UNUSED(moves);
	new_l = ft_deque_clone(*l, clone_heap_integer_void);
	new_r = ft_deque_clone(*r, clone_heap_integer_void);
	new_moves = NULL;
	new_moves_dlist = NULL;

	ps_sort_double_radix_sort_improved_with_swaps(&new_l, &new_r, &new_moves);
	new_moves_dlist = ps_remove_duplicates(new_moves);
	new_number_of_moves = ft_dlist_length(new_moves_dlist);

	ft_deque_destroy_list(&new_l, free);
	ft_deque_destroy_list(&new_r, free);
	ft_lstclear(&new_moves, free);
	ft_dlist_destroy_list(new_moves_dlist, free);

	return new_number_of_moves;
}

void	ps_sort_500_elements(t_ps_data *d)
{
	size_t	bracket_sort_count;
	size_t	radix_sort_count;

	bracket_sort_count = ps_try_500_bracket_sort(d);
	radix_sort_count = ps_try_500_radix_sort(&d->l, &d->r, &d->m);

	// if (1)
	if (bracket_sort_count < radix_sort_count)
	{
		ps_pre_split_into_buckets(d, 4, 32);
		// ps_pre_split_into_buckets(&d->l, &d->r, &d->m, 4, 32);
		ps_pa_all(&d->l, &d->r, &d->m);
		ps_split_into_buckets_double_with_reverse_rotate(d, 32);
		// ps_selection_sort_back_with_doubles(l, r, moves);
		ps_selection_sort_back_with_doubles_and_banking_low_val(d, 32);
	}
	else
	{
		ps_sort_double_radix_sort_improved_with_swaps(&d->l, &d->r, &d->m);
	}
}

	// first bucket	second bucket	min		ave		max
	// 4				32				5050	5150	5250
	// 4				28??			5000	5100	5200
	// 4				36??			5050	5100	5150
	// 4				16-40			others are bad
	// 3				30				4975	5100	5150
	// 2				20				4850	5050	5200