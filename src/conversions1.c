/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:32:30 by lxu               #+#    #+#             */
/*   Updated: 2022/11/08 22:32:33 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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