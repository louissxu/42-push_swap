#include "push_swap.h"

void	ps_sort_double_radix_sort_improved(t_deque *l, t_deque *r, t_list **moves)
{
	int radix;
	int	max_radix;
	int i;
	int	r_first_buffer_length;

	radix = 0;
	max_radix = calculate_max_radix(ft_deque_length(*l));
	while (radix < max_radix)
	{
		if (radix + 1 < max_radix)
		{
			i = ft_deque_length(*l);
			while (i > 0)
			{
				if (*(int *)(l->head->content) / ft_pow(2, radix + 1) % 2  == 0)
				{
					ps_pb(l, r, moves);
				}
				else
				{
					ps_ra(l, r, moves);
				}
				i--;
			}
			r_first_buffer_length = ft_deque_length(*l);
			i = ft_deque_length(*l);
			while (i > 0)
			{
				if (*(int *)(l->head->content) / ft_pow(2, radix) % 2  == 0)
				{
					ps_pb(l, r, moves);
				}
				else
				{
					ps_ra(l, r, moves);
				}
				i--;
			}
			i = ft_deque_length(*l) - r_first_buffer_length;
			while (i > 0)
			{
				ps_pa(l, r, moves);
				i--;
			}
			i = ft_deque_length(*r);
			while (i > 0)
			{
				if (*(int *)(r->head->content) / ft_pow(2, radix) % 2 != 0)
				{
					ps_pa(l, r, moves);
				}
				else
				{
					ps_rb(l, r, moves);
				}
				i--;
			}
			i = ft_deque_length(*r);
			while (i > 0)
			{
				ps_pa(l, r, moves);
				i--;
			}
			radix += 2;
		}
		else
		{
			i = ft_deque_length(*l);
			while (i > 0)
			{
				if (*(int *)(l->head->content) / ft_pow(2, radix) % 2  == 0)
				{
					ps_pb(l, r, moves);
				}
				else
				{
					ps_ra(l, r, moves);
				}
				i--;
			}
			i = ft_deque_length(*r);
			while (i > 0)
			{
				ps_pa(l, r, moves);
				i--;
			}
			radix += 1;
		}
	}
}