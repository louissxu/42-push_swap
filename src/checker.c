#include "push_swap.h"

int main(int argc, char** argv)
{
	t_deque	l;
	t_deque	r;
	t_dlist	*commands;
	bool	err;
	char	*new_line;
	t_dlist	*node;
	t_list	*bin_moves;

	if (argc == 1)
	{
		return (0);
	}
	err = false;
	l = parse_input_args_to_deque(argv, &err);
	if (err)
	{
		ft_deque_destroy_list(&l, free);
		write(2, "Error\n", 6);
		return (0);
	}
	if (deque_has_duplicates(&l) == true)
	{
		write(2, "Error\n", 6);
		ft_deque_destroy_list(&l, free);
		return (0);
	}
	commands = NULL;
	new_line = get_next_line(0);
	while (new_line)
	{
		ft_dlist_insert_end(&commands, ft_dlist_new_node(new_line));
		new_line = get_next_line(0);
	}
	node = commands;
	while (node)
	{
		if (ft_strncmp(node->content, "pa\n", 4) == 0)
		{
			ps_pa(&l, &r, &bin_moves);
		}
		else if (ft_strncmp(node->content, "pb\n", 4) == 0)
		{
			ps_pb(&l, &r, &bin_moves);
		}
		else if (ft_strncmp(node->content, "ra\n", 4) == 0)
		{
			ps_ra(&l, &r, &bin_moves);
		}
		else if (ft_strncmp(node->content, "rra\n", 5) == 0)
		{
			ps_rra(&l, &r, &bin_moves);
		}
		else if (ft_strncmp(node->content, "rb\n", 4) == 0)
		{
			ps_rb(&l, &r, &bin_moves);
		}
		else if (ft_strncmp(node->content, "rrb\n", 5) == 0)
		{
			ps_rrb(&l, &r, &bin_moves);
		}
		else if (ft_strncmp(node->content, "sa\n", 4) == 0)
		{
			ps_sa(&l, &r, &bin_moves);
		}
		else if (ft_strncmp(node->content, "sb\n", 4) == 0)
		{
			ps_sb(&l, &r, &bin_moves);
		}
		else if (ft_strncmp(node->content, "rr\n", 4) == 0)
		{
			ps_rr(&l, &r, &bin_moves);
		}
		else if (ft_strncmp(node->content, "rrr\n", 5) == 0)
		{
			ps_rrr(&l, &r, &bin_moves);
		}
		else
		{
			// clean up
			ft_deque_destroy_list(&l, free);
			ft_deque_destroy_list(&r, free);
			ft_dlist_destroy_list(commands, free);
			ft_lstclear(&bin_moves, free);
			// exit with error
			ft_printf("Error\n");
			return (0);
		}
		node = node->next;
	}
	if (deque_is_sorted(&l) == 1 && ft_deque_length(r) == 0)
	{
		ft_printf("OK\n");
		return (0);
	}
	ft_printf("KO\n");

	//clean up
	ft_deque_destroy_list(&l, free);
	ft_deque_destroy_list(&r, free);
	ft_dlist_destroy_list(commands, free);
	ft_lstclear(&bin_moves, free);
}