/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:29:35 by lxu               #+#    #+#             */
/*   Updated: 2022/11/13 18:29:36 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Print moves to console from dlist head
 * 
 * Takes moves from a dlist and prints the content to console stdout.
 * 
 * @param d The head of the dlist to be printed from.
*/
void	ps_print_list_of_moves_dlist(t_dlist *d)
{
	while (d != NULL)
	{
		ft_printf("%s\n", d->content);
		d = d->next;
	}
}

/**
 * @brief Print moves to console from ps_data struct
 * 
 * Takes moves from a ps_data struct and prints the moves to console stdout.
 * 
 * Does some cleaning inbetween. Removes the paired moves before printing the
 * moves out.
 * 
 * @param data The ps_data struct to print the moves from.
*/
void	ps_print_moves(t_ps_data data)
{
	t_dlist	*moves_dlist;

	moves_dlist = ps_remove_paired_moves(data.m);
	ps_print_list_of_moves_dlist(moves_dlist);
	ft_dlist_destroy_list(moves_dlist, free);
}
