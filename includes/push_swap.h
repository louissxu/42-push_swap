#ifndef PUSH_SWAP_H

# include "deque.h"
# include "libft.h"

void	ps_pb(t_deque *l, t_deque *r, t_list **moves);
void	ps_pa(t_deque *l, t_deque *r, t_list **moves);
void	ps_ra(t_deque *l, t_deque *r, t_list **moves);
void	ps_rra(t_deque *l, t_deque *r, t_list **moves);
void	ps_rb(t_deque *l, t_deque *r, t_list **moves);
void	ps_rrb(t_deque *l, t_deque *r, t_list **moves);
void	ps_sa(t_deque *l, t_deque *r, t_list **moves);

long int	ft_intcmp(const	int *i1, int *i2);

void	ps_sort_2_elements(t_deque *l, t_deque *r, t_list **moves);
void	ps_sort_3_elements(t_deque *l, t_deque *r, t_list **moves);

#endif