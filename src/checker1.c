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
