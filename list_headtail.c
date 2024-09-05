/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_headtail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:50:48 by samatsum          #+#    #+#             */
/*   Updated: 2024/08/30 21:21:55 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	t_list_head_add(t_list_ht st, int data)
{
	t_list	*new_node;
	t_list	*current;

	new_node = create_node(st.h);
	new_node->data = data;
	if (*st.h == NULL)
	{
		*st.h = new_node;
		new_node->next = NULL;
		*st.t = new_node;
	}
	else
	{
		current = *st.h;
		current->prev = new_node;
		new_node->next = current;
		*st.h = new_node;
	}
}

void	t_list_tail_add(t_list_ht st, int data)
{
	t_list	*new_node;
	t_list	*current;

	new_node = create_node(st.h);
	new_node->data = data;
	new_node->next = NULL;
	if (*st.t == NULL)
	{
		*st.t = new_node;
		new_node->prev = NULL;
		*st.h = new_node;
	}
	else
	{
		current = *st.t;
		current->next = new_node;
		new_node->prev = current;
		*st.t = new_node;
	}
}

void	t_list_head_del(t_list **head)
{
	t_list	*temp;

	if (*head == NULL)
		return ;
	temp = *head;
	if ((*head)->next == NULL)
	{
		*head = NULL;
	}
	else
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
	}
	free(temp);
}

void	t_list_tail_del(t_list **tail)
{
	t_list	*temp;

	temp = *tail;
	*tail = (*tail)->next;
	(*tail)->prev = temp->prev;
	temp->prev->next = *tail;
	temp = NULL;
	free(temp);
}

void	connect_tail_to_head(t_list_ht st)
{
	if (st.h != NULL && *st.h != NULL && st.t != NULL && *st.t != NULL)
	{
		(*st.t)->next = *st.h;
		(*st.h)->prev = *st.t;
	}
	else
		write(1, "One of the pointers is NULL\n", 28);
}
