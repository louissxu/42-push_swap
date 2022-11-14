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

static void	ps_pa_val_internal(t_ps_data *d, int *low_target, \
	int current_target, int *distance_target)
{
	if (*(int *)d->b.head->content == *low_target && \
		*low_target < current_target - 1)
	{
		ps_pa(d);
		ps_ra(d);
		*low_target += 1;
	}
	else if (distance_target > 0)
	{
		ps_rb(d);
		*distance_target -= 1;
	}
	else if (distance_target < 0)
	{
		ps_rrb(d);
		*distance_target += 1;
	}
	else
	{
	}
}

void	ps_pa_val_optimal_with_banking(t_ps_data *d, int current_target, \
	int *low_target)
{
	int	distance_target;

	if (*(int *)d->b.head->content == current_target)
	{
		ps_pa(d);
		return ;
	}
	distance_target = ps_find_distance_to_value(&d->b, current_target);
	while (*(int *)d->b.head->content != current_target)
	{
		ps_pa_val_internal(d, low_target, current_target, &distance_target);
	}
	ps_pa(d);
}

void	ps_selection_sort_back_with_doubles_and_banking_low_val_1( \
	t_ps_data *d, int *current_target, int *low_target)
{
	int	next_target;

	next_target = *current_target - 1;
	if (next_target < 0)
	{
		next_target = 0;
	}
	if (ft_math_abs(ps_find_distance_to_value(&d->b, *current_target)) <= \
		ft_math_abs(ps_find_distance_to_value(&d->b, next_target)) || \
		*current_target == next_target || next_target < *low_target)
	{
		ps_pa_val_optimal_with_banking(d, *current_target, low_target);
		*current_target -= 1;
	}
	else
	{
		ps_pa_val_optimal_with_banking(d, next_target, low_target);
		ps_pa_val_optimal_with_banking(d, *current_target, low_target);
		ps_sa(d);
		*current_target -= 2;
	}
}

void	ps_selection_sort_back_with_doubles_and_banking_low_val_2( \
	t_ps_data *d, int *low_target, int bracket_low_bound)
{
	while (*low_target > bracket_low_bound)
	{
		ps_rra(d);
		*low_target -= 1;
	}
}

void	ps_selection_sort_back_with_doubles_and_banking_low_val(t_ps_data *d, \
	int num_groups)
{
	int	group_size;
	int	bracket_low_bound;
	int	current_target;
	int	low_target;

	group_size = (ft_deque_length(d->b) + num_groups - 1) / num_groups;
	bracket_low_bound = ft_deque_length(d->b) - group_size;
	current_target = ft_deque_length(d->b) - 1;
	low_target = bracket_low_bound;
	while (d->b.head)
	{
		ps_selection_sort_back_with_doubles_and_banking_low_val_1(d, \
			&current_target, &low_target);
		if (low_target > current_target)
		{
			ps_selection_sort_back_with_doubles_and_banking_low_val_2(d, \
				&low_target, bracket_low_bound);
			current_target = bracket_low_bound - 1;
			bracket_low_bound -= group_size;
			if (bracket_low_bound < 0)
				bracket_low_bound = 0;
			low_target = bracket_low_bound;
		}
	}
}
