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
	t_ps_data	new_d;
	t_dlist		*new_moves_dlist;
	size_t		new_number_of_moves;

	new_d.a = ft_deque_clone(d->a, clone_heap_integer_void);
	new_d.b = ft_deque_clone(d->b, clone_heap_integer_void);
	new_d.m = NULL;
	new_moves_dlist = NULL;
	ps_pre_split_into_buckets(&new_d, 4, 32);
	ps_pa_all(&new_d);
	ps_split_into_buckets_double_with_reverse_rotate(&new_d, 32);
	ps_selection_sort_back_with_doubles_and_banking_low_val(&new_d, 32);
	new_moves_dlist = ps_remove_paired_moves(new_d.m);
	new_number_of_moves = ft_dlist_length(new_moves_dlist);
	ps_data_destroy(new_d);
	ft_dlist_destroy_list(new_moves_dlist, free);
	return (new_number_of_moves);
}

size_t	ps_try_500_radix_sort(t_ps_data *d)
{
	t_ps_data	new_d;
	t_dlist		*new_moves_dlist;
	size_t		new_number_of_moves;

	new_d.a = ft_deque_clone(d->a, clone_heap_integer_void);
	new_d.b = ft_deque_clone(d->b, clone_heap_integer_void);
	new_d.m = NULL;
	new_moves_dlist = NULL;
	ps_sort_double_radix_sort_improved_with_swaps(&new_d);
	new_moves_dlist = ps_remove_paired_moves(new_d.m);
	new_number_of_moves = ft_dlist_length(new_moves_dlist);
	ps_data_destroy(new_d);
	ft_dlist_destroy_list(new_moves_dlist, free);
	return (new_number_of_moves);
}

void	ps_sort_500_elements(t_ps_data *d)
{
	size_t	bracket_sort_count;
	size_t	radix_sort_count;

	bracket_sort_count = ps_try_500_bracket_sort(d);
	radix_sort_count = ps_try_500_radix_sort(d);
	if (bracket_sort_count < radix_sort_count)
	{
		ps_pre_split_into_buckets(d, 4, 32);
		ps_pa_all(d);
		ps_split_into_buckets_double_with_reverse_rotate(d, 32);
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
