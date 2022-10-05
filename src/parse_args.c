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

BOOL	str_is_valid_integer(char *str, int *dest)
{
	int		i;
	int		num_len;
	long	val;
	BOOL	is_negative;

	i = 0;
	num_len = 0;
	val = 0;
	is_negative = FALSE;
	if (str[i] == '-')
	{
		i++;
		is_negative = TRUE;
		if (str[i] == '\0')
		{
			return (FALSE);
		}
	}
	while (str[i] == '0')
	{
		i++;
	}
	while (str[i] && num_len < 10)
	{
		if (ft_isinstr(str[i], "0123456789") == 0)
		{
			return (FALSE);
		}
		val *= 10;
		val += str[i] - '0';
		i++;
		num_len++;
	}
	if (is_negative == TRUE)
	{
		val *= -1;
	}
	if (val > INT_MAX || val < INT_MIN || str[i] != '\0')
	{
		return (FALSE);
	}
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

t_deque	parse_input_args_to_deque(char **argv, BOOL *err)
{
	char	**input_arg;
	int		*num;
	BOOL	no_err;
	t_deque	d;
	char	**split_args;
	size_t	i;

	*err = FALSE;
	d = ft_deque_new();
	input_arg = &argv[1];
	while (*input_arg)
	{
		split_args = ft_split(*input_arg, ' ');
		i = 0;
		while (split_args[i])
		{
			num = malloc(sizeof (*num) * 1);
			if (!num)
			{
				break ;
			}
			no_err = str_is_valid_integer(split_args[i], num);
			if (no_err == FALSE)
			{
				ft_deque_destroy_list(&d, free);
				free(num);
				*err = TRUE;
				clear_table(split_args);
				return (d);
			}
			ft_deque_append(&d, num);
			i++;
		}
		clear_table(split_args);
		// *num = ft_atoi(*input_arg);
		input_arg++;
	}
	return (d);
}

BOOL	deque_has_duplicates(t_deque *d)
{
	t_list	*l;
	t_list	*node;

	l = ft_deque_to_list(*d, clone_heap_integer_void, free);
	list_sort_bubble_sort(l);
	node = l;
	if (node == NULL)
	{
		return (FALSE);
	}
	if (node->next == NULL)
	{
		return (FALSE);
	}
	while (node && node->next)
	{
		if (*(int *)node->content == *(int *)node->next->content)
		{
			ft_lstclear(&l, free);
			return (TRUE);
		}
		node = node->next;
	}
	ft_lstclear(&l, free);
	return (FALSE);
}

BOOL	deque_is_sorted(t_deque *d)
{
	t_dlist	*node;

	node = d->head;
	if (node == NULL)
	{
		return (TRUE);
	}
	if (node->next == NULL)
	{
		return (TRUE);
	}
	while (node && node->next)
	{
		if (*(int *)node->content <= *(int *)node->next->content)
		{
			;
		}
		else
		{
			return FALSE;
		}
		node = node->next;
	}
	return TRUE;
}
