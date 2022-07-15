#include "push_swap.h"

void	ps_pb(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_popleft(&d->l);
	ft_deque_appendleft(&d->r, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("pb")));
}

void	ps_pa(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_popleft(&d->r);
	ft_deque_appendleft(&d->l, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("pa")));
}

void	ps_ra(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_popleft(&d->l);
	ft_deque_append(&d->l, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("ra")));
}

void	ps_rra(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_pop(&d->l);
	ft_deque_appendleft(&d->l, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("rra")));
}

void	ps_rb(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_popleft(&d->r);
	ft_deque_append(&d->r, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("rb")));
}

void	ps_rrb(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_pop(&d->r);
	ft_deque_appendleft(&d->r, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("rrb")));
}

void	ps_sa(t_ps_data *d)
{
	void	*tmp_0;
	void	*tmp_1;

	if (ft_deque_length(d->l) >= 2)
	{
		tmp_0 = ft_deque_popleft(&d->l);
		tmp_1 = ft_deque_popleft(&d->l);
		ft_deque_appendleft(&d->l, tmp_0);
		ft_deque_appendleft(&d->l, tmp_1);
	}
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("sa")));
}

void	ps_sb(t_ps_data *d)
{
	void	*tmp_0;
	void	*tmp_1;

	if (ft_deque_length(d->r) >= 2)
	{
		tmp_0 = ft_deque_popleft(&d->r);
		tmp_1 = ft_deque_popleft(&d->r);
		ft_deque_appendleft(&d->r, tmp_0);
		ft_deque_appendleft(&d->r, tmp_1);
	}
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("sb")));
}

void	ps_rr(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_popleft(&d->l);
	ft_deque_append(&d->l, tmp);
	tmp = ft_deque_popleft(&d->r);
	ft_deque_append(&d->r, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("rr")));
}

void	ps_rrr(t_ps_data *d)
{
	void	*tmp;

	tmp = ft_deque_pop(&d->l);
	ft_deque_appendleft(&d->l, tmp);
	tmp = ft_deque_pop(&d->r);
	ft_deque_appendleft(&d->r, tmp);
	ft_lstadd_back(&d->m, ft_lstnew(ft_strdup("rrr")));
}
