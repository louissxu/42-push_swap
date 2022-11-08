/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:17 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:39:29 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Applies a list of commands to the stacks in a ps_data struct
 * 
 * Takes a ps_data struct and sequentially applies the commands in the list of
 * commands. If a command is not valid (ie the string does not match the subset
 * of strings that are valid commands) then it stops and returns an error flag.
 * 
 * @param d ps_data struct containing stack for commands to be applied to.
 * @param commands_head List of commands to be applied to the ps_data struct.
 * @return Boolean flag. Returns TRUE (1) if an invalid command is found.
*/
int	apply_commands_to_stacks(t_ps_data *d, t_dlist *commands_head)
{
	t_dlist	*node;
	int		invalid;

	node = commands_head;
	while (node)
	{
		invalid = apply_command_to_data(d, node);
		if (invalid == TRUE)
		{
			return (TRUE);
		}
		node = node->next;
	}
	return (FALSE);
}

/**
 * @brief Applies a command to the ps_data struct
 * 
 * Checks the string in the node passed in and if it matches a valid move it
 * does the corresponding move to the ps_data struct (edits the stacks
 * appropriately and appends the move to the end of the moves list).
 * 
 * @param d The ps_data struct to work with.
 * @param node A dlist node which contains a string as content that may be a
 *   valid ps command.
 * @returns Boolean value. Returns TRUE (1) if an error occurs. Error occurs if
 *   the string is not a valid push swap command.
*/
int	apply_command_to_data(t_ps_data *d, t_dlist *node)
{
	if (ft_strncmp(node->content, "pa\n", 4) == 0)
		ps_pa(d);
	else if (ft_strncmp(node->content, "pb\n", 4) == 0)
		ps_pb(d);
	else if (ft_strncmp(node->content, "ra\n", 4) == 0)
		ps_ra(d);
	else if (ft_strncmp(node->content, "rra\n", 5) == 0)
		ps_rra(d);
	else if (ft_strncmp(node->content, "rb\n", 4) == 0)
		ps_rb(d);
	else if (ft_strncmp(node->content, "rrb\n", 5) == 0)
		ps_rrb(d);
	else if (ft_strncmp(node->content, "sa\n", 4) == 0)
		ps_sa(d);
	else if (ft_strncmp(node->content, "sb\n", 4) == 0)
		ps_sb(d);
	else if (ft_strncmp(node->content, "rr\n", 4) == 0)
		ps_rr(d);
	else if (ft_strncmp(node->content, "rrr\n", 5) == 0)
		ps_rrr(d);
	else
		return (TRUE);
	return (FALSE);
}
