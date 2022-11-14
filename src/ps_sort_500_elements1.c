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

void	ps_pre_split_into_buckets(t_ps_data *d, int num_pre_grps, int num_grps)
{
	int	group_size;
	int	g_per_pre_g;
	int	high_cut;
	int	low_cut;
	int	i;

	group_size = (ft_deque_length(d->a) + num_grps - 1) / num_grps;
	g_per_pre_g = ((num_grps + num_pre_grps - 1) / num_pre_grps) + 1 / 2 * 2;
	low_cut = ft_deque_length(d->a) - (num_grps / 2 * group_size) - \
		(g_per_pre_g / 2 * group_size);
	high_cut = low_cut + (group_size * g_per_pre_g);
	while (d->a.head)
	{
		i = ft_deque_length(d->a) + 1;
		while (--i > 0)
		{
			if (low_cut <= *(int *)(d->a.head->content) && \
				(*(int *)(d->a.head->content) < high_cut))
				ps_pb(d);
			else
				ps_ra(d);
		}
		high_cut += g_per_pre_g / 2 * group_size;
		low_cut -= g_per_pre_g / 2 * group_size;
	}
}

int	ps_deque_contains_value_in_range(t_deque *stack, int low, int high)
{
	t_dlist	*node;

	node = stack->head;
	while (node)
	{
		if (low <= *(int *)(node->content) && *(int *)(node->content) < high)
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
	t_dlist	*fwd;
	t_dlist	*rev;

	if (low <= *(int *)(stack->head->content) && \
		*(int *)(stack->head->content) < high)
	{
		return (1);
	}
	fwd = stack->head;
	rev = stack->tail;
	while (fwd && rev)
	{
		if (low <= *(int *)(fwd->content) && *(int *)(fwd->content) < high)
			return (1);
		if (low <= *(int *)(rev->content) && *(int *)(rev->content) < high)
			return (0);
		if (fwd == rev)
			break ;
		if (fwd->next == rev)
			break ;
		fwd = fwd->next;
		rev = rev->prev;
	}
	return (1);
}

static void	ps_push_bracketed(t_ps_data *d, \
	int high_high, int low_low, int grp_size)
{
	if (high_high - grp_size <= *(int *)(d->a.head->content) && \
		*(int *)(d->a.head->content) < high_high)
	{
		ps_pb(d);
	}
	else if (low_low <= *(int *)(d->a.head->content) && \
		*(int *)(d->a.head->content) < low_low + grp_size)
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

void	ps_split_into_buckets_double_with_reverse_rotate(t_ps_data *d, \
	int num_groups)
{
	int	grp_size;
	int	high_high;
	int	low_low;

	grp_size = (ft_deque_length(d->a) + num_groups - 1) / num_groups;
	high_high = ft_deque_length(d->a) - (num_groups / 2 * grp_size) + grp_size;
	low_low = ft_deque_length(d->a) - (num_groups / 2 * grp_size) - grp_size;
	while (d->a.head)
	{
		while (ps_deque_contains_value_in_range(&d->a, low_low, high_high) == 1)
		{
			ps_push_bracketed(d, high_high, low_low, grp_size);
		}
		high_high += grp_size;
		low_low -= grp_size;
	}
}
