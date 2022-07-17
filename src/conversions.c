#include "push_swap.h" 

int	*clone_heap_integer(int *orig)
{
	int	*clone;

	clone = malloc(sizeof (*clone) * 1);
	*clone = *orig;
	return (clone);
}

void	*clone_heap_integer_void(void *orig)
{
	void *clone;

	clone = clone_heap_integer(orig);
	return (clone);
}

t_dlist	*ft_list_to_dlist(t_list *list_head, void *(*clone)(void *))
{
	t_dlist	*dlist_head;
	t_list	*list_node;
	void	*cloned_content;
	t_dlist	*new_node;

	dlist_head = NULL;
	list_node = list_head;
	while (list_node)
	{
		cloned_content = clone(list_node->content);
		if (!cloned_content)
		{
			return (dlist_head);
		}
		new_node = ft_dlist_new_node(cloned_content);
		if (!new_node)
		{
			free (cloned_content);
			return (dlist_head);
		}
		ft_dlist_insert_end(&dlist_head, new_node);
		list_node = list_node->next;
	}
	return (dlist_head);
}

t_deque	ft_clone_deque(t_deque d, void *(*clone)(void *))
{
	t_deque	new_deque;
	t_dlist	*curr_node;
	void	*cloned_content;
	t_dlist	*new_node;

	new_deque = ft_deque_new();
	curr_node = d.head;
	while (curr_node)
	{
		cloned_content = clone(curr_node->content);
		if (!cloned_content)
		{
			return (new_deque);
		}
		new_node = ft_dlist_new_node(cloned_content);
		if (!new_node)
		{
			free (cloned_content);
			return (new_deque);
		}
		ft_deque_append(&new_deque, new_node);
		curr_node = curr_node->next;
	}
	return (new_deque);
}