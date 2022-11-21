/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_double_radix_sort.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:40:08 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:40:09 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_sort_double_radix_sort(t_ps_data *d)
{
	int radix;
	int max_radix;
	int i;
	int max_i;
	int r_first_buffer_length;

	radix = 0;
	max_radix = calculate_max_radix(ft_deque_length(d->a));
	while (radix < max_radix)
	{
		max_i = ft_deque_length(d->a);
		i = 0;
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
		radix++;
		if (radix < max_radix)
		{
			r_first_buffer_length = ft_deque_length(d->b);
			max_i = ft_deque_length(d->a);
			i = 0;
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
			i = 0;
			max_i = ft_deque_length(d->b) - r_first_buffer_length;
			while (i < max_i)
			{
				ps_rb(d);
				i++;
			}
			i = 0;
			while (i < r_first_buffer_length)
			{
				if (*(int *)(d->b.head->content) / ft_math_pow(2, radix) % 2 != 0)
				{
					ps_pa(d);
				}
				else
				{
					ps_rb(d);
				}
				i++;
			}
		}
		i = 0;
		max_i = ft_deque_length(d->b);
		while (i < max_i)
		{
			ps_pa(d);
			i++;
		}
		radix += 1;
	}
}
