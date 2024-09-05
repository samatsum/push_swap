/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nano_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:50:48 by samatsum          #+#    #+#             */
/*   Updated: 2024/08/30 21:21:53 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_two_b(t_list_ht st_b)
{
	t_list	*one;
	t_list	*two;

	one = *st_b.h;
	two = (*st_b.h)->next;
	if (one->data < two->data)
		swap_sb(st_b);
}

void	swap_three_b(t_list_ht st_b)
{
	t_list	*one;
	t_list	*two;
	t_list	*three;

	one = *st_b.h;
	two = (*st_b.h)->next;
	three = (*st_b.h)->next->next;
	if (three->data < one->data && one->data < two->data)
		swap_sb(st_b);
	if (one->data < two->data && two->data < three->data)
		swap_sb(st_b);
	if (two->data < three->data && three->data < one->data)
		swap_sb(st_b);
	if (one->data < three->data && three->data < two->data)
		swap_rb(st_b);
	if (two->data < one->data && one->data < three->data)
		swap_rrb(st_b);
}
