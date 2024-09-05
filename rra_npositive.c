/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_npositive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:56:57 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/01 23:41:37 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_rrr_rrapositive(t_list_ht_l stl, int w_n, int *rra_n)
{
	if (*rra_n > 0)
	{
		while (*rra_n > 0 && w_n-- > 0)
		{
			swap_rra(stl.a);
			swap_rrb(stl.b);
			(*rra_n)--;
		}
		if (*rra_n > 0)
			while ((*rra_n)-- > 0)
				swap_rra(stl.a);
	}
}

void	swap_rra_rrapositive(t_list_ht_l stl, int *rra_n)
{
	if (*rra_n > 0)
		while ((*rra_n)-- > 0)
			swap_rra(stl.a);
}

int	rb_or_rrb_rrapositive(int rb_num, int rrb_num, int rra_num)
{
	if (rrb_num - rra_num > rb_num)
		return (rb_num);
	else
		return (-rrb_num);
}

void	rra_n_positive(t_list_ht_l stl, int *b_i, int *rra_n)
{
	int			w_n;
	int			rb_num;
	int			rrb_num;

	rb_num = find_i_f_t(stl.b, *b_i);
	rrb_num = find_i_f_b(stl.b, *b_i);
	w_n = rb_or_rrb_rrapositive(rb_num, rrb_num, *rra_n);
	if (w_n > 0 || (w_n == 0 && rb_num == 0))
		swap_rra_rrapositive(stl, rra_n);
	else
		swap_rrr_rrapositive(stl, -w_n, rra_n);
}
