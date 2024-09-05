/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions_one.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:50:48 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/05 13:54:41 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(int *array_a)
{
	array_a = NULL;
	free(array_a);
	write(2, "Error\n", 6);
	exit (1);
}

void	sentinel_stack(t_list_ht st)
{
	if (st.h == NULL)
	{
		t_list_head_add(st, 0);
		(*st.h)->presort_i = -1;
		connect_tail_to_head(st);
	}
}

void	initialize_list(t_list_ht *list_ht)
{
	if (list_ht->h != NULL)
	{
		free(list_ht->h);
		list_ht->h = NULL;
	}
	if (list_ht->t != NULL)
	{
		free(list_ht->t);
		list_ht->t = NULL;
	}
	list_ht->h = (t_list **)malloc(sizeof(t_list *));
	list_ht->t = (t_list **)malloc(sizeof(t_list *));
	if (list_ht->h == NULL || list_ht->t == NULL)
	{
		write(2, "Memory allocation failed.\n", 27);
		exit(1);
	}
	*list_ht->h = NULL;
	*list_ht->t = NULL;
}
