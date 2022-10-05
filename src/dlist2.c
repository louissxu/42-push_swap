/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:39 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:39:41 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

// Pops the node with the given pointer. Assumes that the node is a valid
// pointer in the head list (otherwise bad things happen)
t_dlist	*ft_dlist_pop_at_pointer(t_dlist **head, t_dlist *node)
{
	t_dlist	*popped_node;

	if (node == *head)
	{
		popped_node = ft_dlist_pop_first(head);
		return (popped_node);
	}
	if (node->next)
	{
		node->next->prev = node->prev;
	}
	node->prev->next = node->next;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

size_t	ft_dlist_length(t_dlist *head)
{
	size_t	len;

	len = 0;
	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}
