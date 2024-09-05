/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_pa_ra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:15:17 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/05 13:54:41 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_min_presort_in_range(t_list_ht_l stl, int *rra_n, int *w_n)
{
	if (*stl.b.h != *stl.b.t)
	{
		swap_pa(stl.a, stl.b);
		swap_ra(stl.a);
		(*rra_n)++;
		(*w_n)--;
	}
}

void	swap_rb_para(t_list_ht_l stl, int *rra_n, int range, int *w_n)
{
	t_list		*second;
	t_list		*current;
	int			min_presort_in_range;

	if ((*stl.b.h)->next == *stl.b.h)
		return ;
	min_presort_in_range = find_min_presort_i(stl, range);
	if (min_presort_in_range == (*stl.b.h)->presort_i)
		handle_min_presort_in_range(stl, rra_n, w_n);
	if (*w_n != -1)
	{
		second = (*stl.b.h)->next;
		*stl.b.h = second;
		current = second;
		while (current->next != second)
			current = current->next;
		current->next = *stl.b.h;
		(*stl.b.h)->prev = current;
		writing_swap(2);
		*stl.b.t = (*stl.b.h)->prev;
	}
}

void	swap_rrb_para(t_list_ht_l stl, int *rra_n, int range)
{
	t_list		*last;
	t_list		*current;
	int			min_presort_in_range;

	if ((*stl.b.h)->next == *stl.b.h)
		return ;
	min_presort_in_range = find_min_presort_i(stl, range);
	if (min_presort_in_range == (*stl.b.h)->presort_i)
	{
		if (*stl.b.h != *stl.b.t)
		{
			swap_pa(stl.a, stl.b);
			swap_ra(stl.a);
			(*rra_n)++;
		}
	}
	last = (*stl.b.h)->prev;
	*stl.b.h = last;
	current = last;
	while (current->prev != last)
		current = current->prev;
	current->prev = *stl.b.h;
	(*stl.b.h)->next = current;
	writing_swap(4);
	*stl.b.t = (*stl.b.h)->prev;
}
