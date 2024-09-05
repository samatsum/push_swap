/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:50:48 by samatsum          #+#    #+#             */
/*   Updated: 2024/08/30 21:22:01 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_sa(t_list_ht st_a)
{
	t_list	*one;
	t_list	*two;
	int		tmp;

	if ((*st_a.h)->next == *st_a.h)
		return ;
	one = *st_a.h;
	two = (*st_a.h)->next;
	tmp = one->data;
	one->data = two->data;
	two->data = tmp;
	writing_swap(7);
	*st_a.t = (*st_a.h)->prev;
}

void	swap_ra(t_list_ht st_a)
{
	t_list	*second;
	t_list	*current;

	if ((*st_a.h)->next == *st_a.h)
		return ;
	second = (*st_a.h)->next;
	*st_a.h = second;
	current = second;
	while (current->next != second)
		current = current->next;
	current->next = *st_a.h;
	(*st_a.h)->prev = current;
	*st_a.t = (*st_a.h)->prev;
	writing_swap(1);
}

void	swap_rra(t_list_ht st_a)
{
	t_list	*last;
	t_list	*current;

	if ((*st_a.h)->next == *st_a.h)
		return ;
	last = (*st_a.h)->prev;
	*st_a.h = last;
	current = *st_a.h;
	while (current->prev != last)
		current = current->prev;
	current->prev = *st_a.h;
	(*st_a.h)->next = current;
	*st_a.t = (*st_a.h)->prev;
	writing_swap(3);
}
