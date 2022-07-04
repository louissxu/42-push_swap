#include "push_swap.h"

t_deque	parse_input_args_to_deque(char **argv)
{
	char	**input_arg;
	int		*num;
	t_deque	d;

	d = ft_deque_new();
	input_arg = &argv[1];
	while (*input_arg)
	{
		num = malloc(sizeof (*num) * 1);
		if (!num)
		{
			break ;
		}
		*num = ft_atoi(*input_arg);
		ft_deque_append(&d, num);
		input_arg++;
	}
	return d;
}

int	*clone_heap_integer(int *orig)
{
	int	*clone;

	clone = malloc(sizeof (*clone) * 1);
	*clone = *orig;
	return (clone);
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

int	check_if_deque_has_duplicates(t_deque *d)
{
	t_dlist *node;

	node = d->head;
	if (!node)
	{
		return (0);
	}
	if (!node->next)
	{
		return (0);
	}
	while (node->next)
	{
		// ft_printf("checking for duplicates %i vs %i\n", *(int *)node->content, *(int *)node->next->content);
		if (*(int *)(node->content) == *(int *)(node->next->content))
		{
			return (1);
		}
		node = node->next;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_deque l;
	t_deque r;
	t_list *moves;

	if (argc == 1)
	{
		ft_printf("not enough args\n");
		return (0);
	}
	l = parse_input_args_to_deque(argv);
	if (check_if_deque_has_duplicates(&l) == 1)
	{
		ft_printf("has duplicates\n");
		ft_deque_destroy_list(&l, free);
		return (0);
	}
	// debug_print_deque(&l);
	normalise_in_place(&l);
	// debug_print_deque(&l);
	r = ft_deque_new();
	moves = NULL;

	if (ft_deque_length(l) <= 1)
	{
		;
		// ft_printf("debug: sorting 1\n");
	}
	else if (ft_deque_length(l) == 2)
	{
		ps_sort_2_elements(&l, &r, &moves);
		// ft_printf("debug: sorting 2\n");
	}
	else if (ft_deque_length(l) == 3)
	{
		ps_sort_3_elements(&l, &r, &moves);
		// ft_printf("debug: sorting 3\n");
	}
	else if (ft_deque_length(l) == 4)
	{
		ps_sort_4_elements(&l, &r, &moves);
		// ft_printf("debug: sorting 4\n");
	}
	else if (ft_deque_length(l) == 5)
	{
		ps_sort_5_elements(&l, &r, &moves);
		// ft_printf("debug: sorting 5\n");
	}
	else if (ft_deque_length(l) < 50)
	{
		ps_sort_double_radix_sort_improved(&l, &r, &moves);
		// ft_printf("debug: sorting 50\n");
	}
	else if (ft_deque_length(l) < 150)
	{
		ps_sort_100_elements(&l, &r, &moves);
		// ft_printf("debug: sorting 150\n");
	}
	else if (ft_deque_length(l) < 600)
	{
		ps_sort_500_elements(&l, &r, &moves);
		// ft_printf("debug: sorting 600\n");
	}
	else
	{
		ps_sort_double_radix_sort_improved(&l, &r, &moves);
		// ft_printf("debug: sorting >600\n");
	}
	debug_print_list_of_moves(moves);
	// ft_printf("debug: length of l is: %i\n", (int)ft_deque_length(l));
	// ft_printf("Number of moves: %i\n", ft_lstsize(moves));
}