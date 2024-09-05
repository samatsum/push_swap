/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_data_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:56:42 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/05 13:54:41 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_i_f_t(t_list_ht st, int index)
{
	int		position;
	int		find_flag;
	t_list	*current;

	position = 0;
	current = *st.h;
	find_flag = 0;
	while (current != *st.t)
	{
		if (current->presort_i == index)
		{
			find_flag = 1;
			break ;
		}
		current = current->next;
		position++;
	}
	if (current->presort_i == index)
		find_flag = 1;
	if (find_flag == 0)
		return (-1);
	return (position);
}

int	find_i_f_b(t_list_ht st, int index)
{
	t_list	*current;
	int		position;

	position = 0;
	current = *st.t;
	while (current != *st.h)
	{
		if (current->presort_i == index)
			break ;
		current = current->prev;
		position++;
	}
	return (position);
}

int	find_mindata_node(t_list *head, int index, long limit_min)
{
	t_list	*current;
	t_list	*tmp;
	int		min;

	current = head;
	min = INT_MAX;
	tmp = NULL;
	while (current != head->prev)
	{
		if (current->data <= min && (long)current->data > limit_min)
		{
			tmp = current;
			min = current->data;
		}
		current = current->next;
	}
	if (current->data <= min && (long)current->data > limit_min)
	{
		tmp = current;
		min = current->data;
	}
	tmp->presort_i = index;
	return (min);
}

int	find_min_from_top(t_list_ht st)
{
	t_list	*current;
	int		index;
	int		min_index;
	int		min_value;

	current = *st.h;
	min_value = current->presort_i;
	min_index = 0;
	index = 0;
	while (current != *st.t)
	{
		if (current->presort_i < min_value)
		{
			min_value = current->presort_i;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	if (current->presort_i < min_value)
	{
		min_value = current->presort_i;
		min_index = index;
	}
	return (min_index);
}

int	find_min_presort_i(t_list_ht_l stl, int range)
{
	int		min_presort_i;
	t_list	*current;

	min_presort_i = INT_MAX;
	current = *stl.b.h;
	while (current != *stl.b.t)
	{
		if (current->range_f == range)
			if (min_presort_i > current->presort_i)
				min_presort_i = current->presort_i;
		current = current->next;
	}
	if (current->range_f == range)
		if (min_presort_i > current->presort_i)
			min_presort_i = current->presort_i;
	return (min_presort_i);
}
