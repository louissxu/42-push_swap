#include "push_swap.h"

void	ps_pb(t_deque *l, t_deque *r, t_list **moves)
{
	void	*tmp;

	tmp = ft_deque_popleft(l);
	ft_deque_appendleft(r, tmp);
	ft_lstadd_back(moves, ft_lstnew(ft_strdup("pb")));
}

void	ps_pa(t_deque *l, t_deque *r, t_list **moves)
{
	void	*tmp;

	tmp = ft_deque_popleft(r);
	ft_deque_appendleft(l, tmp);
	ft_lstadd_back(moves, ft_lstnew(ft_strdup("pa")));
}

void	ps_ra(t_deque *l, t_deque *r, t_list **moves)
{
	void	*tmp;

	tmp = ft_deque_popleft(l);
	ft_deque_append(l, tmp);
	ft_lstadd_back(moves, ft_lstnew(ft_strdup("ra")));
}

void	ps_rra(t_deque *l, t_deque *r, t_list **moves)
{
	void	*tmp;

	tmp = ft_deque_pop(l);
	ft_deque_appendleft(l, tmp);
	ft_lstadd_back(moves, ft_lstnew(ft_strdup("rra")));
}

void	ps_rb(t_deque *l, t_deque *r, t_list **moves)
{
	void	*tmp;

	tmp = ft_deque_popleft(r);
	ft_deque_append(r, tmp);
	ft_lstadd_back(moves, ft_lstnew(ft_strdup("rb")));
}

void	ps_rrb(t_deque *l, t_deque *r, t_list **moves)
{
	void	*tmp;

	tmp = ft_deque_pop(r);
	ft_deque_appendleft(r, tmp);
	ft_lstadd_back(moves, ft_lstnew(ft_strdup("rrb")));
}

void	ps_sa(t_deque *l, t_deque *r, t_list **moves)
{
	void	*tmp_0;
	void	*tmp_1;

	if (ft_deque_length(*l) >= 2)
	{
		tmp_0 = ft_deque_popleft(l);
		tmp_1 = ft_deque_popleft(l);
		ft_deque_appendleft(l, tmp_0);
		ft_deque_appendleft(l, tmp_1);
	}
	ft_lstadd_back(moves, ft_lstnew(ft_strdup("sa")));
}