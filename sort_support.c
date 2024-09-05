/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_support.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:11:05 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/05 13:54:41 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_ra(t_list_ht_l stl, int pbnum, int pbrbnum)
{
	int	tmp;

	if ((*stl.a.h)->range_f == pbnum || (*stl.a.h)->range_f == pbrbnum)
	{
		tmp = (*stl.a.h)->range_f;
		if ((*stl.a.h)->range_f == pbrbnum)
		{
			swap_pb(stl.a, stl.b);
			(*stl.b.h)->range_f = tmp;
			swap_rb(stl.b);
		}
		else
		{
			swap_pb(stl.a, stl.b);
			(*stl.b.h)->range_f = tmp;
		}
	}
	else
		swap_ra(stl.a);
}

void	while_pa(t_list_ht_l stl, int *b_i, int *rra_n, int range)
{
	int			w_n;
	int			rb_num;
	int			rrb_num;

	rb_num = find_i_f_t(stl.b, *b_i);
	rrb_num = find_i_f_b(stl.b, *b_i);
	(*b_i)--;
	if (rb_num == -1)
		return ;
	w_n = rb_or_rrb(rb_num, rrb_num);
	if (w_n > 0 || (w_n == 0 && rb_num == 0))
	{
		while (w_n-- > 0)
			swap_rb_para(stl, rra_n, range, &w_n);
		swap_pa(stl.a, stl.b);
	}
	else
	{
		w_n = -w_n;
		while (w_n-- >= 0)
			swap_rrb_para(stl, rra_n, range);
		swap_pa(stl.a, stl.b);
	}
}

void	push_all_a(t_list_ht_l stl, int a_size, int range)
{
	int	b_i;
	int	rra_n;

	b_i = a_size - 1;
	while (range > 0)
	{
		rra_n = 0;
		while ((*stl.b.h)->range_f == range || (*stl.b.t)->range_f == range)
		{
			while_pa(stl, &b_i, &rra_n, range);
			if (b_i == -1)
				break ;
		}
		rra_n_positive(stl, &b_i, &rra_n);
		if (b_i == -1)
			break ;
		b_i = (*stl.a.h)->presort_i - 1;
		range--;
	}
}

void	while_b_ra(t_list_ht_l stl, int pbnum, int pbrbnum)
{
	int		now_a_size;
	long	i;

	i = 0;
	now_a_size = list_len(*stl.a.h, *stl.a.t);
	while (i++ < now_a_size)
		push_b_ra(stl, pbnum, pbrbnum);
}
