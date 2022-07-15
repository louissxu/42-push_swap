#include "push_swap.h"

void	ps_sort_2_elements(t_ps_data *d)
{
	// if (ft_intcmp(d->l.head->content, 0) == 0)
	if (*(int *)(d->l.head->content) == 0)
	{
		;
	}
	else
	{
		ps_sa(d);
	}
}