#include "push_swap.c"

int	calculate_max_radix(int num)
{
	int max_radix;

	max_radix = 0;
	if (num < 0)
	{
		return 0;
	}
	while (num > pow(2, max_radix))
	{
		max_radix++;
	}
}

void	ps_sort_double_radix_sort(t_deque *l, t_deque *r, t_list **moves)
{
	int radix;
	int	max_radix;
	int i;
	int	max_i;
	int	r_first_buffer_length;

	radix = 0;
	max_radix = calculate_max_radix(ft_deque_length(*l));
	while (radix < max_radix)
	{
		max_i = ft_deque_length(*l);
		i = 0;
		while (i < max_i)
		{
			if (*(int *)(l->head->content) / pow(2, radix) % 2  == 0)
			{
				ps_pb(l, r, moves);
			}
			else
			{
				ps_ra(l, r, moves);
			}
		}
		radix++;
		if (radix < max_radix)
		{
			r_first_buffer_length = ft_deque_length(*r);
			max_i = ft_deque_length(*l);
			i = 0
			while (i < max_i)
			{
				if (*(int *)(l->head->content) / pow(2, radix) % 2  == 0)
				{
					ps_pb(l, r, moves);
				}
				else
				{
					ps_ra(l, r, moves);
				}
			}
		}
		
		

	}

}