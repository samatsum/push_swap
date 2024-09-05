/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:23:22 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/02 03:24:01 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list_ht(t_list_ht *list_ht)
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
}

void	free_t_list(t_list *head, int a_size)
{
	int		i;

	i = 0;
	while (i < a_size)
	{
		head = head->next;
		free(head);
		i++;
	}
}

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
