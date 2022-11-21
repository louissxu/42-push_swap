/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:39:45 by lxu               #+#    #+#             */
/*   Updated: 2022/10/05 12:39:46 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

BOOL	str_is_valid_integer1(char *str, int *i, BOOL *post_multiplier)
{
	*i = 0;
	*post_multiplier = 1;
	if (str[*i] == '-')
	{
		(*i)++;
		*post_multiplier = -1;
		if (str[*i] == '\0')
		{
			return (FALSE);
		}
	}
	while (str[*i] == '0')
	{
		(*i)++;
	}
	return (TRUE);
}

BOOL	str_is_valid_integer(char *str, int *dest)
{
	int		i;
	int		num_len;
	long	val;
	int		post_multiplier;

	num_len = 0;
	val = 0;
	if (str_is_valid_integer1(str, &i, &post_multiplier) == FALSE)
		return (FALSE);
	while (str[i] && num_len < 10)
	{
		if (ft_isinstr(str[i], "0123456789") == 0)
			return (FALSE);
		val *= 10;
		val += str[i] - '0';
		i++;
		num_len++;
	}
	val = val * post_multiplier;
	if (val > INT_MAX || val < INT_MIN || str[i] != '\0')
		return (FALSE);
	*dest = (int)val;
	return (TRUE);
}

void	clear_table(char **table)
{
	size_t	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

BOOL	split_and_poke_arg_into_deque(char *this_arg, t_deque *d)
{
	char	**split_arg;
	size_t	i;
	int		*num;
	BOOL	str_is_valid;

	split_arg = ft_split(this_arg, ' ');
	i = 0;
	while (split_arg[i])
	{
		num = malloc(sizeof (*num) * 1);
		if (!num)
			break ;
		str_is_valid = str_is_valid_integer(split_arg[i], num);
		if (str_is_valid == FALSE)
		{
			ft_deque_destroy_list(d, free);
			free(num);
			clear_table(split_arg);
			return (FALSE);
		}
		ft_deque_append(d, num);
		i++;
	}
	clear_table(split_arg);
	return (TRUE);
}

t_deque	parse_input_args_to_deque(char **argv, BOOL *err)
{
	char	**input_arg;
	t_deque	d;

	*err = FALSE;
	d = ft_deque_new();
	input_arg = &argv[1];
	while (*input_arg)
	{
		*err = !split_and_poke_arg_into_deque(*input_arg, &d);
		if (*err == TRUE)
		{
			return (d);
		}
		input_arg++;
	}
	return (d);
}
