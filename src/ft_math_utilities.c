/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:42 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:39:44 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/**
 * @brief Returns the power of an integer.
 * 
 * Takes two integers and returns the power of x to the y.
 * 
 * Uses serial multiplication. (Fix: Switch to exponentiation by squaring for a
 * faster algorithm)
 * 
 * If the return value overflows (> INT_MAX) the behaviour is undefined. Likely
 * rolls over but this depends on the compiler's handling of integer overflow.
*/
int	ft_math_pow(int x, int y)
{
	int	result;

	if (x == 0 && y == 0)
	{
		return (0);
	}
	if (y == 0)
	{
		return (1);
	}
	if (y < 0)
	{
		return (0);
	}
	result = x;
	while (y > 1)
	{
		result *= x;
		y--;
	}
	return (result);
}
