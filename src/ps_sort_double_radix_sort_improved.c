/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_double_radix_sort_improved.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:40:10 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:40:11 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_sort_double_radix_sort_improved(t_ps_data *d)
{
	int radix;
	int max_radix;
	int i;
	int r_first_buffer_length;

	radix = 0;
	max_radix = calculate_max_radix(ft_deque_length(d->a));
	while (radix < max_radix)
	{
		if (radix + 1 < max_radix)
		{
			i = ft_deque_length(d->a);
			while (i > 0)
			{
				if (*(int *)(d->a.head->content) / ft_pow(2, radix + 1) % 2 == 0)
				{
					ps_pb(d);
				}
				else
				{
					ps_ra(d);
				}
				i--;
			}
			r_first_buffer_length = ft_deque_length(d->b);
			i = ft_deque_length(d->a);
			while (i > 0)
			{
				if (*(int *)(d->a.head->content) / ft_pow(2, radix) % 2 == 0)
				{
					ps_pb(d);
				}
				else
				{
					ps_ra(d);
				}
				i--;
			}
			i = ft_deque_length(d->b) - r_first_buffer_length;
			while (i > 0)
			{
				ps_pa(d);
				i--;
			}
			i = ft_deque_length(d->b);
			while (i > 0)
			{
				if (*(int *)(d->b.head->content) / ft_pow(2, radix) % 2 != 0)
				{
					ps_pa(d);
				}
				else
				{
					ps_rb(d);
				}
				i--;
			}
			i = ft_deque_length(d->b);
			while (i > 0)
			{
				ps_pa(d);
				i--;
			}
			radix += 2;
		}
		else
		{
			i = ft_deque_length(d->a);
			while (i > 0)
			{
				if (*(int *)(d->a.head->content) / ft_pow(2, radix) % 2 == 0)
				{
					ps_pb(d);
				}
				else
				{
					ps_ra(d);
				}
				i--;
			}
			i = ft_deque_length(d->b);
			while (i > 0)
			{
				ps_pa(d);
				i--;
			}
			radix += 1;
		}
	}
}
