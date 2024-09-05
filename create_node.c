/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 03:10:17 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/05 13:54:41 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(t_list **head)
{
	t_list	*new_list;
	int		i;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (new_list == NULL)
	{
		i = 0;
		while (*head != NULL)
		{
			*head = NULL;
			free(*head);
			*head = (*head)->next;
			i++;
		}
		write(2, "Memory allocation failed.\n", 27);
		exit(1);
	}
	new_list->presort_i = -1;
	new_list->separate_flag = 0;
	new_list->range_f = 0;
	return (new_list);
}
