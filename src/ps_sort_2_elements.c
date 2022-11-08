/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_2_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:58 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:39:59 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts a two element push swap puzzle
 * 
 * Assumes content is normalised.
 * Checks if the first element has a value of zero. If it does, do nothing. Else
 * outputs sa to swap the two elements.
 * 
 * @param d Pointer to a set of push swap data.
*/
void	ps_sort_2_elements(t_ps_data *d)
{
	if (*(int *)(d->a.head->content) == 0)
	{
	}
	else
	{
		ps_sa(d);
	}
}
