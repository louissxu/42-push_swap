#include "push_swap.h"

void	ps_pa_with_swap(t_deque *l, t_deque *r, t_list **moves)
{
	int	top_number;
	int	next_number;

	ps_pa(l, r, moves);
	if (ft_deque_length(*l) <= 1)
	{
		return ;
	}
	top_number = *(int *)(l->head->content);
	next_number = *(int *)(l->head->next->content);
	if (top_number / 2 == next_number / 2)
	{
		if (top_number % 2 > next_number % 2)
		{
			ps_sa(l, r, moves);
		}
	}
}

void	ps_cycle_stack_and_swap(t_deque *l, t_deque *r, t_list **moves)
{
	int	top_number;
	int	next_number;
	int	i;

	i = ft_deque_length(*l);
	if (i < 2)
	{
		return ;
	}
	while (i > 0)
	{
		top_number = *(int *)(l->head->content);
		next_number = *(int *)(l->head->next->content);
		if (top_number / 2 == next_number / 2)
		{
			if (top_number % 2 > next_number % 2)
			{
				ps_sa(l, r, moves);
			}
			ps_ra(l, r, moves);
			ps_ra(l, r, moves);
			i--;
			i--;
		}
		else
		{
			ps_ra(l, r, moves);
			i--;
		}
	}
}

void	ps_sa_if_helpful(t_deque *l, t_deque *r, t_list **moves)
{
	int	top_number;
	int	next_number;

	if (ft_deque_length(*l) <= 1)
	{
		return ;
	}
	top_number = *(int *)(l->head->content);
	next_number = *(int *)(l->head->next->content);
	if (top_number / 2 == next_number / 2)
	{
		if (top_number % 2 > next_number % 2)
		{
			ps_sa(l, r, moves);
		}
	}
}

void	ps_sa_bottom_if_helpful(t_deque *l, t_deque *r, t_list **moves)
{
	int	bottom_number;
	int	above_bottom_number;

	if (ft_deque_length(*l) <= 1)
	{
		return ;
	}
	bottom_number = *(int *)(l->tail->content);
	above_bottom_number = *(int *)(l->tail->prev->content);
	if (bottom_number / 2 == above_bottom_number / 2)
	{
		if (above_bottom_number % 2 > bottom_number % 2)
		{
			ps_rra(l, r, moves);
			ps_rra(l, r, moves);
			ps_sa(l, r, moves);
			ps_ra(l, r, moves);
			ps_ra(l, r, moves);
		}
	}
}

void	ps_sort_double_radix_sort_improved_with_swaps(t_deque *l, t_deque *r, t_list **moves)
{
	int	radix;
	int	max_radix;
	int	i;
	int	r_first_buffer_length;

	radix = 1;
	max_radix = calculate_max_radix(ft_deque_length(*l));
	while (radix < max_radix)
	{
		if (radix + 1 < max_radix)
		{
			i = ft_deque_length(*l);
			while (i > 0)
			{
				if (*(int *)(l->head->content) / ft_pow(2, radix + 1) % 2 == 0)
				{
					ps_pb(l, r, moves);
				}
				else
				{
					ps_ra(l, r, moves);
				}
				i--;
			}
			r_first_buffer_length = ft_deque_length(*r);
			i = ft_deque_length(*l);
			while (i > 0)
			{
				if (*(int *)(l->head->content) / ft_pow(2, radix) % 2 == 0)
				{
					ps_pb(l, r, moves);
				}
				else
				{
					ps_sa_bottom_if_helpful(l, r, moves);
					ps_ra(l, r, moves);
					ps_sa_bottom_if_helpful(l, r, moves);
				}
				i--;
			}
			i = ft_deque_length(*r) - r_first_buffer_length;
			while (i > 0)
			{
				ps_pa_with_swap(l, r, moves);
				i--;
			}
			i = ft_deque_length(*r);
			while (i > 0)
			{
				if (*(int *)(r->head->content) / ft_pow(2, radix) % 2 != 0)
				{
					ps_pa_with_swap(l, r, moves);
				}
				else
				{
					ps_rb(l, r, moves);
				}
				i--;
			}
			// if (radix + 2 >= max_radix)
			// {
			// 	ps_cycle_stack_and_swap(l, r, moves);
			// }
			i = ft_deque_length(*r);
			while (i > 0)
			{
				ps_pa_with_swap(l, r, moves);
				i--;
			}
			radix += 2;
		}
		else
		{
			i = ft_deque_length(*l);
			while (i > 0)
			{
				if (*(int *)(l->head->content) / ft_pow(2, radix) % 2 == 0)
				{
					ps_sa_bottom_if_helpful(l, r, moves);
					ps_pb(l, r, moves);
					ps_sa_bottom_if_helpful(l, r, moves);
				}
				else
				{
					ps_sa_bottom_if_helpful(l, r, moves);
					ps_ra(l, r, moves);
					ps_sa_bottom_if_helpful(l, r, moves);
				}
				i--;
			}
			// ps_cycle_stack_and_swap(l, r, moves);
			i = ft_deque_length(*r);
			while (i > 0)
			{
				ps_pa_with_swap(l, r, moves);
				i--;
			}
			radix += 1;
		}
	}

	// i = ft_deque_length(*l);
	// while (i > 0)
	// {
	// 	int	current_num = *(int *)(l->head->content);
	// 	int next_num = *(int *)(l->head->next->content);
	// 	if (current_num / 2 == next_num / 2)
	// 	{
	// 		if (current_num % 2 > next_num % 2)
	// 		{
	// 			ps_sa(l, r, moves);
	// 		}
	// 		ps_ra(l, r, moves);
	// 		ps_ra(l, r, moves);
	// 		i--;
	// 		i--;
	// 	}
	// 	else
	// 	{
	// 		ps_ra(l, r, moves);
	// 		i--;
	// 	}
	// }
}