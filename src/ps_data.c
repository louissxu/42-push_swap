/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:47 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:39:48 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Destroy ps_data struct
 * 
 * Destroys the the components within a ps_data struct.
 * 
 * @param data ps_data struct to be destroyed
*/
void	ps_data_destroy(t_ps_data data)
{
	ft_deque_destroy_list(&data.a, free);
	ft_deque_destroy_list(&data.b, free);
	ft_lstclear(&data.m, free);
}
