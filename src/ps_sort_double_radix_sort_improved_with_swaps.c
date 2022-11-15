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

static void	ps_sort_radix_sort_one_radix(t_ps_data *d, int radix)
{
	ps_spin_and_pb_if_radix_is_value_and_all_sa_bottom(d, radix);
	ps_pa_with_swap_all(d);
}

static void	ps_sort_radix_sort_two_radix(t_ps_data *d, int radix)
{
	int	a_first_buffer_length;

	ps_spin_and_pb_if_radix_is_value(d, radix + 1);
	a_first_buffer_length = ft_deque_length(d->b);
	ps_spin_and_pb_if_radix_is_value_and_sa_bottom(d, radix);
	ps_pa_with_swap_for_count_of_values(d,
		ft_deque_length(d->b) - a_first_buffer_length);
	ps_spin_and_pa_if_radix_is_not_value(d, radix);
	ps_pa_with_swap_all(d);
}

void	ps_sort_double_radix_sort_improved_with_swaps(t_ps_data *d)
{
	int	radix;
	int	max_radix;

	radix = 1;
	max_radix = calculate_max_radix(ft_deque_length(d->a));
	while (radix < max_radix)
	{
		if (radix + 1 < max_radix)
		{
			ps_sort_radix_sort_two_radix(d, radix);
			radix += 2;
		}
		else
		{
			ps_sort_radix_sort_one_radix(d, radix);
			radix += 1;
		}
	}
}
