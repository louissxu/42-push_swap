/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_remove_paired_moves.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:54 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:39:55 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Internal checks for node_is_redundant function
 * 
 * Exists due to norm function line limit.
 * 
 * @see node_is_redundant()
*/
static BOOL	node_is_redundant_1(t_dlist *node)
{
	if ((ft_strncmp(node->content, "pb", 3) == 0 && \
			ft_strncmp(node->next->content, "pa", 3) == 0) || \
		(ft_strncmp(node->content, "pa", 3) == 0 && \
			ft_strncmp(node->next->content, "pb", 3) == 0) || \
		(ft_strncmp(node->content, "ra", 3) == 0 && \
			ft_strncmp(node->next->content, "rra", 4) == 0) || \
		(ft_strncmp(node->content, "rra", 4) == 0 && \
			ft_strncmp(node->next->content, "ra", 3) == 0) || \
		(ft_strncmp(node->content, "rb", 3) == 0 && \
			ft_strncmp(node->next->content, "rrb", 4) == 0) || \
		(ft_strncmp(node->content, "rrb", 4) == 0 && \
			ft_strncmp(node->next->content, "rb", 3) == 0))
	{
		return (TRUE);
	}
	return (FALSE);
}

/**
 * @brief Internal checks for node_is_redundant function
 * 
 * Exists due to norm function line limit.
 * 
 * @see node_is_redundant()
*/
static BOOL	node_is_redundant_2(t_dlist *node)
{
	if ((ft_strncmp(node->content, "sa", 3) == 0 && \
			ft_strncmp(node->next->content, "sa", 3) == 0) || \
		(ft_strncmp(node->content, "sb", 3) == 0 && \
			ft_strncmp(node->next->content, "sb", 3) == 0) || \
		(ft_strncmp(node->content, "ss", 3) == 0 && \
			ft_strncmp(node->next->content, "ss", 3) == 0) || \
		(ft_strncmp(node->content, "rr", 3) == 0 && \
			ft_strncmp(node->next->content, "rrr", 4) == 0) || \
		(ft_strncmp(node->content, "rrr", 4) == 0 && \
			ft_strncmp(node->next->content, "rr", 3) == 0))
	{
		return (TRUE);
	}
	return (FALSE);
}

/**
 * @brief Checks if node is redundant
 * 
 * Checks if a node is is redundant. A node is redundant when it does an action
 * but the next action does the inverse of it. Therefore, after the two actions
 * the state is the same and two moves were wasted.
 *
 * NB: This will behave incorrectly in the edge case where a pa (or pb) move is
 * "skipped" due to an empty list. Consider - a: [], b: [1, 2], moves: [pb, pa]
 * Correct state after the moves will be a: [1], b: [2]. But the moves will be
 * considered redundant and both nodes removed by ps_remove_paired_moves because
 * it thinks pa will undo pb.
 *
 * Therefore, it requires skipped moves to be stripped out first.
 *
 * @param node A pointer to a dlist node containing a move string as content.
 *     The node is expected to be a node within a list of moves. Ie the node
 *     that it checks is the next node in the list.
 */
BOOL	node_is_redundant(t_dlist *node)
{
	if (!node)
	{
		return (FALSE);
	}
	if (!node->next)
	{
		return (FALSE);
	}
	if (node_is_redundant_1(node) || node_is_redundant_2(node))
	{
		return (TRUE);
	}
	return (FALSE);
}

/**
 * @brief Subroutine to remove a node and reset the associated pointers
 * 
 * Subroutine of ps_remove_paired_moves. This removes the node and moves the
 * pointers as necessary.
 * 
 * @see ps_remove_paired_moves()
 * @param dlist_head The head of the dlist being modified.
 * @param node A pointer to the node that is being popped. The pointer must
 *   point to a node in the dlist being modified.
*/
static void	pop_node_and_reset_pointer(t_dlist **dlist_head, t_dlist **node)
{
	t_dlist	*prev_node;
	t_dlist	*popped_node;

	prev_node = (*node)->prev;
	popped_node = ft_dlist_pop_at_pointer(dlist_head, (*node)->next);
	ft_dlist_destroy_node(popped_node, free);
	popped_node = ft_dlist_pop_at_pointer(dlist_head, (*node));
	ft_dlist_destroy_node(popped_node, free);
	if (prev_node)
	{
		(*node) = prev_node;
	}
	else
	{
		(*node) = (*dlist_head);
	}
}

/**
 * @brief Removes paired moves that are redundant
 * 
 * Checks if moves in a list of moves are redundant pairs. Moves are a redundant
 * pair when a move has an subsequent move that would undo that action and
 * therefore the pair of moves do nothing (eg pa/pb, or ra/rra, etc). This
 * function walks through the list and removes these redundant pairs.
 * 
 * @param l A list of moves to be checked.
 * @returns A dlist cloned with these same moves but with paired moves removed.
*/
t_dlist	*ps_remove_paired_moves(t_list *l)
{
	t_dlist	*dlist_head;
	t_dlist	*node;

	dlist_head = ft_list_to_dlist(l, clone_heap_integer_void);
	node = dlist_head;
	if (!node)
	{
		return (dlist_head);
	}
	if (!node->next)
	{
		return (dlist_head);
	}
	while (node->next)
	{
		if (node_is_redundant(node))
		{
			pop_node_and_reset_pointer(&dlist_head, &node);
		}
		else
		{
			node = node->next;
		}
	}
	return (dlist_head);
}
