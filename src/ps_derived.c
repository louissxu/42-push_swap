/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_derived.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:49 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:39:51 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Push_swap move. An "efficient" pa for a particular value in the stack.
 *
 * Searches the stack for the value and rotates to that via the optimal
 * direction (forward or reverse, whichever is the shorter number of moves).
 *
 * Nb. Does /not/ check for the existance of the value within the stack. It will
 * just push the top element if the value does not exist in the stack.
 *
 * @param d The stacks to perform the moves on and the moves list to append to.
 * @param value The value being searched for to be pushed across.
 */
void	ps_pa_value_optimal(t_ps_data *d, int value)
{
	int	distance;

	distance = ps_find_distance_to_value(&d->b, value);
	while (distance > 0)
	{
		ps_rb(d);
		distance--;
	}
	while (distance < 0)
	{
		ps_rrb(d);
		distance++;
	}
	ps_pa(d);
}

/**
 * @brief Push_swap move. pa, but for all elements in the stack.
 *
 * Pushes all elements in the stack from b to a.
 *
 * @param d The stacks to perform the moves on and the moves list to append to.
 */
void	ps_pa_all(t_ps_data *d)
{
	while (d->b.head)
	{
		ps_pa(d);
	}
}

/**
 * @brief Push_swap move. An "efficient" pb for a particular value in the stack.
 *
 * Same as ps_pa_value_optimal but for stack b.
 *
 * @see ps_pa_value_optimal()
 * @param d The stacks to perform the moves on and the moves list to append to.
 * @param value The value being searche for to be pushed across.
 */
void	ps_pb_value_optimal(t_ps_data *d, int value)
{
	int	distance;

	distance = ps_find_distance_to_value(&d->a, value);
	while (distance > 0)
	{
		ps_ra(d);
		distance--;
	}
	while (distance < 0)
	{
		ps_rra(d);
		distance++;
	}
	ps_pb(d);
}
