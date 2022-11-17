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
 * Takes two integers and returns the power of the base to the exponent
 * (base^exponent).
 * 
 * Uses iterative version of exponentiation by squaring.
 * 
 * NB: DOES NOT HANDLE NEGATIVE EXPONENTS. TO BE FIXED.
 * 
 * If the return value overflows (> INT_MAX) the behaviour is undefined. Likely
 * rolls over but this depends on the compiler's handling of integer overflow.
 * 
 * Ref: https://stackoverflow.com/a/23079728/9160572
 * 
 * @param base The base of the power calculation.
 * @param exponent The exponent of the power calculation.
 * @returns base^exponent
*/
int	ft_math_pow(int base, int exponent)
{
	int	result;

	if (base == 0 && exponent == 0)
		return (0);
	if (exponent == 0)
		return (0);
	if (exponent < 0)
		return (0);
	result = 1;
	while (exponent > 0)
	{
		while ((exponent & 1) == 0)
		{
			exponent /= 2;
			base *= base;
		}
		exponent--;
		result *= base;
	}
	return (result);
}
