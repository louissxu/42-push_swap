#include "push_swap.h"

/**
 * @brief Returns the absolute value of an integer.
 * 
 * Takes an integer and returns the absolute value of that integer.
 * Note that for INT_MIN (-2147483648) it returns INT_MIN as that is how two's
 * complement math works. Have not tried to handle it in a special way since
 * this matches the behaviour of the stdlib abs function.
 *
 * @param val The integer to be checked.
 * @returns val The absolute value of val. For INT_MIN returns INT_MIN.
 */
int	ft_math_abs(int val)
{
	if (val < 0)
	{
		return (val * -1);
	}
	return (val);
}
