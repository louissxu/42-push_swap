#include "push_swap.h"

// Check how this handles INT_MIN
int	ft_abs(int val)
{
	if (val < 0)
	{
		return (val * -1);
	}
	return (val);
}