/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ten_separates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:12:06 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/05 13:54:41 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//   10   1  2  3 45 6  7  8   9
void	ten_push_all_b(t_list_ht_l stl)
{
	while_b_ra(stl, 4, 5);
	while_b_ra(stl, 3, 6);
	while_b_ra(stl, 2, 7);
	while_b_ra(stl, 1, 8);
	while_b_ra(stl, 10, 9);
}

void	ten_separater(t_list *current, int a_size)
{
	if (current->presort_i < a_size / 10)
		current->range_f = 1;
	else if (current->presort_i < a_size * 2 / 10)
		current->range_f = 2;
	else if (current->presort_i < a_size * 3 / 10)
		current->range_f = 3;
	else if (current->presort_i < a_size * 4 / 10)
		current->range_f = 4;
	else if (current->presort_i < a_size * 5 / 10)
		current->range_f = 5;
	else if (current->presort_i < a_size * 6 / 10)
		current->range_f = 6;
	else if (current->presort_i < a_size * 7 / 10)
		current->range_f = 7;
	else if (current->presort_i < a_size * 8 / 10)
		current->range_f = 8;
	else if (current->presort_i < a_size * 9 / 10)
		current->range_f = 9;
	else
		current->range_f = 10;
}

void	ten_range_flagger(t_list_ht st, int a_size)
{
	t_list	*current;

	current = *st.h;
	while (current != *st.t)
	{
		ten_separater(current, a_size);
		current = current->next;
	}
	ten_separater(current, a_size);
}

void	sort_ten_separates(t_list_ht *st_a, t_list_ht *st_b, int a_size)
{
	t_list_ht_l	stl;

	stl.a = *st_a;
	stl.b = *st_b;
	if (sort_check(a_size, stl.a.h) == 0)
		return ;
	sentinel_stack(stl.b);
	ten_range_flagger(stl.a, a_size);
	ten_push_all_b(stl);
	initialize_list(&stl.a);
	push_all_a(stl, a_size, 10);
	*st_a = stl.a;
	*st_b = stl.b;
}
