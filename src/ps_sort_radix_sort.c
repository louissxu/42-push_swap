/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_radix_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:40:14 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:40:15 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_deque *stack)
{
	t_dlist *node;

	if (ft_deque_length(*stack) <= 1)
	{
		return (1);
	}
	node = stack->head;
	while (node->next)
	{
		if (ft_intcmp(node->content, node->next->content) > 0)
		{
			return (0);
		}
		node = node->next;
	}
	return (1);
}

// void	ps_sort_radix_sort(t_ps_data *d)
void ps_sort_radix_sort(t_ps_data *d)
{
	int radix;
	int i;
	int max_i;

	radix = 0;
	while (is_sorted(&d->a) == 0)
	{
		i = 0;
		max_i = ft_deque_length(d->a);
		while (i < max_i)
		{
			if (*(int *)(d->a.head->content) / ft_math_pow(2, radix) % 2 == 0)
			{
				ps_pb(d);
			}
			else
			{
				ps_ra(d);
			}
			i++;
		}
		while (d->b.head)
		{
			ps_pa(d);
		}
		radix++;
	}
}
