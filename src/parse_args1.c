/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:45 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:39:46 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

BOOL	deque_has_duplicates(t_deque *d)
{
	t_list	*l;
	t_list	*node;

	l = ft_deque_to_list(*d, clone_heap_integer_void, free);
	list_sort_bubble_sort(l);
	node = l;
	if (node == NULL)
	{
		return (FALSE);
	}
	if (node->next == NULL)
	{
		return (FALSE);
	}
	while (node && node->next)
	{
		if (*(int *)node->content == *(int *)node->next->content)
		{
			ft_lstclear(&l, free);
			return (TRUE);
		}
		node = node->next;
	}
	ft_lstclear(&l, free);
	return (FALSE);
}

BOOL	deque_is_sorted(t_deque *d)
{
	t_dlist	*node;

	node = d->head;
	if (node == NULL)
	{
		return (TRUE);
	}
	if (node->next == NULL)
	{
		return (TRUE);
	}
	while (node && node->next)
	{
		if (*(int *)node->content <= *(int *)node->next->content)
		{
		}
		else
		{
			return (FALSE);
		}
		node = node->next;
	}
	return (TRUE);
}
