#include "push_swap.h"

int calculate_max_radix(int num)
{
	int max_radix;

	max_radix = 0;
	if (num < 0)
	{
		return (0);
	}
	while (num > ft_pow(2, max_radix))
	{
		max_radix++;
	}
	return (max_radix);
}

void ps_sort_double_radix_sort(t_ps_data *d)
{
	int radix;
	int max_radix;
	int i;
	int max_i;
	int r_first_buffer_length;

	radix = 0;
	max_radix = calculate_max_radix(ft_deque_length(d->a));
	while (radix < max_radix)
	{
		max_i = ft_deque_length(d->a);
		i = 0;
		while (i < max_i)
		{
			if (*(int *)(d->a.head->content) / ft_pow(2, radix) % 2 == 0)
			{
				ps_pb(d);
			}
			else
			{
				ps_ra(d);
			}
			i++;
		}
		radix++;
		if (radix < max_radix)
		{
			r_first_buffer_length = ft_deque_length(d->b);
			max_i = ft_deque_length(d->a);
			i = 0;
			while (i < max_i)
			{
				if (*(int *)(d->a.head->content) / ft_pow(2, radix) % 2 == 0)
				{
					ps_pb(d);
				}
				else
				{
					ps_ra(d);
				}
				i++;
			}
			i = 0;
			max_i = ft_deque_length(d->b) - r_first_buffer_length;
			while (i < max_i)
			{
				ps_rb(d);
				i++;
			}
			i = 0;
			while (i < r_first_buffer_length)
			{
				if (*(int *)(d->b.head->content) / ft_pow(2, radix) % 2 != 0)
				{
					ps_pa(d);
				}
				else
				{
					ps_rb(d);
				}
				i++;
			}
		}
		i = 0;
		max_i = ft_deque_length(d->b);
		while (i < max_i)
		{
			ps_pa(d);
			i++;
		}
		radix += 1;
	}
}