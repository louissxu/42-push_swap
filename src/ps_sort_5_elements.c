/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_5_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:40:06 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:40:07 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts a five element push swap puzzle
 * 
 * Pushes across the smallest two elements. The stack a is then sorted as if the
 * stack has only three elements. Then the two elements are pushed back onto
 * stack a.
 * 
 * @param d Pointer to a set of push swap data.
*/
void	ps_sort_5_elements(t_ps_data *d)
{
	ps_pb_value_optimal(d, 0);
	ps_pb_value_optimal(d, 1);
	ps_sort_3_elements(d);
	ps_pa(d);
	ps_pa(d);
}
