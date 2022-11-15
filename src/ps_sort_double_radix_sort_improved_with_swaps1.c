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

void	ps_pa_with_swap(t_ps_data *d)
{
	int	top_number;
	int	next_number;

	ps_pa(d);
	if (ft_deque_length(d->a) <= 1)
	{
		return ;
	}
	top_number = *(int *)(d->a.head->content);
	next_number = *(int *)(d->a.head->next->content);
	if (top_number / 2 == next_number / 2)
	{
		if (top_number % 2 > next_number % 2)
		{
			ps_sa(d);
		}
	}
}

void	ps_cycle_stack_and_swap(t_ps_data *d)
{
	int	top_number;
	int	next_number;
	int	i;

	i = ft_deque_length(d->a);
	if (i < 2)
		return ;
	while (i > 0)
	{
		top_number = *(int *)(d->a.head->content);
		next_number = *(int *)(d->a.head->next->content);
		if (top_number / 2 == next_number / 2)
		{
			if (top_number % 2 > next_number % 2)
				ps_sa(d);
			ps_ra(d);
			ps_ra(d);
			i -= 2;
		}
		else
		{
			ps_ra(d);
			i--;
		}
	}
}

void	ps_sa_if_helpful(t_ps_data *d)
{
	int	top_number;
	int	next_number;

	if (ft_deque_length(d->a) <= 1)
	{
		return ;
	}
	top_number = *(int *)(d->a.head->content);
	next_number = *(int *)(d->a.head->next->content);
	if (top_number / 2 == next_number / 2)
	{
		if (top_number % 2 > next_number % 2)
		{
			ps_sa(d);
		}
	}
}

void	ps_sa_bottom_if_helpful(t_ps_data *d)
{
	int	bottom_number;
	int	above_bottom_number;

	if (ft_deque_length(d->a) <= 1)
	{
		return ;
	}
	bottom_number = *(int *)(d->a.tail->content);
	above_bottom_number = *(int *)(d->a.tail->prev->content);
	if (bottom_number / 2 == above_bottom_number / 2)
	{
		if (above_bottom_number % 2 > bottom_number % 2)
		{
			ps_rra(d);
			ps_rra(d);
			ps_sa(d);
			ps_ra(d);
			ps_ra(d);
		}
	}
}

void	ps_spin_and_pb_if_radix_is_value(t_ps_data *d, int radix_val)
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
			ps_ra(d);
		}
		i--;
	}
}
