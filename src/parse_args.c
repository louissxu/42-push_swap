#include "push_swap.h"

bool	str_is_valid_integer(char *str, int *dest)
{
	int		i;
	int		num_len;
	long	val;
	bool	is_negative;

	i = 0;
	num_len = 0;
	val = 0;
	is_negative = false;
	if (str[i] == '-')
	{
		i++;
		is_negative = true;
		if (str[i] == '\0')
		{
			return false;
		}
	}
	while (str[i] == '0')
	{
		i++;
	}
	while (str[i] && num_len < 10)
	{
		if (ft_isinstr(str[i], "0123456789") == 0)
		{
			return false;
		}
		val *= 10;
		val += str[i] - '0';
		i++;
		num_len++;
	}
	if (is_negative == true)
	{
		val *= -1;
	}
	if (val > INT_MAX || val < INT_MIN || str[i] != '\0')
	{
		return false;
	}
	*dest = (int)val;
	return true;
}

void	clear_table(char **table)
{
	size_t	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

t_deque	parse_input_args_to_deque(char **argv, bool *err)
{
	char	**input_arg;
	int		*num;
	bool	no_err;
	t_deque	d;
	char	**split_args;
	size_t	i;

	*err = false;
	d = ft_deque_new();
	input_arg = &argv[1];
	while (*input_arg)
	{
		split_args = ft_split(*input_arg, ' ');
		i = 0;
		while (split_args[i])
		{
			num = malloc(sizeof (*num) * 1);
			if (!num)
			{
				break ;
			}
			no_err = str_is_valid_integer(split_args[i], num);
			if (no_err == false)
			{
				ft_deque_destroy_list(&d, free);
				free(num);
				*err = true;
				clear_table(split_args);
				return d;
			}
			ft_deque_append(&d, num);
			i++;
		}
		clear_table(split_args);
		// *num = ft_atoi(*input_arg);
		input_arg++;
	}
	return d;
}

t_list	*deque_to_list(t_deque *d)
{
	t_list *list_head;
	t_list *list_tail;
	t_dlist *deque_node_pointer;
	void	*cloned_content;

	list_head = NULL;
	list_tail = NULL;
	deque_node_pointer = d->head;

	while (deque_node_pointer)
	{
		cloned_content = clone_heap_integer(deque_node_pointer->content);
		ft_lstadd_back(&list_tail, ft_lstnew(cloned_content));
		deque_node_pointer = deque_node_pointer->next;
		if (list_head == NULL)
		{
			list_head = list_tail;
		}
	}
	return (list_head);
}

bool	deque_has_duplicates(t_deque *d)
{
	t_list	*l;
	t_list	*node;

	l = deque_to_list(d);
	list_sort_bubble_sort(l);

	node = l;
	if (node == NULL)
	{
		return false;
	}

	if (node->next == NULL)
	{
		return false;
	}
	while (node && node->next)
	{
		if (*(int *)node->content == *(int *)node->next->content)
		{
			ft_lstclear(&l, free);
			return true;
		}
		node = node->next;
	}
	ft_lstclear(&l, free);
	return false;
}

bool	deque_is_sorted(t_deque *d)
{
	t_dlist	*node;

	node = d->head;
	if (node == NULL)
	{
		return true;
	}
	if (node->next == NULL)
	{
		return true;
	}
	while (node && node->next)
	{
		if (*(int *)node->content <= *(int *)node->next->content)
		{
			;
		}
		else
		{
			return false;
		}
		node = node->next;
	}
	return true;
}


/**
 * @brief Swap the content of two list nodes
 * 
 * @param node_1 First node to swap
 * @param node_2 Second node to swap
 */
void	list_swap_content(t_list *node_1, t_list *node_2)
{
	void	*temp_content;

	temp_content = node_1->content;
	node_1->content = node_2->content;
	node_2->content = temp_content;
}

long	ft_intcmp(const	int *i1, int *i2)
{
	return ((long)*i1 - *i2);
}

/**
 * @brief In-place bubble sort of a list
 * 
 * An implementation of an bubble sort of a list containing heap integers
 * as content
 * 
 * As a design decision, it swaps the /content pointers/ within the list rather
 * than swapping the entire list nodes themselves.
 * 
 * @param l The head of the list to be sorted
 * @return t_list* Returns the head of the list
 */

t_list	*list_sort_bubble_sort(t_list *l)
{
	int	unsorted_element_count;
	int swapped;
	t_list	*node;
	int		node_i;

	unsorted_element_count = ft_lstsize(l);
	swapped = 1;

	while (swapped == 1)
	{
		swapped = 0;
		node = l;
		node_i = 0;
		while (node_i < unsorted_element_count - 1)
		{
			if (ft_intcmp(node->content, node->next->content) > 0)
			{
				list_swap_content(node, node->next);
				swapped = 1;
			}
			node_i++;
			node = node->next;
		}
	}
	return (l);
}

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
	return clone;
}

t_deque	clone_deque(t_deque *d)
{
	t_deque	clone;
	t_dlist	*node;

	clone = ft_deque_new();
	node = d->head;

	while (node)
	{
		ft_deque_append(&clone, clone_heap_integer(node->content));
		node = node->next;
	}
	return clone;
}

t_deque	*normalise_in_place(t_deque *d)
{
	t_list	*sorted_list_head;
	int		i;
	t_dlist	*d_node;
	t_list	*sorted_list_node;

	sorted_list_head = list_sort_bubble_sort(deque_to_list(d));
	d_node = d->head;
	while (d_node != NULL)
	{
		i = 0;
		sorted_list_node = sorted_list_head;
		while (ft_intcmp(sorted_list_node->content, d_node->content) != 0)
		{
			i++;
			sorted_list_node = sorted_list_node->next;
		}
		*(int *)(d_node->content) = i;
		d_node = d_node->next;
	}
	ft_lstclear(&sorted_list_head, free);
	return (d);
}