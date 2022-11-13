/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_100_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:56 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:39:57 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Push across if a value is within the bracket, otherwise spin
 * 
 * Within a ps_data dataset, checks if the top value is in either the high or
 * low bracket and pushes it across. If it's in low bracket it pushes it across
 * and rotates it to the bottom.
 * 
 * @param d The ps_data struct to work on.
 * @param high_low The lower end of the high bracket.
 * @param low_high The higher end of the low bracket.
 * @param group_size The size of the brackets.
*/
static void	ps_push_bracketed(t_ps_data *d, \
	int high_low, int low_high, int group_size)
{
	if (high_low <= *(int *)(d->a.head->content) && \
		*(int *)(d->a.head->content) < high_low + group_size)
	{
		ps_pb(d);
	}
	else if (low_high - group_size <= *(int *)(d->a.head->content) && \
		*(int *)(d->a.head->content) < low_high)
	{
		ps_pb(d);
		ps_rb(d);
	}
	else
	{
		ps_ra(d);
	}
}

/**
 * @brief Single pass selection sort into bracketed ranges
 * 
 * Spins through stack a. While spinning sorts across to stack b into bracketed
 * groups. Eg for range 0-99, might sort into groups 0-24, 25-49, 5-74, 75-99.
 * 
 * To make it more efficient, this sorts double sided. It starts from the middle
 * then sorts around the middle. That way it can simultaneously be looking for
 * two values while it spins. If it is the lower value, it will push it across
 * then rotate it onto the other side.
 * 
 * Sorts in-place.
 * 
 * Notes:
 * Divide but round up
 * Ref: https://stackoverflow.com/a/4846569/9160572
 * 
 * @param d The ps_data to work on.
 * @param num_groups The number of groups to sort the data into.
*/
void	ps_selection_sort_into_brackets_twin_sided(t_ps_data *d, int num_groups)
{
	int	group_size;
	int	high_low;
	int	low_high;
	int	i;

	group_size = (ft_deque_length(d->a) + num_groups - 1) / num_groups;
	high_low = num_groups / 2 * group_size;
	low_high = high_low;
	while (d->a.head)
	{
		i = ft_deque_length(d->a);
		while (i > 0)
		{
			ps_push_bracketed(d, high_low, low_high, group_size);
			i--;
		}
		high_low += group_size;
		low_high -= group_size;
	}
}

/**
 * @brief Push across two numbers, put them in order, and reset target value
 * 
 * Internal subroutine of ps_selection_sort_back_with_doubles. It pushes across
 * the two next terms, puts them in the correct order, and sets the target value
 * appropriately (two less)
 * 
 * @param d The ps_data to be operated on.
 * @param current_target The current target value. Passed by reference so that
 *   it can be modified down to the next target value.
 * @param 
*/
static void	ps_push_two_numbers(t_ps_data *d, \
	int *current_target, int next_target)
{
	ps_pa_value_optimal(d, next_target);
	ps_pa_value_optimal(d, *current_target);
	ps_sa(d);
	*current_target -= 2;
}

/**
 * @brief Select back while searching for doubles
 * 
 * Selection sort back from stack b to stack a in order. As an efficiency
 * optimisation, it searches for the next two values. If it can efficiently do
 * so it pulls the second value, then the first value, then switches them so
 * that it can search for two numbers simultaneously.
 * 
 * @param d The ps_data instance to act on.
*/
static void	ps_selection_sort_back_with_doubles(t_ps_data *d)
{
	int	current_target;
	int	next_target;
	int	distance_target;
	int	distance_next_target;

	current_target = ft_deque_length(d->b) - 1;
	while (d->b.head)
	{
		next_target = current_target - 1;
		if (next_target < 0)
			next_target = 0;
		distance_target = ps_find_distance_to_value(&d->b, current_target);
		distance_next_target = ps_find_distance_to_value(&d->b, next_target);
		if (ft_math_abs(distance_target) < ft_math_abs(distance_next_target) \
			|| current_target == next_target)
		{
			ps_pa_value_optimal(d, current_target);
			current_target--;
		}
		else
			ps_push_two_numbers(d, &current_target, next_target);
	}
}

/**
 * @brief Sort 100 elements
 * 
 * Efficiently sorts 100 elements.
 * 
 * Pushes elements from stack a to b selection sorted into brackets. Then
 * selection sorts the elements back from b to a in the final sorted order.
 * 
 * @param d The ps_data instance to act on.
*/
void	ps_sort_100_elements(t_ps_data *d)
{
	ps_selection_sort_into_brackets_twin_sided(d, 8);
	ps_selection_sort_back_with_doubles(d);
}
