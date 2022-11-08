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

t_dlist	*read_commands_from_stdin(void)
{
	t_dlist	*commands;
	char	*new_line;

	commands = NULL;
	new_line = get_next_line(0);
	while (new_line)
	{
		ft_dlist_insert_end(&commands, ft_dlist_new_node(new_line));
		new_line = get_next_line(0);
	}
	return (commands);
}

void	clean_up(t_ps_data *d, t_dlist *commands)
{
	ft_deque_destroy_list(&d->a, free);
	ft_deque_destroy_list(&d->b, free);
	ft_lstclear(&d->m, free);
	ft_dlist_destroy_list(commands, free);
	return ;
}

void	check_and_print_result(BOOL err, t_ps_data *d)
{
	if (err == TRUE)
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

int	main(int argc, char **argv)
{
	t_ps_data	d;
	t_dlist		*commands;
	BOOL		err;

	if (argc == 1)
		return (0);
	err = FALSE;
	d.a = parse_input_args_to_deque(argv, &err);
	if (err)
	{
		ft_deque_destroy_list(&d.a, free);
		write(2, "Error\n", 6);
		return (0);
	}
	if (deque_has_duplicates(&d.a) == TRUE)
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
