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

t_dlist	*ft_dlist_new_node(void *content)
{
	t_dlist	*node;

	node = malloc(sizeof (*node) * 1);
	if (!node)
	{
		return (NULL);
	}
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_dlist_destroy_node(t_dlist *node, void (*del)(void *))
{
	if (!node | !del)
	{
		return ;
	}
	del(node->content);
	free(node);
	return ;
}

void	ft_dlist_destroy_list(t_dlist *head, void (*del)(void *))
{
	t_dlist	*next;

	if (!head | !del)
	{
		return ;
	}
	while (head)
	{
		next = head->next;
		ft_dlist_destroy_node(head, del);
		head = next;
	}
	return ;
}

t_dlist	*ft_dlist_get_last(t_dlist *head)
{
	if (!head)
	{
		return (NULL);
	}
	while (head->next)
	{
		head = head->next;
	}
	return (head);
}

void	ft_dlist_remove_first(t_dlist **head, void (*del)(void *))
{
	t_dlist	*curr;
	t_dlist	*prev;

	if (!head | !del)
	{
		return ;
	}
	if (!*head)
	{
		return ;
	}
	curr = *head;
	prev = curr;
	curr = curr->next;
	ft_dlist_destroy_node(prev, del);
	if (curr == NULL)
	{
		*head = NULL;
		return ;
	}
	curr->prev = NULL;
	*head = curr;
	return ;
}
