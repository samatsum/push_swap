/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:12:22 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/02 00:43:48 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	array_a_atoi(int **array_a, int a_size, char **argv)
{
	int	index;
	int	tmp;

	*array_a = (int *)malloc(a_size * sizeof(int));
	if (*array_a == NULL)
	{
		write(2, "Memory allocation failed.\n", 27);
		print_error(*array_a);
	}
	index = 0;
	while (index != a_size)
	{
		(*array_a)[index] = ft_atoi_int(argv[index], *array_a);
		tmp = 0;
		while (tmp++ != index)
			if ((*array_a)[tmp - 1] == (*array_a)[index])
				print_error(*array_a);
		index++;
	}
}

int	list_len(t_list *a_head, t_list *a_tail)
{
	int		index;
	t_list	*current;

	index = 0;
	current = a_head;
	if (current != NULL)
	{
		index++;
		while (current != a_tail)
		{
			index++;
			current = current->next;
		}
	}
	return (index);
}

int	rb_or_rrb(int rb_num, int rrb_num)
{
	if (rrb_num > rb_num)
		return (rb_num);
	else
		return (-rrb_num);
}
