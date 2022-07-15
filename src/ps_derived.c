#include "push_swap.h"

void	ps_pa_value_optimal(t_ps_data *d, int value)
{
	int	distance;

	distance = ps_find_distance_to_value(&d->r, value);
	while (distance > 0)
	{
		ps_rb(d);
		distance--;
	}
	while (distance < 0)
	{
		ps_rrb(d);
		distance++;
	}
	ps_pa(d);
}

void	ps_pa_all(t_ps_data *d)
{
	while (d->r.head)
	{
		ps_pa(d);
	}
}

void	ps_pb_value_optimal(t_ps_data *d, int value)
{
	int	distance;

	distance = ps_find_distance_to_value(&d->l, value);
	while (distance > 0)
	{
		ps_ra(d);
		distance--;
	}
	while (distance < 0)
	{
		ps_rra(d);
		distance++;
	}
	ps_pb(d);
}
