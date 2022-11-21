/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_remove_skipped.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:08:37 by lxu               #+#    #+#             */
/*   Updated: 2022/11/10 00:08:38 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Remove commands from list of moves that would be skipped
 * 
 * In a particular edge case a move is "skipped" and redundant. For example if
 * stack a contains zero elements, a pb move will do nothing, as there is no
 * element to push across from a to b. The same occurs in the mirror scenario.
 * 
 * These skipped moves can be removed for two purposes. Firstly, it is useful as
 * these moves are wasted and can be removed to reduce the move count without
 * any loss.
 * 
 * Secondly, these /must/ be removed before the redundant moves are removed. The
 * removal of redundant moves is based on pairs of moves that undo each other.
 * However this calculation is incorrect for pa/pb and pb/pa pairs if one of
 * them is skipped. Therefore it is important that there are no skipped commands
 * before ps_remove_redundant() is run. Running this function beforehand is one
 * way of achieving that.
 * 
 * NB. This is not used in the current implementation of push_swap. It is known
 * that the algorithms used will not produce these skipped redundant moves
 * therefore time is not wasted to check if any skipped moves need to be
 * removed.
 * 
 * @param cmds The list of commands to be checked and duplicated across.
 * @param stack_a_length The starting length of stack a.
 * @return The head node of a dlist containing the commands with skipped
 *   commands removed.
*/
t_dlist	*ps_remove_skipped(t_list *cmds, int stack_a_length)
{
	int		stack_b_length;
	t_deque	result_deque;

	result_deque = ft_deque_new();
	stack_b_length = 0;
	while (cmds)
	{
		if (ft_strncmp(cmds->content, "pb", 3) == 0 && stack_a_length > 0)
		{
			stack_a_length--;
			stack_b_length++;
			ft_deque_append(&result_deque, ft_strdup(cmds->content));
		}
		else if (ft_strncmp(cmds->content, "pa", 3) == 0 && stack_b_length > 0)
		{
			stack_a_length++;
			stack_b_length--;
			ft_deque_append(&result_deque, ft_strdup(cmds->content));
		}
		else if (ft_strncmp(cmds->content, "pa", 3) == 1 && \
		ft_strncmp(cmds->content, "pb", 3) == 1)
			ft_deque_append(&result_deque, ft_strdup(cmds->content));
		cmds = cmds->next;
	}
	return (result_deque.head);
}
