/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_primitives1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:51 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:39:53 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Push_swap command - perform the move: ra (rotate a).
 *
 * On a provided ps_data struct perform a ra move.
 * ie. Shift up all elements of stack a by 1.
 * The first element then becomes the last element.
 * Then append the string name of the move to the list of moves.
 *
 * @param d The stacks to be manipulated and the list of moves to append to.
 */
void	ps_ra(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_popleft(&d->a);
	ft_deque_append(&d->a, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("ra")));
}

/**
 * @brief Push_swap command - perform the move: rb (rotate b).
 *
 * On a provided ps_data struct perform a rb move.
 * ie. Shift up all elements of stack b by 1.
 * The first element then becomes the last element.
 * Then append the string name of the move to the list of moves.
 *
 * @param d The stacks to be manipulated and the list of moves to append to.
 */
void	ps_rb(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_popleft(&d->b);
	ft_deque_append(&d->b, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("rb")));
}

/**
 * @brief Push_swap command - perform the move: rr (rotate a and b).
 *
 * On a provided ps_data struct perform a rr move.
 * ie. Do ra and rb at the same time.
 * Then append the string name of the move to the list of moves.
 *
 * @param d The stacks to be manipulated and the list of moves to append to.
 */
void	ps_rr(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_popleft(&d->a);
	ft_deque_append(&d->a, tmp);
	tmp = ft_deque_popleft(&d->b);
	ft_deque_append(&d->b, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("rr")));
}
