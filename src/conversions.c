/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:30 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:39:33 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

/**
 * @brief Clones a heap integer.
 * 
 * When passed in a pointer to an integer. Clones it and returns the new heap
 * integer.
 *
 * @param orig The pointer to the initial integer to clone.
 * @return clone A pointer to the new cloned integer - or NULL if clone fails.
 */
int	*clone_heap_integer(int *orig)
{
	int	*clone;

	clone = malloc(sizeof (*clone) * 1);
	*clone = *orig;
	return (clone);
}

/**
 * @brief Clones a void pointer containing a integer.
 * 
 * Wraps clone_heap_integer so taht it accepts a void pointer as argument. Used
 * where some functions expect a function with a (void *) function signature.
 *
 * @param orig The void pointer to the initial integer to clone.
 * @return clone A pointer to the new cloned integer - or NULL if clone fails.
 */
void	*clone_heap_integer_void(void *orig)
{
	void	*clone;

	clone = clone_heap_integer(orig);
	return (clone);
}

/**
 * @brief Clones a list as a new dlist.
 * 
 * Creates a clone of a list and returns it as a dlist. Clones the content by
 * calling the clone function passed in as an argument. The clone function is
 * expected to take the content pointer from nodes in the list, clone it, and
 * return a new pointer to a cloned copy of the content.
 *
 * @param list_head The pointer to the head of the list to be cloned.
 * @param clone A function that clones the content pointer in the list.
 * @return clone A dlist containing cloned content from the source list.
 */
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

/**
 * @brief Clones a deque.
 * 
 * When passed in a deque. Creates a clone, including cloning the content using
 * the passed in clone function. Returns the deque corresponding to this cloned
 * deque.
 *
 * @param d The original deque to clone.
 * @param clone The function that clones the content pointers.
 * @return new_deque A new deque with cloned copies of the content.
 */
t_deque	ft_clone_deque(t_deque d, void *(*clone)(void *))
{
	t_deque	new_deque;
	t_dlist	*curr_node;
	void	*cloned_content;

	new_deque = ft_deque_new();
	curr_node = d.head;
	while (curr_node)
	{
		cloned_content = clone(curr_node->content);
		if (!cloned_content)
		{
			return (new_deque);
		}
		ft_deque_append(&new_deque, cloned_content);
		curr_node = curr_node->next;
	}
	return (new_deque);
}

/**
 * @brief Clones a deque as a new list
 * 
 * When passed a deque, creates a clone including cloned copies of the content.
 * Packages this into a new list and returns the pointer to the head of the
 * list.
 *
 * @param d The original deque to be cloned.
 * @param clone A function to clone the content in the nodes of the deque.
 * @param del A function to delete (likely free) the cloned content. Only used 
 *     in case of error to clean up the content that was cloned but now hanging.
 * @return new_list_head The head of the new cloned list.
 */
t_list	*ft_deque_to_list(t_deque d, void *(*clone)(void *), \
	void (*del)(void *))
{
	t_list	*new_list_head;
	t_list	*new_list_tail;
	t_list	*new_list_node;
	t_dlist	*curr_node;
	void	*cloned_content;

	new_list_head = NULL;
	new_list_tail = NULL;
	curr_node = d.head;
	while (curr_node)
	{
		cloned_content = clone(curr_node->content);
		if (!cloned_content)
		{
			return (new_list_head);
		}
		new_list_node = ft_lstnew(cloned_content);
		if (!new_list_node)
		{
			del(cloned_content);
			return (new_list_head);
		}
		ft_lstadd_back(&new_list_tail, new_list_node);
		if (new_list_head == NULL)
		{
			new_list_head = new_list_tail;
		}
		curr_node = curr_node->next;
	}
	return (new_list_head);
}
