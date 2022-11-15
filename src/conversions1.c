/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:32:30 by lxu               #+#    #+#             */
/*   Updated: 2022/11/08 22:32:33 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Set multiple pointers to NULL
 * 
 * Takes a number of pointers and the count of those pointers and sets them all
 * to NULL.
 * 
 * @param count The number of pointers in the variadic list.
 * @param ... Variadic list of the pointesr to be set to NULL.
*/
void	set_pointers_to_null(size_t count, ...)
{
	va_list	ptrs;
	void	**ptr;
	size_t	i;

	va_start(ptrs, count);
	i = 0;
	while (i < count)
	{
		ptr = va_arg(ptrs, void **);
		*ptr = NULL;
		i++;
	}
	va_end(ptrs);
}