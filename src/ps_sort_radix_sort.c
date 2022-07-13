#include "push_swap.h"

int	is_sorted(t_deque *stack)
{
	t_dlist	*node;

	if (ft_deque_length(*stack) <= 1)
	{
		return (1);
	}
	node = stack->head;
	while (node->next)
	{
		if (ft_intcmp(node->content, node->next->content) > 0)
		{
			return (0);
		}
		node = node->next;
	}
	return (1);
}

int	ft_pow(int x, int y)
{
	int	result;

	if (x == 0 && y == 0)
	{
		return (0);
	}
	if (y == 0)
	{
		return (1);
	}
	if (y < 0)
	{
		return (0);
	}
	result = x;
	while (y > 1)
	{
		result *= x;
		y--;
	}
	return (result);
}

// void	ps_sort_radix_sort(t_deque *l, t_deque *r, t_list **moves)
void	ps_sort_radix_sort(t_ps_data *d)
{
	int	radix;
	int	i;
	int	max_i;

	radix = 0;
	while (is_sorted(&d->l) == 0)
	{
		i = 0;
		max_i = ft_deque_length(d->l);
		while (i < max_i)
		{
			if (*(int *)(d->l.head->content) / ft_pow(2, radix) % 2 == 0)
			{
				ps_pb(&d->l, &d->r, &d->m);
			}
			else
			{
				ps_ra(&d->l, &d->r, &d->m);
			}
			i++;
		}
		while (d->r.head)
		{
			ps_pa(&d->l, &d->r, &d->m);
		}
		radix++;
	}
}