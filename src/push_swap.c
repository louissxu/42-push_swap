#include "push_swap.h"

int main(int argc, char **argv)
{
	t_deque l;
	t_deque r;
	t_list *moves;
	bool	err;

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
	if (deque_is_sorted(&l) == true)
	{
		ft_deque_destroy_list(&l, free);
		return (0);
	}
	// debug_print_deque(&l);
	normalise_in_place(&l);
	// debug_print_deque(&l);
	r = ft_deque_new();
	moves = NULL;

	if (ft_deque_length(l) <= 1)
	{
		;
		// ft_printf("debug: sorting 1\n");
	}
	else if (ft_deque_length(l) == 2)
	{
		ps_sort_2_elements(&l, &r, &moves);
		// ft_printf("debug: sorting 2\n");
	}
	else if (ft_deque_length(l) == 3)
	{
		ps_sort_3_elements(&l, &r, &moves);
		// ft_printf("debug: sorting 3\n");
	}
	else if (ft_deque_length(l) == 4)
	{
		ps_sort_4_elements(&l, &r, &moves);
		// ft_printf("debug: sorting 4\n");
	}
	else if (ft_deque_length(l) == 5)
	{
		ps_sort_5_elements(&l, &r, &moves);
		// ft_printf("debug: sorting 5\n");
	}
	else if (ft_deque_length(l) < 50)
	{
		ps_sort_double_radix_sort_improved_with_swaps(&l, &r, &moves);
		// ft_printf("debug: sorting 50\n");
	}
	else if (ft_deque_length(l) < 150)
	{
		ps_sort_100_elements(&l, &r, &moves);
		// ft_printf("debug: sorting 150\n");
	}
	else if (ft_deque_length(l) < 600)
	{
		ps_sort_500_elements(&l, &r, &moves);
		// ft_printf("debug: sorting 600\n");
	}
	else
	{
		ps_sort_double_radix_sort_improved_with_swaps(&l, &r, &moves);
		// ft_printf("debug: sorting >600\n");
	}
	// else
	// {
	// 	ps_sort_double_radix_sort(&l, &r, &moves);
	// }
	// debug_print_list_of_moves(moves);
	t_dlist	*moves_dlist;
	moves_dlist = ps_remove_duplicates(moves);
	// moves_dlist = list_to_dlist(moves);
	debug_print_list_of_moves_dlist(moves_dlist);
	// ft_printf("list len %i    dups removed len %i\n", ft_lstsize(moves), ft_dlist_length(moves_dlist));
	// ft_printf("len before: %i    after duplicate removal: %i\n", ft_lstsize(moves), ft_dlist_length(moves_dlist));
	// debug_print_deque(&l);
	// debug_print_deque(&r);
	// ft_printf("deque l is sorted: %i\n", deque_is_sorted(&l));
	ft_lstclear(&moves, free);
	ft_dlist_destroy_list(moves_dlist, free);
	// ft_printf("debug: length of l is: %i\n", (int)ft_deque_length(l));
	// ft_printf("Number of moves: %i\n", ft_lstsize(moves));
}