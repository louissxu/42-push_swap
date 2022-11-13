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

static int	print_string_and_data_destroy_and_return(\
	char *output_str, t_ps_data data, int return_val)
{
	ft_printf("%s", output_str);
	ps_data_destroy(data);
	return (return_val);
}

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
		print_string_and_data_destroy_and_return("Error\n", data, 0);
	if (deque_has_duplicates(&data.a) == TRUE)
		print_string_and_data_destroy_and_return("Error\n", data, 0);
	if (deque_is_sorted(&data.a) == TRUE)
		print_string_and_data_destroy_and_return("", data, 0);
	ps_normalise_in_place(&data.a);
	run_corresponding_ps_sort(&data);
	ps_print_moves(data);
	ps_data_destroy(data);
}
