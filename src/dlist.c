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

/*
Pops the node with the given pointer. Assumes that the node is a valid pointer in the head list (otherwise bad things happen)
*/
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