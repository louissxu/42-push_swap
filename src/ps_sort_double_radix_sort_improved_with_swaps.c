#include "push_swap.h"

void	ps_pa_with_swap(t_ps_data *d)
{
	int	top_number;
	int	next_number;

	ps_pa(d);
	if (ft_deque_length(d->l) <= 1)
	{
		return ;
	}
	top_number = *(int *)(d->l.head->content);
	next_number = *(int *)(d->l.head->next->content);
	if (top_number / 2 == next_number / 2)
	{
		if (top_number % 2 > next_number % 2)
		{
			ps_sa(d);
		}
	}
}

void	ps_cycle_stack_and_swap(t_ps_data *d)
{
	int	top_number;
	int	next_number;
	int	i;

	i = ft_deque_length(d->l);
	if (i < 2)
	{
		return ;
	}
	while (i > 0)
	{
		top_number = *(int *)(d->l.head->content);
		next_number = *(int *)(d->l.head->next->content);
		if (top_number / 2 == next_number / 2)
		{
			if (top_number % 2 > next_number % 2)
			{
				ps_sa(d);
			}
			ps_ra(d);
			ps_ra(d);
			i--;
			i--;
		}
		else
		{
			ps_ra(d);
			i--;
		}
	}
}

void	ps_sa_if_helpful(t_ps_data *d)
{
	int	top_number;
	int	next_number;

	if (ft_deque_length(d->l) <= 1)
	{
		return ;
	}
	top_number = *(int *)(d->l.head->content);
	next_number = *(int *)(d->l.head->next->content);
	if (top_number / 2 == next_number / 2)
	{
		if (top_number % 2 > next_number % 2)
		{
			ps_sa(d);
		}
	}
}

void	ps_sa_bottom_if_helpful(t_ps_data *d)
{
	int	bottom_number;
	int	above_bottom_number;

	if (ft_deque_length(d->l) <= 1)
	{
		return ;
	}
	bottom_number = *(int *)(d->l.tail->content);
	above_bottom_number = *(int *)(d->l.tail->prev->content);
	if (bottom_number / 2 == above_bottom_number / 2)
	{
		if (above_bottom_number % 2 > bottom_number % 2)
		{
			ps_rra(d);
			ps_rra(d);
			ps_sa(d);
			ps_ra(d);
			ps_ra(d);
		}
	}
}

void	ps_sort_double_radix_sort_improved_with_swaps(t_ps_data *d)
{
	int	radix;
	int	max_radix;
	int	i;
	int	r_first_buffer_length;

	radix = 1;
	max_radix = calculate_max_radix(ft_deque_length(d->l));
	while (radix < max_radix)
	{
		if (radix + 1 < max_radix)
		{
			i = ft_deque_length(d->l);
			while (i > 0)
			{
				if (*(int *)(d->l.head->content) / ft_pow(2, radix + 1) % 2 == 0)
				{
					ps_pb(d);
				}
				else
				{
					ps_ra(d);
				}
				i--;
			}
			r_first_buffer_length = ft_deque_length(d->r);
			i = ft_deque_length(d->l);
			while (i > 0)
			{
				if (*(int *)(d->l.head->content) / ft_pow(2, radix) % 2 == 0)
				{
					ps_pb(d);
				}
				else
				{
					ps_sa_bottom_if_helpful(d);
					ps_ra(d);
					ps_sa_bottom_if_helpful(d);
				}
				i--;
			}
			i = ft_deque_length(d->r) - r_first_buffer_length;
			while (i > 0)
			{
				ps_pa_with_swap(d);
				i--;
			}
			i = ft_deque_length(d->r);
			while (i > 0)
			{
				if (*(int *)(d->r.head->content) / ft_pow(2, radix) % 2 != 0)
				{
					ps_pa_with_swap(d);
				}
				else
				{
					ps_rb(d);
				}
				i--;
			}
			// if (radix + 2 >= max_radix)
			// {
			// 	ps_cycle_stack_and_swap(d);
			// }
			i = ft_deque_length(d->r);
			while (i > 0)
			{
				ps_pa_with_swap(d);
				i--;
			}
			radix += 2;
		}
		else
		{
			i = ft_deque_length(d->l);
			while (i > 0)
			{
				if (*(int *)(d->l.head->content) / ft_pow(2, radix) % 2 == 0)
				{
					ps_sa_bottom_if_helpful(d);
					ps_pb(d);
					ps_sa_bottom_if_helpful(d);
				}
				else
				{
					ps_sa_bottom_if_helpful(d);
					ps_ra(d);
					ps_sa_bottom_if_helpful(d);
				}
				i--;
			}
			// ps_cycle_stack_and_swap(d);
			i = ft_deque_length(d->r);
			while (i > 0)
			{
				ps_pa_with_swap(d);
				i--;
			}
			radix += 1;
		}
	}

	// i = ft_deque_length(d->l);
	// while (i > 0)
	// {
	// 	int	current_num = *(int *)(d->l.head->content);
	// 	int next_num = *(int *)(l->head->next->content);
	// 	if (current_num / 2 == next_num / 2)
	// 	{
	// 		if (current_num % 2 > next_num % 2)
	// 		{
	// 			ps_sa(d);
	// 		}
	// 		ps_ra(d);
	// 		ps_ra(d);
	// 		i--;
	// 		i--;
	// 	}
	// 	else
	// 	{
	// 		ps_ra(d);
	// 		i--;
	// 	}
	// }
}