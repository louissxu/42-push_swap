#ifndef PUSH_SWAP_H

# define UNUSED(x) (void)(x)
# define BOOL int
# define TRUE 1
# define FALSE 0

# include "deque.h"
# include "libft.h"
# include <limits.h>
# include <stdarg.h>

/**
 * @struct t_ps_data
 * A pushswap state. Bundle containing stack a, stack b, and a list of moves.
 *
 * A struct to hold the state of a sort and the moves taken to get there. Used
 * to bundle up the two stacks and the moves list together to be passed around
 * between functions and around the program.
 *
 * @var t_ps_data::a
 *     A deque containing the current state of stack A.
 * @var t_ps_data::b
 *     A deque containing the current state of stack B.
 * @var t_ps_data::m
 *     Pointer to the head of a list containing the list of moves.
 */
typedef struct s_ps_data {
	t_deque	a;
	t_deque	b;
	t_list	*m;
}	t_ps_data;

void	ps_pb(t_ps_data *d);
void	ps_pa(t_ps_data *d);
void	ps_ra(t_ps_data *d);
void	ps_rra(t_ps_data *d);
void	ps_rb(t_ps_data *d);
void	ps_rrb(t_ps_data *d);
void	ps_sa(t_ps_data *d);
void	ps_sb(t_ps_data *d);
void	ps_rr(t_ps_data *d);
void	ps_rrr(t_ps_data *d);

void	debug_print_list(t_list *node);
void	debug_print_list_of_moves(t_list *moves_node);
void	debug_print_dlist(t_dlist *node);
void	debug_print_deque(t_deque *d);


void	ps_sort_2_elements(t_ps_data *d);
void	ps_sort_3_elements(t_ps_data *d);
void	ps_sort_4_elements(t_ps_data *d);
void	ps_sort_5_elements(t_ps_data *d);
void	ps_sort_100_elements(t_ps_data *d);
void	ps_sort_500_elements(t_ps_data *d);
void	ps_sort_radix_sort(t_ps_data *d);
void	ps_sort_double_radix_sort(t_ps_data *d);
void	ps_sort_double_radix_sort_improved(t_ps_data *d);
void	ps_sort_double_radix_sort_improved_with_swaps(t_ps_data *d);

// PS data
void	ps_data_destroy(t_ps_data data);

// PS derived
void	ps_pa_value_optimal(t_ps_data *d, int value);
void	ps_pa_all(t_ps_data *d);
void	ps_pb_value_optimal(t_ps_data *d, int value);

// PS print
void	ps_print_list_of_moves_dlist(t_dlist *d);
void	ps_print_moves(t_ps_data data);

// PS advanced
void	ps_selection_sort_back_with_doubles(t_ps_data *d);

// PS utilities
int		ps_find_distance_to_value(t_deque *stack, int val);
long	ft_intcmp(const	int *i1, int *i2);
// void	list_swap_content(t_list *node_1, t_list *node_2)
t_list	*list_sort_bubble_sort(t_list *l);
t_deque	*ps_normalise_in_place(t_deque *d);
BOOL	deque_has_duplicates(t_deque *d);


// FT math utilities
int		ft_math_abs(int val);

// Type conversions and clones
t_dlist	*ft_list_to_dlist(t_list *list_head, void *(*clone)(void *));
t_list	*ft_deque_to_list(t_deque d, void *(*clone)(void *), \
	void (*del)(void *));
t_deque	ft_clone_deque(t_deque d, void *(*clone)(void *));
int		*clone_heap_integer(int *orig);
void	*clone_heap_integer_void(void *orig);

void	set_pointers_to_null(size_t count, ...);

// Other functions - to rearrange and/or maybe rename
int		ft_pow(int x, int y);
int		calculate_max_radix(int num);
t_dlist	*ps_remove_paired_moves(t_list *l);

// Shared functions needed for checker
t_deque	parse_input_args_to_deque(char **argv, BOOL *err);
BOOL	deque_is_sorted(t_deque *d);

// Checker functions
int		apply_commands_to_stacks(t_ps_data *d, t_dlist *commands_head);
int		apply_command_to_data(t_ps_data *d, t_dlist *node);

#endif