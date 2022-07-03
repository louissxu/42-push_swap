#include "push_swap.h"

void	ps_pre_split_into_buckets(t_deque *l, t_deque *r, t_list **moves, int num_pre_groups, int num_groups)
{
	int	group_size;
	int	groups_per_pre_group;
	int	high_cut;
	int	low_cut;
	int	i;

	group_size = (ft_deque_length(*l) + num_groups - 1) / num_groups;
	groups_per_pre_group = (num_groups + num_pre_groups - 1) / num_pre_groups;

	high_cut = ft_deque_length(*l) - (group_size * groups_per_pre_group / 2);
	low_cut = group_size * groups_per_pre_group / 2;

	while (l->head)
	{
		i = ft_deque_length(*l);
		while (i > 0)
		{
			if (*(int *)(l->head->content) <= low_cut || (*(int *)(l->head->content) >= high_cut))
			{
				ps_pb(l, r, moves);
			}
			else
			{
				ps_ra(l, r, moves);
			}
			i--;
		}
		high_cut -= group_size * groups_per_pre_group / 2;
		low_cut += group_size * groups_per_pre_group / 2;
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

void	ps_split_into_buckets_double_with_reverse_rotate(t_deque *l, t_deque *r, t_list **moves, int num_groups)
{
	int	group_size;
	int	high_high;
	int	low_low;

	group_size = (ft_deque_length(*l) + num_groups - 1) / num_groups;
	high_high = (num_groups / 2 * group_size) + group_size;
	low_low = (num_groups / 2 * group_size) - group_size;

	while (l->head)
	{
		while (ps_deque_contains_value_in_range(l, low_low, high_high) == 1)
		{
			if (high_high - group_size <= *(int *)(l->head->content) && *(int *)(l->head->content) <= high_high)
			{
				ps_pb(l, r, moves);
			}
			else if (low_low <= *(int *)(l->head->content) && *(int *)(l->head->content) <= low_low + group_size)
			{
				ps_pb(l, r, moves);
				ps_rb(l, r, moves);
			}
			else
			{
				if (ps_is_forward_closer_to_value_range(l, low_low, high_high))
				{
					ps_ra(l, r, moves);
				}
				else
				{
					ps_rra(l, r, moves);
				}
			}
		}
		high_high += group_size;
		low_low -= group_size;
	}
}

void	ps_sort_500_elements(t_deque *l, t_deque *r, t_list **moves)
{
	ps_pre_split_into_buckets(l, r, moves, 4, 32);
	ps_pa_all(l, r, moves);
	ps_split_into_buckets_double_with_reverse_rotate(l, r, moves, 32);
	ps_selection_sort_back_with_doubles(l, r, moves);
}