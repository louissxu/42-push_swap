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

t_deque	ft_deque_new(void)
{
	t_deque	d;

	d.head = NULL;
	d.tail = NULL;
	return (d);
}

void	ft_deque_destroy_list(t_deque *d, void (*del)(void *))
{
	ft_dlist_destroy_list(d->head, del);
	d->head = NULL;
	d->tail = NULL;
}

// Design choice: appending and popping expects and returns the content void *
//     rather than the dlist node itself.
// Advantage: No need to remember to create and breakdown the intermediary dlist
//     nodes.
// Disadvantage: Moving an element from bottom to top (or vice versa) involves a
//     free then malloc of a node rather than moving the node directly.
void	ft_deque_append(t_deque *d, void *content)
{
	t_dlist	*node;

	node = ft_dlist_new_node(content);
	if (!node)
	{
		return ;
	}
	ft_dlist_insert_end(&d->tail, node);
	if (d->head == NULL)
	{
		d->head = node;
	}
	d->tail = node;
}

void	ft_deque_appendleft(t_deque *d, void *content)
{
	t_dlist	*node;

	node = ft_dlist_new_node(content);
	if (!node)
	{
		return ;
	}
	ft_dlist_insert_start(&d->head, node);
	if (d->tail == NULL)
	{
		d->tail = node;
	}
}

void	*ft_deque_pop(t_deque *d)
{
	t_dlist	*node;
	void	*content;
	t_dlist	*prev_node;

	prev_node = d->tail->prev;
	node = ft_dlist_pop_last(&d->tail);
	if (!node)
	{
		return (NULL);
	}
	content = node->content;
	d->tail = prev_node;
	free(node);
	if (d->tail == NULL)
	{
		d->head = NULL;
	}
	return (content);
}
