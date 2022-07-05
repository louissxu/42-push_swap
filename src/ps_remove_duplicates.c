#include "push_swap.h"

t_dlist	*list_to_dlist(t_list *list_head)
{
	t_dlist	*dlist_head;
	t_list	*list_node;
	int		*cloned_int;
	t_dlist *new_node;

	dlist_head = NULL;
	list_node = list_head;
	while (list_node)
	{
		cloned_int = clone_heap_integer(list_node->content);
		if (!cloned_int)
		{
			return (dlist_head);
		}
		new_node = ft_dlist_new_node(cloned_int);
		if (!new_node)
		{
			free (cloned_int);
			return (dlist_head);
		}
		ft_dlist_insert_end(&dlist_head, new_node);
		list_node = list_node->next;
	}
	return dlist_head;

}

t_dlist	*ps_remove_duplicates(t_list *l)
{
	t_dlist	*dlist_head;
	t_dlist	*node;
	t_dlist	*prev_node;

	dlist_head = list_to_dlist(l);
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
		if ((ft_strncmp(node->content, "pb", 3) == 0 && ft_strncmp(node->next->content, "pa", 3) == 0) || \
			(ft_strncmp(node->content, "pa", 3) == 0 && ft_strncmp(node->next->content, "pb", 3) == 0) || \
			(ft_strncmp(node->content, "ra", 3) == 0 && ft_strncmp(node->next->content, "rra", 3) == 0) || \
			(ft_strncmp(node->content, "rra", 3) == 0 && ft_strncmp(node->next->content, "ra", 3) == 0) || \
			(ft_strncmp(node->content, "rb", 3) == 0 && ft_strncmp(node->next->content, "rrb", 3) == 0) || \
			(ft_strncmp(node->content, "rrb", 3) == 0 && ft_strncmp(node->next->content, "rb", 3) == 0))
		{
			prev_node = node->prev;
			ft_dlist_pop_at_pointer(&dlist_head, node);
			ft_dlist_destroy_node(node, free);
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