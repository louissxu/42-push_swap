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
void	ps_sort_radix(t_deque *l, t_deque *r, t_list **moves);

// Other functions - to rearrange and/or maybe rename
t_deque	clone_deque(t_deque *d);
t_deque	*normalise_in_place(t_deque *d);

int	find_distance_from_val(t_deque *stack, int val);
void	ps_pb_val(t_deque *l, t_deque *r, t_list **moves, int val);

#endif