#ifndef PUSH_SWAP_H

# define UNUSED(x) (void)(x)

# include "deque.h"
# include "libft.h"

void	ps_pb(t_deque *l, t_deque *r, t_list **moves);
void	ps_pa(t_deque *l, t_deque *r, t_list **moves);
void	ps_ra(t_deque *l, t_deque *r, t_list **moves);
void	ps_rra(t_deque *l, t_deque *r, t_list **moves);
void	ps_rb(t_deque *l, t_deque *r, t_list **moves);
void	ps_rrb(t_deque *l, t_deque *r, t_list **moves);
void	ps_sa(t_deque *l, t_deque *r, t_list **moves);

void	debug_print_list(t_list *node);
void	debug_print_list_of_moves(t_list *moves_node);
void	debug_print_dlist(t_dlist *node);
void	debug_print_deque(t_deque *d);

long int	ft_intcmp(const	int *i1, int *i2);

void	ps_sort_2_elements(t_deque *l, t_deque *r, t_list **moves);
void	ps_sort_3_elements(t_deque *l, t_deque *r, t_list **moves);
void	ps_sort_4_elements(t_deque *l, t_deque *r, t_list **moves);
void	ps_sort_5_elements(t_deque *l, t_deque *r, t_list **moves);
void	ps_sort_100_elements(t_deque *l, t_deque *r, t_list **moves);
void	ps_sort_500_elements(t_deque *l, t_deque *r, t_list **moves);
void	ps_sort_radix_sort(t_deque *l, t_deque *r, t_list **moves);
void	ps_sort_double_radix_sort(t_deque *l, t_deque *r, t_list **moves);
void	ps_sort_double_radix_sort_improved(t_deque *l, t_deque *r, t_list **moves);

// PS derived
void	ps_pa_value_optimal(t_deque *l, t_deque *r, t_list **moves, int value);
void	ps_pa_all(t_deque *l, t_deque *r, t_list **moves);

// PS advanced
void	ps_selection_sort_back_with_doubles(t_deque *l, t_deque *r, t_list **moves);

// PS utilities
int	ps_find_distance_to_value(t_deque *stack, int val);

// FT utilities
int	ft_abs(int val);

// Other functions - to rearrange and/or maybe rename
t_deque	clone_deque(t_deque *d);
t_deque	*normalise_in_place(t_deque *d);
int	ft_pow(int x, int y);
int	calculate_max_radix(int num);


int	find_distance_from_val(t_deque *stack, int val);
void	ps_pb_val(t_deque *l, t_deque *r, t_list **moves, int val);

#endif