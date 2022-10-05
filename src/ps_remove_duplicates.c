/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_remove_duplicates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:54 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:39:55 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
 * considered redundant and both nodes removed by ps_remove_duplicates because
 * it thinks pa will undo pb.
 *
 * Therefore, it expects skipped moves to be stripped out first.
 *
 * @param node A pointer to a dlist node containing a move string as content.
 *     The node is expected to be a node within a list of moves. Ie the node
 *     that it checks is the next node in the list.
 */
bool	node_is_redundant(t_dlist *node)
{
	if (!node)
	{
		return (false);
	}
	if (!node->next)
	{
		return (false);
	}
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
		return (true);
	}
	return (false);
}

// Deprecated
t_dlist *ps_remove_skipped(t_list *l, int stack_a_length)
{
	int	stack_b_length;
	t_list *curr;

	stack_b_length = 0;
	curr = l;
	while (curr) {
		if (ft_strncmp(curr->content, "pb", 3) == 0)
		{
			if (stack_a_length == 0) {
				// pop list element
			} else {
				stack_a_length--;
				stack_b_length++;
			}
		}
		else if (ft_strncmp(curr->content, "pa", 3) == 0)
		{
			if (stack_b_length == 0) {
				// pop list element
			} else {
				stack_a_length++;
				stack_b_length--;
			}
		}
	}
	return (NULL);
}

t_dlist	*ps_remove_duplicates(t_list *l)
{
	t_dlist	*dlist_head;
	t_dlist	*node;
	t_dlist	*prev_node;
	t_dlist	*popped_node;

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
			prev_node = node->prev;
			popped_node = ft_dlist_pop_at_pointer(&dlist_head, node->next);
			ft_dlist_destroy_node(popped_node, free);
			popped_node = ft_dlist_pop_at_pointer(&dlist_head, node);
			ft_dlist_destroy_node(popped_node, free);
			if (prev_node)
			{
				node = prev_node;
			}
			else
			{
				node = dlist_head;
			}
		}
		else
		{
			node = node->next;
		}
	}
	return (dlist_head);
}
