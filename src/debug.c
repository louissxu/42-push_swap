#include "push_swap.h"

/**
 * @brief Print list to stdout
 * 
 * Prints a list's content to stdout. Debug function to interrogate the value of
 * certain structs throughout development. Not used in final implementation.
 *
 * @param node The head pointer of the list to be printed
 */
void	debug_print_list(t_list *node)
{
	ft_printf("[");
	while (node != NULL)
	{
		ft_printf("%i", *(int *)(node->content));
		if (node->next)
		{
			ft_printf(", ");
		}
		node = node->next;
	}
	ft_printf("]\n");
}

void	debug_print_list_of_moves(t_list *moves_node)
{
	while (moves_node != NULL)
	{
		ft_printf("%s\n", moves_node->content);
		moves_node = moves_node->next;
	}
}

void	debug_print_list_of_moves_dlist(t_dlist *d)
{
	while (d != NULL)
	{
		ft_printf("%s\n", d->content);
		d = d->next;
	}
}

void	debug_print_dlist(t_dlist *node)
{
	ft_printf("dlist([");
	while (node != NULL)
	{
		ft_printf("%i", *(int *)(node->content));
		if (node->next)
		{
			ft_printf(", ");
		}
		node = node->next;
	}
	ft_printf("])\n");
}

void	debug_print_deque(t_deque *d)
{
	t_dlist	*node;

	node = d->head;
	ft_printf("deque([");
	while (node != NULL)
	{
		ft_printf("%i", *(int *)(node->content));
		if (node->next)
		{
			ft_printf(", ");
		}
		node = node->next;
	}
	ft_printf("])\n");
}
