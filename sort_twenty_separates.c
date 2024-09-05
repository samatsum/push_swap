/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_twenty_separates.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:20:35 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/05 13:54:41 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	twenty_push_all_b(t_list_ht_l stl)
{
	while_b_ra(stl, 9, 10);
	while_b_ra(stl, 8, 11);
	while_b_ra(stl, 7, 12);
	while_b_ra(stl, 6, 13);
	while_b_ra(stl, 5, 14);
	while_b_ra(stl, 4, 15);
	while_b_ra(stl, 3, 16);
	while_b_ra(stl, 2, 17);
	while_b_ra(stl, 1, 18);
	while_b_ra(stl, 20, 19);
}

void	twenty_separater_one(t_list *current, int a_size)
{
	if (current->presort_i < a_size / 20)
		current->range_f = 1;
	else if (current->presort_i < a_size * 2 / 20)
		current->range_f = 2;
	else if (current->presort_i < a_size * 3 / 20)
		current->range_f = 3;
	else if (current->presort_i < a_size * 4 / 20)
		current->range_f = 4;
	else if (current->presort_i < a_size * 5 / 20)
		current->range_f = 5;
	else if (current->presort_i < a_size * 6 / 20)
		current->range_f = 6;
	else if (current->presort_i < a_size * 7 / 20)
		current->range_f = 7;
	else if (current->presort_i < a_size * 8 / 20)
		current->range_f = 8;
	else if (current->presort_i < a_size * 9 / 20)
		current->range_f = 9;
	else if (current->presort_i < a_size * 10 / 20)
		current->range_f = 10;
}

void	twenty_separater_two(t_list *current, int a_size)
{
	if (current->presort_i < a_size * 11 / 20 && current->range_f == 0)
		current->range_f = 11;
	else if (current->presort_i < a_size * 12 / 20 && current->range_f == 0)
		current->range_f = 12;
	else if (current->presort_i < a_size * 13 / 20 && current->range_f == 0)
		current->range_f = 13;
	else if (current->presort_i < a_size * 14 / 20 && current->range_f == 0)
		current->range_f = 14;
	else if (current->presort_i < a_size * 15 / 20 && current->range_f == 0)
		current->range_f = 15;
	else if (current->presort_i < a_size * 16 / 20 && current->range_f == 0)
		current->range_f = 16;
	else if (current->presort_i < a_size * 17 / 20 && current->range_f == 0)
		current->range_f = 17;
	else if (current->presort_i < a_size * 18 / 20 && current->range_f == 0)
		current->range_f = 18;
	else if (current->presort_i < a_size * 19 / 20 && current->range_f == 0)
		current->range_f = 19;
	else if (current->presort_i < a_size && current->range_f == 0)
		current->range_f = 20;
}

void	twenty_range_flagger(t_list_ht st, int a_size)
{
	t_list	*current;

	current = *st.h;
	while (current != *st.t)
	{
		twenty_separater_one(current, a_size);
		twenty_separater_two(current, a_size);
		current = current->next;
	}
	twenty_separater_one(current, a_size);
	twenty_separater_two(current, a_size);
}

void	sort_twenty_separates(t_list_ht *st_a, t_list_ht *st_b, int a_size)
{
	t_list_ht_l	stl;

	stl.a = *st_a;
	stl.b = *st_b;
	if (sort_check(a_size, stl.a.h) == 0)
		return ;
	sentinel_stack(stl.b);
	twenty_range_flagger(stl.a, a_size);
	twenty_push_all_b(stl);
	initialize_list(&stl.a);
	push_all_a(stl, a_size, 20);
	*st_a = stl.a;
	*st_b = stl.b;
}
