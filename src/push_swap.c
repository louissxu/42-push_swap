/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:40:20 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:40:28 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Print string, destroy data struct, and return a value
 * 
 * An internal function/collection of actions. Primarily exists to condense the
 * main function to fit the norm limits.
 * 
 * @param output_str The output string to be printed to console.
 * @param data The data struct to be destroyed.
 * @param return_value The return value to be returned.
 * @return Returns the return value that was passed in.
*/
static int	print_string_and_data_destroy_and_return(\
	char *output_str, t_ps_data data, int return_val)
{
	ft_printf("%s", output_str);
	ps_data_destroy(data);
	return (return_val);
}

/**
 * @brief Runs sort function on data struct
 * 
 * Runs a sort function on a data struct. Runs corresponding most efficient
 * option depending on the starting stack size.
 * 
 * Function sorts in-place and appends the moves onto the passed in data struct.
 * 
 * @param data The data struct containing the stack to be sorted and for the
 *   moves to be recorded within.
*/
static void	run_corresponding_ps_sort(t_ps_data *data)
{
	if (ft_deque_length((*data).a) <= 1)
		return ;
	else if (ft_deque_length((*data).a) == 2)
		ps_sort_2_elements(data);
	else if (ft_deque_length((*data).a) == 3)
		ps_sort_3_elements(data);
	else if (ft_deque_length((*data).a) == 4)
		ps_sort_4_elements(data);
	else if (ft_deque_length((*data).a) == 5)
		ps_sort_5_elements(data);
	else if (ft_deque_length((*data).a) < 50)
		ps_sort_double_radix_sort_improved_with_swaps(data);
	else if (ft_deque_length((*data).a) < 150)
		ps_sort_100_elements(data);
	else if (ft_deque_length((*data).a) < 600)
		ps_sort_500_elements(data);
	else
		ps_sort_double_radix_sort_improved_with_swaps(data);
	return ;
}

/**
 * @brief Main function for the program
 * 
 * Parses args into the stack. Checks if the data is valid and returns an error
 * if appropriate. Then if the data is valid, runs the corresponding sort
 * function and prints the output to the console stdout.
 * 
 * @param argc The count of input args
 * @param argv Vector of the arguments. The arguments are expected to contain
 *   the numbers in the order of the starting state of stack a.
 * @return Returns 0 if successfully exits.
*/
int	main(int argc, char **argv)
{
	BOOL		err;
	t_ps_data	data;

	if (argc == 1)
		return (0);
	err = FALSE;
	data.a = parse_input_args_to_deque(argv, &err);
	data.b = ft_deque_new();
	data.m = NULL;
	if (err)
		return(print_string_and_data_destroy_and_return("Error\n", data, 0));
	if (deque_has_duplicates(&data.a) == TRUE)
		return(print_string_and_data_destroy_and_return("Error\n", data, 0));
	if (deque_is_sorted(&data.a) == TRUE)
		return(print_string_and_data_destroy_and_return("", data, 0));
	ps_normalise_in_place(&data.a);
	run_corresponding_ps_sort(&data);
	ps_print_moves(data);
	ps_data_destroy(data);
}
