#include "push_swap.h"

void	ps_selection_sort_into_brackets_twin_sided(t_deque *l, t_deque *r, t_list **moves, int num_groups)
{
	int	group_size;
	// int	high_high;
	int	high_low;
	int	low_high;
	// int low_low;
	int i;

	// Divide but round up
	// Ref: https://stackoverflow.com/a/4846569/9160572
	group_size = (ft_deque_length(*l) + num_groups - 1) / num_groups;
	// group_size = ft_deque_length(*l) / num_groups;
	high_low = num_groups / 2 * group_size;
	low_high = high_low;

	while (l->head)
	{
		i = ft_deque_length(*l);
		while (i > 0)
		{
			if (high_low <= *(int *)(l->head->content) && *(int *)(l->head->content) < high_low + group_size)
			{
				ps_pb(l, r, moves);
			}
			else if (low_high - group_size <= *(int *)(l->head->content) && *(int *)(l->head->content) < low_high)
			{
				ps_pb(l, r, moves);
				ps_rb(l, r, moves);
			}
			else
			{
				ps_ra(l, r, moves);
			}
			i--;
		}
		high_low += group_size;
		low_high -= group_size;
	}
}

void	ps_selection_sort_back_with_doubles(t_deque *l, t_deque *r, t_list **moves)
{
	int	current_target;
	int	next_target;
	int	distance_target;
	int	distance_next_target;

	current_target = ft_deque_length(*r) - 1;
	while (r->head)
	{
		next_target = current_target - 1;
		if (next_target < 0)
		{
			next_target = 0;
		}
		distance_target = ps_find_distance_to_value(r, current_target);
		distance_next_target = ps_find_distance_to_value(r, next_target);
		if (ft_math_abs(distance_target) < ft_math_abs(distance_next_target) || current_target == next_target)
		{
			ps_pa_value_optimal(l, r, moves, current_target);
			current_target--;
		}
		else
		{
			ps_pa_value_optimal(l, r, moves, next_target);
			ps_pa_value_optimal(l, r, moves, current_target);
			ps_sa(l, r, moves);
			current_target -= 2;
		}
	}
}

void	ps_sort_100_elements(t_deque *l, t_deque *r, t_list **moves)
{
	ps_selection_sort_into_brackets_twin_sided(l, r, moves, 8);
	ps_selection_sort_back_with_doubles(l, r, moves);
}