/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_papb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:50:28 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/05 13:54:41 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_pa(t_list_ht st_a, t_list_ht st_b)
{
	t_list_head_add(st_a, (*st_b.h)->data);
	(*st_a.h)->presort_i = (*st_b.h)->presort_i;
	t_list_head_del(st_b.h);
	writing_swap(5);
	connect_tail_to_head(st_b);
	connect_tail_to_head(st_a);
}

void	swap_pb(t_list_ht st_a, t_list_ht st_b)
{
	t_list_head_add(st_b, (*st_a.h)->data);
	(*st_b.h)->presort_i = (*st_a.h)->presort_i;
	t_list_head_del(st_a.h);
	connect_tail_to_head(st_b);
	if ((*st_b.t)->presort_i == -1)
		t_list_tail_del(st_b.t);
	writing_swap(6);
	connect_tail_to_head(st_b);
	connect_tail_to_head(st_a);
}
