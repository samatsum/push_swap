/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_eight_separates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:11:43 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/05 13:54:41 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//   8   1  2 34 5  6   7
void	eight_push_all_b(t_list_ht_l stl)
{
	while_b_ra(stl, 3, 4);
	while_b_ra(stl, 2, 5);
	while_b_ra(stl, 1, 6);
	while_b_ra(stl, 8, 7);
}

void	eight_separater(t_list *current, int a_size)
{
	if (current->presort_i < a_size / 8)
		current->range_f = 1;
	else if (current->presort_i < a_size * 2 / 8)
		current->range_f = 2;
	else if (current->presort_i < a_size * 3 / 8)
		current->range_f = 3;
	else if (current->presort_i < a_size * 4 / 8)
		current->range_f = 4;
	else if (current->presort_i < a_size * 5 / 8)
		current->range_f = 5;
	else if (current->presort_i < a_size * 6 / 8)
		current->range_f = 6;
	else if (current->presort_i < a_size * 7 / 8)
		current->range_f = 7;
	else
		current->range_f = 8;
}

void	eight_range_flagger(t_list_ht st, int a_size)
{
	t_list	*current;

	current = *st.h;
	while (current != *st.t)
	{
		eight_separater(current, a_size);
		current = current->next;
	}
	eight_separater(current, a_size);
}

void	sort_eight_separates(t_list_ht *st_a, t_list_ht *st_b, int a_size)
{
	t_list_ht_l	stl;

	stl.a = *st_a;
	stl.b = *st_b;
	if (sort_check(a_size, stl.a.h) == 0)
		return ;
	sentinel_stack(stl.b);
	eight_range_flagger(stl.a, a_size);
	eight_push_all_b(stl);
	initialize_list(&stl.a);
	push_all_a(stl, a_size, 8);
	*st_a = stl.a;
	*st_b = stl.b;
}
