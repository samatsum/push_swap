/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:44:59 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/05 13:54:41 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	big_or_small(long a, long b)
{
	if (a > b)
		return (-2);
	return (0);
}

int	sort_check(int stack_size, t_list **head)
{
	int		index;
	int		result;
	t_list	*current;

	index = 0;
	result = 0;
	current = *head;
	while (index < stack_size - 1 && current->next != NULL)
	{
		result = big_or_small(current->presort_i, current->next->presort_i);
		if (result == -2)
			return (result);
		current = current->next;
		index++;
	}
	return (0);
}
