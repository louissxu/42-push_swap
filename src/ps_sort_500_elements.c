/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_500_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:40:04 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:40:05 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_pre_split_into_buckets(t_ps_data *d, int num_pre_groups, int num_groups)
{
	int group_size;
	int groups_per_pre_group;
	int high_cut;
	int low_cut;
	int i;

	group_size = (ft_deque_length(d->a) + num_groups - 1) / num_groups;
	groups_per_pre_group = (num_groups + num_pre_groups - 1) / num_pre_groups;
	groups_per_pre_group = (groups_per_pre_group + 1) / 2 * 2;

	low_cut = ft_deque_length(d->a) - (num_groups / 2 * group_size) - (groups_per_pre_group / 2 * group_size);
	high_cut = low_cut + (group_size * groups_per_pre_group);

	while (d->a.head)
	{
		i = ft_deque_length(d->a);
		while (i > 0)
		{
			if (low_cut <= *(int *)(d->a.head->content) && (*(int *)(d->a.head->content) < high_cut))
			{
				ps_pb(d);
			}
			else
			{
				ps_ra(d);
			}
			i--;
		}
		high_cut += groups_per_pre_group / 2 * group_size;
		low_cut -= groups_per_pre_group / 2 * group_size;
	}
}

int ps_deque_contains_value_in_range(t_deque *stack, int low, int high)
{
	t_dlist *node;

	node = stack->head;
	while (node)
	{
		if (low <= *(int *)(node->content) && *(int *)(node->content) < high)
		{
			// ft_printf("the number is %i\n", *(int *)(node->content));
			return (1);
		}
		else
		{
			node = node->next;
		}
	}
	return (0);
}

int ps_is_forward_closer_to_value_range(t_deque *stack, int low, int high)
{
	t_dlist *forward;
	t_dlist *reverse;

	if (low <= *(int *)(stack->head->content) && *(int *)(stack->head->content) < high)
	{
		return (1);
	}
	forward = stack->head;
	reverse = stack->tail;
	while (forward && reverse)
	{
		if (low <= *(int *)(forward->content) && *(int *)(forward->content) < high)
		{
			return (1);
		}
		if (low <= *(int *)(reverse->content) && *(int *)(reverse->content) < high)
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

void ps_split_into_buckets_double_with_reverse_rotate(t_ps_data *d, int num_groups)
{
	int group_size;
	int high_high;
	int low_low;

	group_size = (ft_deque_length(d->a) + num_groups - 1) / num_groups;
	high_high = ft_deque_length(d->a) - (num_groups / 2 * group_size) + group_size;
	low_low = ft_deque_length(d->a) - (num_groups / 2 * group_size) - group_size;
	while (d->a.head)
	{
		while (ps_deque_contains_value_in_range(&d->a, low_low, high_high) == 1)
		{
			if (high_high - group_size <= *(int *)(d->a.head->content) && *(int *)(d->a.head->content) < high_high)
			{
				ps_pb(d);
			}
			else if (low_low <= *(int *)(d->a.head->content) && *(int *)(d->a.head->content) < low_low + group_size)
			{
				ps_pb(d);
				ps_rb(d);
			}
			else
			{
				if (ps_is_forward_closer_to_value_range(&d->a, low_low, high_high))
				{
					ps_ra(d);
				}
				else
				{
					ps_rra(d);
				}
			}
		}
		high_high += group_size;
		low_low -= group_size;
	}
}

void ps_pa_val_optimal_with_banking(t_ps_data *d, int current_target, int *low_target)
{
	int distance_target;

	if (*(int *)d->b.head->content == current_target)
	{
		ps_pa(d);
		return;
	}
	distance_target = ps_find_distance_to_value(&d->b, current_target);
	while (*(int *)d->b.head->content != current_target)
	{
		if (*(int *)d->b.head->content == *low_target && *low_target < current_target - 1)
		{
			ps_pa(d);
			ps_ra(d);
			*low_target += 1;
		}
		else if (distance_target > 0)
		{
			ps_rb(d);
			distance_target -= 1;
		}
		else if (distance_target < 0)
		{
			ps_rrb(d);
			distance_target += 1;
		}
		else
		{
			;
		}
	}
	ps_pa(d);
}

void ps_selection_sort_back_with_doubles_and_banking_low_val(t_ps_data *d, int num_groups)
{
	int group_size;
	int bracket_low_bound;
	int current_target;
	int next_target;
	int low_target;

	group_size = (ft_deque_length(d->b) + num_groups - 1) / num_groups;
	bracket_low_bound = ft_deque_length(d->b) - group_size;
	current_target = ft_deque_length(d->b) - 1;
	low_target = bracket_low_bound;
	while (d->b.head)
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
		if (ft_math_abs(ps_find_distance_to_value(&d->b, current_target)) <= ft_math_abs(ps_find_distance_to_value(&d->b, next_target)) || current_target == next_target || next_target < low_target)
		{
			ps_pa_val_optimal_with_banking(d, current_target, &low_target);
			current_target -= 1;
		}
		else
		{
			ps_pa_val_optimal_with_banking(d, next_target, &low_target);
			ps_pa_val_optimal_with_banking(d, current_target, &low_target);
			ps_sa(d);
			current_target -= 2;
		}
		if (low_target > current_target)
		{
			while (low_target > bracket_low_bound)
			{
				ps_rra(d);
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

t_deque ft_deque_clone(t_deque d, void *(clone_element)(void *))
{
	t_deque cloned_deque;
	t_dlist *d_node;

	cloned_deque = ft_deque_new();
	d_node = d.head;
	while (d_node)
	{
		ft_deque_append(&cloned_deque, clone_element(d_node->content));
		d_node = d_node->next;
	}
	return (cloned_deque);
}

size_t ps_try_500_bracket_sort(t_ps_data *d)
{
	t_dlist *new_moves_dlist;
	size_t new_number_of_moves;

	t_ps_data new_d;

	new_d.a = ft_deque_clone(d->a, clone_heap_integer_void);
	new_d.b = ft_deque_clone(d->b, clone_heap_integer_void);
	new_d.m = NULL;
	new_moves_dlist = NULL;

	ps_pre_split_into_buckets(&new_d, 4, 32);
	ps_pa_all(&new_d);
	ps_split_into_buckets_double_with_reverse_rotate(&new_d, 32);
	ps_selection_sort_back_with_doubles_and_banking_low_val(&new_d, 32);
	new_moves_dlist = ps_remove_duplicates(new_d.m);
	new_number_of_moves = ft_dlist_length(new_moves_dlist);

	ft_deque_destroy_list(&new_d.a, free);
	ft_deque_destroy_list(&new_d.b, free);
	ft_lstclear(&new_d.m, free);
	ft_dlist_destroy_list(new_moves_dlist, free);

	return new_number_of_moves;
}

size_t ps_try_500_radix_sort(t_ps_data *d)
{
	t_ps_data new_d;
	t_dlist *new_moves_dlist;
	size_t new_number_of_moves;

	new_d.a = ft_deque_clone(d->a, clone_heap_integer_void);
	new_d.b = ft_deque_clone(d->b, clone_heap_integer_void);
	new_d.m = NULL;
	new_moves_dlist = NULL;

	ps_sort_double_radix_sort_improved_with_swaps(&new_d);
	new_moves_dlist = ps_remove_duplicates(new_d.m);
	new_number_of_moves = ft_dlist_length(new_moves_dlist);

	ft_deque_destroy_list(&new_d.a, free);
	ft_deque_destroy_list(&new_d.b, free);
	ft_lstclear(&new_d.m, free);
	ft_dlist_destroy_list(new_moves_dlist, free);

	return new_number_of_moves;
}

void ps_sort_500_elements(t_ps_data *d)
{
	size_t bracket_sort_count;
	size_t radix_sort_count;

	bracket_sort_count = ps_try_500_bracket_sort(d);
	radix_sort_count = ps_try_500_radix_sort(d);

	// if (1)
	if (bracket_sort_count < radix_sort_count)
	{
		ps_pre_split_into_buckets(d, 4, 32);
		// ps_pre_split_into_buckets(&d->a, &d->b, &d->m, 4, 32);
		ps_pa_all(d);
		ps_split_into_buckets_double_with_reverse_rotate(d, 32);
		// ps_selection_sort_back_with_doubles(d);
		ps_selection_sort_back_with_doubles_and_banking_low_val(d, 32);
	}
	else
	{
		ps_sort_double_radix_sort_improved_with_swaps(d);
	}
}

// first bucket	second bucket	min		ave		max
// 4				32				5050	5150	5250
// 4				28??			5000	5100	5200
// 4				36??			5050	5100	5150
// 4				16-40			others are bad
// 3				30				4975	5100	5150
// 2				20				4850	5050	5200
