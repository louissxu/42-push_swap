/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_double_radix_sort_improved_with_s          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:40:12 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:40:13 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_spin_and_pb_if_radix_is_value_and_sa_bottom(t_ps_data *d, \
	int radix_val)
{
	int	i;

	i = ft_deque_length(d->a);
	while (i > 0)
	{
		if (*(int *)(d->a.head->content) / ft_pow(2, radix_val) % 2 == 0)
		{
			ps_pb(d);
		}
		else
		{
			ps_sa_bottom_if_helpful(d);
			ps_ra(d);
			ps_sa_bottom_if_helpful(d);
		}
		i--;
	}
}

void	ps_pa_with_swap_for_count_of_values(t_ps_data *d, int count)
{
	int	i;

	i = count;
	while (i > 0)
	{
		ps_pa_with_swap(d);
		i--;
	}
}

void	ps_spin_and_pa_if_radix_is_not_value(t_ps_data *d, int radix_val)
{
	int	i;

	i = ft_deque_length(d->b);
	while (i > 0)
	{
		if (*(int *)(d->b.head->content) / ft_pow(2, radix_val) % 2 != 0)
		{
			ps_pa_with_swap(d);
		}
		else
		{
			ps_rb(d);
		}
		i--;
	}
}

void	ps_pa_with_swap_all(t_ps_data *d)
{
	int	i;

	i = ft_deque_length(d->b);
	while (i > 0)
	{
		ps_pa_with_swap(d);
		i--;
	}
}

void	ps_spin_and_pb_if_radix_is_value_and_all_sa_bottom(t_ps_data *d, \
	int radix_val)
{
	int	i;

	i = ft_deque_length(d->a);
	while (i > 0)
	{
		if (*(int *)(d->a.head->content) / ft_pow(2, radix_val) % 2 == 0)
		{
			ps_sa_bottom_if_helpful(d);
			ps_pb(d);
			ps_sa_bottom_if_helpful(d);
		}
		else
		{
			ps_sa_bottom_if_helpful(d);
			ps_ra(d);
			ps_sa_bottom_if_helpful(d);
		}
		i--;
	}
}

