#include "push_swap.h"

// Check how this handles INT_MIN
long	ft_math_abs(int val)
{
	long	l_val;

	l_val = val;
	if (l_val < 0)
	{
		return (l_val * -1);
	}
	return (l_val);
}