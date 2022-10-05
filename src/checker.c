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

t_dlist *read_commands_from_stdin(void)
{
	t_dlist *commands;
	char *new_line;

	commands = NULL;
	new_line = get_next_line(0);
	while (new_line)
	{
		ft_dlist_insert_end(&commands, ft_dlist_new_node(new_line));
		new_line = get_next_line(0);
	}
	return (commands);
}

int apply_commands_to_stacks(t_ps_data *d, t_dlist *commands_head)
{
	t_dlist *node;

	node = commands_head;
	while (node)
	{
		if (ft_strncmp(node->content, "pa\n", 4) == 0)
		{
			ps_pa(d);
		}
		else if (ft_strncmp(node->content, "pb\n", 4) == 0)
		{
			ps_pb(d);
		}
		else if (ft_strncmp(node->content, "ra\n", 4) == 0)
		{
			ps_ra(d);
		}
		else if (ft_strncmp(node->content, "rra\n", 5) == 0)
		{
			ps_rra(d);
		}
		else if (ft_strncmp(node->content, "rb\n", 4) == 0)
		{
			ps_rb(d);
		}
		else if (ft_strncmp(node->content, "rrb\n", 5) == 0)
		{
			ps_rrb(d);
		}
		else if (ft_strncmp(node->content, "sa\n", 4) == 0)
		{
			ps_sa(d);
		}
		else if (ft_strncmp(node->content, "sb\n", 4) == 0)
		{
			ps_sb(d);
		}
		else if (ft_strncmp(node->content, "rr\n", 4) == 0)
		{
			ps_rr(d);
		}
		else if (ft_strncmp(node->content, "rrr\n", 5) == 0)
		{
			ps_rrr(d);
		}
		else
		{
			return (true);
		}
		node = node->next;
	}
	return (false);
}

void clean_up(t_ps_data *d, t_dlist *commands)
{
	ft_deque_destroy_list(&d->a, free);
	ft_deque_destroy_list(&d->b, free);
	ft_lstclear(&d->m, free);
	ft_dlist_destroy_list(commands, free);
	return;
}

void check_and_print_result(bool err, t_ps_data *d)
{
	if (err == true)
	{
		write(2, "Error\n", 6);
	}
	else
	{
		if (deque_is_sorted(&d->a) == 1 && ft_deque_length(d->b) == 0)
		{
			ft_printf("OK\n");
		}
		else
		{
			ft_printf("KO\n");
		}
	}
}

int main(int argc, char **argv)
{
	t_ps_data d;
	t_dlist *commands;
	bool err;

	if (argc == 1)
	{
		return (0);
	}
	err = false;
	d.a = parse_input_args_to_deque(argv, &err);
	if (err)
	{
		ft_deque_destroy_list(&d.a, free);
		write(2, "Error\n", 6);
		return (0);
	}
	if (deque_has_duplicates(&d.a) == true)
	{
		ft_deque_destroy_list(&d.a, free);
		write(2, "Error\n", 6);
		return (0);
	}
	commands = read_commands_from_stdin();
	err = apply_commands_to_stacks(&d, commands);
	check_and_print_result(err, &d);
	clean_up(&d, commands);
	return (0);
}
