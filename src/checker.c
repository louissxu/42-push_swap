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
 * @brief Reads in the string commands from stdin and stores them in a dlist
 * 
 * Reads in the value from get_next_line until the end of the stdin is reached
 * (EOF char reached). Populates the result dlist with each command with one
 * command per line. This will be read later by the checker.
 * 
 * The commands are not sanitised. At this stage, any string is accepted and
 * placed within the dlist to be parsed later.
 * 
 * @return dlist populated with the commands. One line per dlist node.
*/
static t_dlist	*read_commands_from_stdin(void)
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

/**
 * @brief Clean up. Refactored out of the main due to function line limit
 * 
 * Does the clean up at the end of the main function. Clears out the data in a
 * ps_data struct and clears out a dlist filled with commands.
 * 
 * @param d ps_data struct to be cleared.
 * @param commands commands list to be cleared.
*/
static void	clean_up(t_ps_data *d, t_dlist *commands)
{
	ft_deque_destroy_list(&d->a, free);
	ft_deque_destroy_list(&d->b, free);
	ft_lstclear(&d->m, free);
	ft_dlist_destroy_list(commands, free);
	return ;
}

/**
 * @brief Checks error flag and value of the result. Prints to stdout the result
 * 
 * Checks the error flag and prints error response if error is true. Then if no
 * error it checks the ps_data struct to see if it is sorted and prints the
 * appropriate result (OK if sorted, KO if not sorted).
 * 
 * @param err Boolean data. True if error.
 * @param d ps_data struct containing the state after the moves have been
 *   applied.
*/
static void	check_and_print_result(BOOL err, t_ps_data *d)
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

/**
 * @brief Set up starting ars of the checker program
 * 
 * Sets up some of the starting args. Primarily to save lines for norm limits.
 * 
 * @param err A pointer to the err variable to be set to starting values.
 * @param d A pointer to the ps_data to be set to starting values.
*/
static void	set_up(BOOL *err, t_ps_data *d)
{
	*err = FALSE;
	d->a = ft_deque_new();
	d->b = ft_deque_new();
	d->m = NULL;
}

/**
 * @brief Main function of the checker program
 * 
 * A program to check if a list of commands adequately sorts a given stack.
 * First parses arguments to populate the stack. Checks the stack for errors and
 * fails appropriately.
 * 
 * Then takes commands from stdin. Then applies these commands to the stack and
 * prints the correct response depending on whether these commands are valid and
 * whether they sort the stack.
 * 
 * @param argc Arg count.
 * @param argv Strings containing the starting stack values.
*/
int	main(int argc, char **argv)
{
	t_ps_data	d;
	t_dlist		*commands;
	BOOL		err;

	if (argc == 1)
		return (0);
	set_up(&err, &d);
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
