#include "push_swap.h"

void ps_selection_sort_into_brackets_twin_sided(t_ps_data *d, int num_groups)
{
	int group_size;
	int high_low;
	int low_high;
	int i;

	// Divide but round up
	// Ref: https://stackoverflow.com/a/4846569/9160572
	group_size = (ft_deque_length(d->a) + num_groups - 1) / num_groups;
	// group_size = ft_deque_length(d->a) / num_groups;
	high_low = num_groups / 2 * group_size;
	low_high = high_low;

	while (d->a.head)
	{
		i = ft_deque_length(d->a);
		while (i > 0)
		{
			if (high_low <= *(int *)(d->a.head->content) && *(int *)(d->a.head->content) < high_low + group_size)
			{
				ps_pb(d);
			}
			else if (low_high - group_size <= *(int *)(d->a.head->content) && *(int *)(d->a.head->content) < low_high)
			{
				ps_pb(d);
				ps_rb(d);
			}
			else
			{
				ps_ra(d);
			}
			i--;
		}
		high_low += group_size;
		low_high -= group_size;
	}
}

void ps_selection_sort_back_with_doubles(t_ps_data *d)
{
	int current_target;
	int next_target;
	int distance_target;
	int distance_next_target;

	current_target = ft_deque_length(d->b) - 1;
	while (d->b.head)
	{
		next_target = current_target - 1;
		if (next_target < 0)
		{
			next_target = 0;
		}
		distance_target = ps_find_distance_to_value(&d->b, current_target);
		distance_next_target = ps_find_distance_to_value(&d->b, next_target);
		if (ft_math_abs(distance_target) < ft_math_abs(distance_next_target) || current_target == next_target)
		{
			ps_pa_value_optimal(d, current_target);
			current_target--;
		}
		else
		{
			ps_pa_value_optimal(d, next_target);
			ps_pa_value_optimal(d, current_target);
			ps_sa(d);
			current_target -= 2;
		}
	}
}

void ps_sort_100_elements(t_ps_data *d)
{
	ps_selection_sort_into_brackets_twin_sided(d, 8);
	ps_selection_sort_back_with_doubles(d);
}
