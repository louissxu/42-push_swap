/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:37 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:39:38 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	*ft_deque_popleft(t_deque *d)
{
	t_dlist	*node;
	void	*content;
	t_dlist	*next_node;

	next_node = d->head->next;
	node = ft_dlist_pop_first(&d->head);
	if (!node)
	{
		return (NULL);
	}
	content = node->content;
	d->head = next_node;
	free(node);
	if (d->head == NULL)
	{
		d->tail = NULL;
	}
	return (content);
}

size_t	ft_deque_length(t_deque d)
{
	return (ft_dlist_length(d.head));
}
