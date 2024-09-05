/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six_separates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:11:57 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/05 13:54:41 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//        6  1 23 4  5
void	six_push_all_b(t_list_ht_l stl)
{
	while_b_ra(stl, 2, 3);
	while_b_ra(stl, 1, 4);
	while_b_ra(stl, 6, 5);
}

void	six_separater(t_list *current, int a_size)
{
	if (current->presort_i < a_size / 6)
		current->range_f = 1;
	else if (current->presort_i < a_size * 2 / 6)
		current->range_f = 2;
	else if (current->presort_i < a_size * 3 / 6)
		current->range_f = 3;
	else if (current->presort_i < a_size * 4 / 6)
		current->range_f = 4;
	else if (current->presort_i < a_size * 5 / 6)
		current->range_f = 5;
	else
		current->range_f = 6;
}

void	six_range_flagger(t_list_ht st, int a_size)
{
	t_list	*current;

	current = *st.h;
	while (current != *st.t)
	{
		six_separater(current, a_size);
		current = current->next;
	}
	six_separater(current, a_size);
}

void	sort_six_separates(t_list_ht *st_a, t_list_ht *st_b, int a_size)
{
	t_list_ht_l	stl;

	stl.a = *st_a;
	stl.b = *st_b;
	if (sort_check(a_size, stl.a.h) == 0)
		return ;
	sentinel_stack(stl.b);
	six_range_flagger(stl.a, a_size);
	six_push_all_b(stl);
	initialize_list(&stl.a);
	push_all_a(stl, a_size, 6);
	*st_a = stl.a;
	*st_b = stl.b;
}
