/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_primitives2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:51 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:39:53 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Push_swap command - perform the move: rra (reverse rotate a).
 *
 * On a provided ps_data struct perform a rra move.
 * ie. Shift down all elements of stack a by 1.
 * The last element then becomes the first element.
 * Then append the string name of the move to the list of moves.
 *
 * @param d The stacks to be manipulated and the list of moves to append to.
 */
void	ps_rra(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_pop(&d->a);
	ft_deque_appendleft(&d->a, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("rra")));
}

/**
 * @brief Push_swap command - perform the move: rrb (reverse rotate b).
 *
 * On a provided ps_data struct perform a rrb move.
 * ie. Shift down all elements of stack b by 1.
 * The last element then becomes the first element.
 * Then append the string name of the move to the list of moves.
 *
 * @param d The stacks to be manipulated and the list of moves to append to.
 */
void	ps_rrb(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_pop(&d->b);
	ft_deque_appendleft(&d->b, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("rrb")));
}

/**
 * @brief Push_swap command - perform the move: rrr (reverse rotate a and b).
 *
 * On a provided ps_data struct perform a rrr move.
 * ie. Do rra and rrb at the same time.
 * Then append the string name of the move to the list of moves.
 *
 * @param d The stacks to be manipulated and the list of moves to append to.
 */
void	ps_rrr(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_pop(&d->a);
	ft_deque_appendleft(&d->a, tmp);
	tmp = ft_deque_pop(&d->b);
	ft_deque_appendleft(&d->b, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("rrr")));
}
