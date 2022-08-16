#include "push_swap.h"

/**
 * @brief Push_swap command - perform the move: sa (swap a).
 *
 * On a provided ps_data struct perform a sa move.
 * ie. Swap the first two elements at the top of stack a.
 * If there is one or no elements, do nothing.
 * Then append the string name of the move to the list of moves.
 *
 * @param d The stacks to be manipulated and the list of moves to append to.
 */
void	ps_sa(t_ps_data *d)
{
	void	*tmp_0;
	void	*tmp_1;

	if (ft_deque_length(d->a) >= 2)
	{
		tmp_0 = ft_deque_popleft(&d->a);
		tmp_1 = ft_deque_popleft(&d->a);
		ft_deque_appendleft(&d->a, tmp_0);
		ft_deque_appendleft(&d->a, tmp_1);
	}
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("sa")));
}

/**
 * @brief Push_swap command - perform the move: sb (swap b).
 *
 * On a provided ps_data struct perform a sb move.
 * ie. Swap the first two elements at the top of stack b.
 * If there is one or no elements, do nothing.
 * Then append the string name of the move to the list of moves.
 *
 * @param d The stacks to be manipulated and the list of moves to append to.
 */
void	ps_sb(t_ps_data *d)
{
	void	*tmp_0;
	void	*tmp_1;

	if (ft_deque_length(d->b) >= 2)
	{
		tmp_0 = ft_deque_popleft(&d->b);
		tmp_1 = ft_deque_popleft(&d->b);
		ft_deque_appendleft(&d->b, tmp_0);
		ft_deque_appendleft(&d->b, tmp_1);
	}
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("sb")));
}

/**
 * @brief Push_swap command - perform the move: ss (swap a and b).
 * 
 * On a provided ps_data struct perform a ss move.
 * ie. Do sa and sb at the same time.
 * Then append the string name of the move to the list of moves.
 * 
 * @param d The stacks to be manipulated and the list of moves to append to.
 */
void	ps_ss(t_ps_data *d)
{
	void	*tmp_0;
	void	*tmp_1;

	if (ft_deque_length(d->a) >= 2)
	{
		tmp_0 = ft_deque_popleft(&d->a);
		tmp_1 = ft_deque_popleft(&d->a);
		ft_deque_appendleft(&d->a, tmp_0);
		ft_deque_appendleft(&d->a, tmp_1);
	}
	if (ft_deque_length(d->b) >= 2)
	{
		tmp_0 = ft_deque_popleft(&d->b);
		tmp_1 = ft_deque_popleft(&d->b);
		ft_deque_appendleft(&d->b, tmp_0);
		ft_deque_appendleft(&d->b, tmp_1);
	}
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("ss")));
}

/**
 * @brief Push_swap command - perform the move: pa (push a).
 *
 * One a provided ps_data struct perform a pa move.
 * ie. Push top element from stack b to top of stack a.
 * Do nothing if b is empty.
 * Then append the string name of the move to the list of moves.
 *
 * @param d The stacks to be manipulated and the list of moves to append to.
 */
void	ps_pa(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_popleft(&d->b);
	ft_deque_appendleft(&d->a, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("pa")));
}

/**
 * @brief Push_swap command - perform the move: pb (push b).
 *
 * On a provided ps_data struct perform a pb move.
 * ie. Push top element from stack a to top of stack b.
 * Do nothing if a is empty.
 * Then append the string name of the move to the list of moves.
 *
 * @param d The stacks to be manipulated and the list of moves to append to.
 */
void	ps_pb(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_popleft(&d->a);
	ft_deque_appendleft(&d->b, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("pb")));
}

/**
 * @brief Push_swap command - perform the move: ra (rotate a).
 *
 * On a provided ps_data struct perform a ra move.
 * ie. Shift up all elements of stack a by 1.
 * The first element then becomes the last element.
 * Then append the string name of the move to the list of moves.
 *
 * @param d The stacks to be manipulated and the list of moves to append to.
 */
void ps_ra(t_ps_data *d)
{
	void *tmp;

	tmp = ft_deque_popleft(&d->a);
	ft_deque_append(&d->a, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("ra")));
}

/**
 * @brief Push_swap command - perform the move: rb (rotate b).
 *
 * On a provided ps_data struct perform a rb move.
 * ie. Shift up all elements of stack b by 1.
 * The first element then becomes the last element.
 * Then append the string name of the move to the list of moves.
 *
 * @param d The stacks to be manipulated and the list of moves to append to.
 */
void	ps_rb(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_popleft(&d->b);
	ft_deque_append(&d->b, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("rb")));
}

/**
 * @brief Push_swap command - perform the move: rr (rotate a and b).
 *
 * On a provided ps_data struct perform a rr move.
 * ie. Do ra and rb at the same time.
 * Then append the string name of the move to the list of moves.
 *
 * @param d The stacks to be manipulated and the list of moves to append to.
 */
void	ps_rr(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_popleft(&d->a);
	ft_deque_append(&d->a, tmp);
	tmp = ft_deque_popleft(&d->b);
	ft_deque_append(&d->b, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("rr")));
}

/**
 * @brief Push_swap command - perform the move: rra (reverse rotate a).
 *
 * On a provided ps_data struct perform a rra move.
 * ie. Shift down all elements of stack a by 1.
 * The last element then becomes the first element.
 * Then append the string name of the move to the list of moves.
 *
 * @param d The stacks to be manipulated and the list of moves to append to.
 */
void	ps_rra(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_pop(&d->a);
	ft_deque_appendleft(&d->a, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("rra")));
}

/**
 * @brief Push_swap command - perform the move: rrb (reverse rotate b).
 *
 * On a provided ps_data struct perform a rrb move.
 * ie. Shift down all elements of stack b by 1.
 * The last element then becomes the first element.
 * Then append the string name of the move to the list of moves.
 *
 * @param d The stacks to be manipulated and the list of moves to append to.
 */
void	ps_rrb(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_pop(&d->b);
	ft_deque_appendleft(&d->b, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("rrb")));
}

/**
 * @brief Push_swap command - perform the move: rrr (reverse rotate a and b).
 *
 * On a provided ps_data struct perform a rrr move.
 * ie. Do rra and rrb at the same time.
 * Then append the string name of the move to the list of moves.
 *
 * @param d The stacks to be manipulated and the list of moves to append to.
 */
void	ps_rrr(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_pop(&d->a);
	ft_deque_appendleft(&d->a, tmp);
	tmp = ft_deque_pop(&d->b);
	ft_deque_appendleft(&d->b, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("rrr")));
}
