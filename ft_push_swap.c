/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:50:48 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/01 23:28:18 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_by_size(int a_size, t_list_ht st_a)
{
	int		index;
	long	limit_min;

	limit_min = -2147483648 - 1;
	index = 0;
	while (index++ < a_size)
		limit_min = find_mindata_node(*st_a.h, index - 1, limit_min);
}

void	sort_type_classification(int a_size, t_list_ht *st_a, t_list_ht st_b)
{
	if (a_size == 2)
		swap_two_a(*st_a);
	else if (a_size == 3)
		swap_three_a(*st_a);
	else if (a_size == 4)
		swap_four_a(*st_a, st_b);
	else if (a_size == 5)
		swap_five_a(*st_a, st_b);
	else if (a_size >= 6 && a_size <= 30)
		sort_four_separates(st_a, &st_b, a_size);
	else if (a_size >= 31 && a_size <= 50)
		sort_six_separates(st_a, &st_b, a_size);
	else if (a_size >= 51 && a_size <= 150)
		sort_eight_separates(st_a, &st_b, a_size);
	else if (a_size >= 151 && a_size <= 325)
		sort_ten_separates(st_a, &st_b, a_size);
	else if (a_size >= 326)
		sort_twenty_separates(st_a, &st_b, a_size);
}

void	swapping(int a_size, t_list_ht *st_a)
{
	int			index;
	t_list_ht	st_b;

	index = 0;
	st_b.h = NULL;
	st_b.t = NULL;
	initialize_list(&st_b);
	sort_by_size(a_size, *st_a);
	sort_type_classification(a_size, st_a, st_b);
	writing_swap(-1);
	free_list_ht(&st_b);
}

void	ft_push_swap(int a_size, int *array_a)
{
	t_list_ht	st_a;
	int			index;

	st_a.h = NULL;
	st_a.t = NULL;
	index = 0;
	initialize_list(&st_a);
	t_list_head_add(st_a, array_a[index]);
	while (++index < a_size)
		t_list_tail_add(st_a, array_a[index]);
	connect_tail_to_head(st_a);
	swapping(a_size, &st_a);
	free_t_list((*st_a.h), a_size);
	free_list_ht(&st_a);
}
