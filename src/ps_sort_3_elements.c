/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_3_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:40:00 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:40:01 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks if first three deque nodes match
 * 
 * Takes a deque, checks if the values of the first three nodes are equal to the
 * three values passed in as parameters.
 * 
 * NB. Does not check past the first three deque nodes. Therefore it will return
 * a 1 if the first three nodes match but potentially subsequent nodes do not.
 * 
 * @param d Pointer to the deque.
 * @param e0 First integer.
 * @param e1 Second integer.
 * @param e2 Third integer.
 * @returns 1 (true) if all three integers matched. 0 (false) if any of the
 *     three integers do not match.
*/
static int	check_if_three_deque_nodes_match(t_deque *d, int e0, int e1, int e2)
{
	t_dlist	*node;

	node = d->head;
	if (ft_intcmp(node->content, &e0) != 0)
	{
		return (0);
	}
	node = node->next;
	if (ft_intcmp(node->content, &e1) != 0)
	{
		return (0);
	}
	node = node->next;
	if (ft_intcmp(node->content, &e2) != 0)
	{
		return (0);
	}
	return (1);
}

/**
 * @brief Sorts a three element push swap puzzle
 * 
 * Checks the value of the first three nodes. Depending on the value, outputs an
 * optimal sequence to sort the list.
 * 
 * @param d Pointer to a set of push swap data.
*/
void	ps_sort_3_elements(t_ps_data *d)
{
	t_deque	l_clone;

	l_clone = ft_clone_deque(d->a, clone_heap_integer_void);
	ps_normalise_in_place(&l_clone);
	if (check_if_three_deque_nodes_match(&l_clone, 0, 1, 2) == 1)
		;
	else if (check_if_three_deque_nodes_match(&l_clone, 1, 0, 2) == 1)
		ps_sa(d);
	else if (check_if_three_deque_nodes_match(&l_clone, 2, 1, 0) == 1)
	{
		ps_sa(d);
		ps_rra(d);
	}
	else if (check_if_three_deque_nodes_match(&l_clone, 2, 0, 1) == 1)
		ps_ra(d);
	else if (check_if_three_deque_nodes_match(&l_clone, 0, 2, 1) == 1)
	{
		ps_sa(d);
		ps_ra(d);
	}
	else if (check_if_three_deque_nodes_match(&l_clone, 1, 2, 0) == 1)
		ps_rra(d);
	ft_deque_destroy_list(&l_clone, free);
}
