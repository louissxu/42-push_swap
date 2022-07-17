#include "push_swap.h"

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