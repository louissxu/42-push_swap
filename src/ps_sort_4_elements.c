/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_4_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:40:02 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:40:03 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts a four element push swap puzzle
 * 
 * Pushes across the smallest element with the optimal number of moves. The list
 * is then sorted as if the list is three elements. Then the smallest element is
 * pushed back onto stack a.
 * 
 * @param d Pointer to a set of push swap data.
*/
void	ps_sort_4_elements(t_ps_data *d)
{
	ps_pb_value_optimal(d, 0);
	ps_sort_3_elements(d);
	ps_pa(d);
}
