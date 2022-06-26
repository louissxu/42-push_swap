#include "push_swap.h"

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