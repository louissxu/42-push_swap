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

void	ft_dlist_remove_last(t_dlist **head, void (*del)(void *))
{
	t_dlist	*last;
	t_dlist	*prev;

	if (!head | !del)
	{
		return ;
	}
	if (!*head)
	{
		return ;
	}
	last = ft_dlist_get_last(*head);
	prev = last->prev;
	ft_dlist_destroy_node(last, del);
	if (prev == NULL)
	{
		*head = NULL;
		return ;
	}
	prev->next = NULL;
	return ;
}

void	ft_dlist_insert_start(t_dlist **head, t_dlist *new_node)
{
	if (!head | !new_node)
	{
		return ;
	}
	if (!*head)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
		return ;
	}
	new_node->next = *head;
	new_node->prev = NULL;
	(*head)->prev = new_node;
	*head = new_node;
	return ;
}

void	ft_dlist_insert_end(t_dlist **head, t_dlist *new_node)
{
	t_dlist	*last;

	if (!head | !new_node)
	{
		return ;
	}
	if (!*head)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
		return ;
	}
	last = ft_dlist_get_last(*head);
	last->next = new_node;
	new_node->next = NULL;
	new_node->prev = last;
	return ;
}

t_dlist	*ft_dlist_pop_first(t_dlist **head)
{
	t_dlist	*node;

	if (!head)
	{
		return (NULL);
	}
	if (!*head)
	{
		return (NULL);
	}
	node = *head;
	*head = (*head)->next;
	node->next = NULL;
	if (*head)
	{
		(*head)->prev = NULL;
	}
	return (node);
}

t_dlist *ft_dlist_pop_last(t_dlist **head)
{
	t_dlist	*node;

	if (!head)
	{
		return (NULL);
	}
	if (!*head)
	{
		return (NULL);
	}
	node = ft_dlist_get_last(*head);
	if (node->prev == NULL)
	{
		*head = NULL;
	}
	else
	{
		node->prev->next = NULL;
	}
	node->prev = NULL;
	return (node);
}
