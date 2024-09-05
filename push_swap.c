/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 08:18:57 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/05 13:52:49 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(int *array, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (array[i - 1] > array[i])
			return (false);
		i++;
	}
	return (true);
}

void	main_push_swap(int argc, char **argv)
{
	int		*array_a;
	int		a_size;
	char	**split_argv;

	array_a = NULL;
	a_size = argc - 1;
	split_argv = NULL;
	if (argc == 2)
	{
		a_size = 0;
		split_argv = ft_strsplit(argv[1], ' ');
		while (split_argv[a_size] != NULL)
			a_size++;
		array_a_atoi(&array_a, a_size, split_argv);
		free_tab(split_argv);
	}
	else
		array_a_atoi(&array_a, a_size, argv + 1);
	if (is_sorted(array_a, a_size))
	{
		free(array_a);
		exit(EXIT_SUCCESS);
	}
	ft_push_swap(a_size, array_a);
	free(array_a);
}

// __attribute__((destructor))
// static	void	destructor(void)
// {
// 	system("leaks -q push_swap");
// }

int	main(int argc, char **argv)
{
	main_push_swap(argc, argv);
	return (0);
}

// void	print_t_list_a(t_list *a_head, t_list *a_tail)
// {
// 	if (a_head != NULL)
// 	{
// 		t_list	*tmp_a_head;
// 		t_list	*tmp_a_tail;

// 		printf("a_t_List: ");
// 		tmp_a_head = a_head;
// 		tmp_a_tail = a_tail;
// 		while (tmp_a_head != tmp_a_tail)
// 		{
// 			printf("%d ", tmp_a_head->data);
// 			tmp_a_head = tmp_a_head->next;
// 		}
// 		printf("%d", tmp_a_head->data);
// 		printf("\n");
// 	}
// 	else
// 		printf("Stack_A is NULL!!!!\n");
// }

// void	print_t_list_b(t_list *b_head, t_list *b_tail)
// {
// 	if (b_head != NULL)
// 	{	
// 		t_list	*tmp_b_head;
// 		t_list	*tmp_b_tail;

// 		printf("b_t_List: ");
// 		tmp_b_tail = b_tail;
// 		tmp_b_head = b_head;
// 		while (tmp_b_head != tmp_b_tail)
// 		{
// 			printf("%d ", tmp_b_head->data);
// 			tmp_b_head = tmp_b_head->next;
// 		}
// 		printf("%d", tmp_b_head->data);
// 		printf("\n");
// 	}
// 	else
// 		printf("Stack_B is NULL!!!!\n");
// }

// void	print_a_undermedflag(t_list *a_head, t_list *a_tail)
// {
// 	if (a_head != NULL)
// 	{
// 		t_list	*tmp_a_head;
// 		t_list	*tmp_a_tail;

// 		printf("a_undermed :");
// 		tmp_a_head = a_head;
// 		tmp_a_tail = a_tail;
// 		while (tmp_a_head != tmp_a_tail)
// 		{
// 			printf("%d ", tmp_a_head->separate_flag);
// 			tmp_a_head = tmp_a_head->next;
// 		}
// 		printf("%d", tmp_a_head->separate_flag);
// 		printf("\n");
// 	}else
// 		printf("Stack_A is NULL!!!!\n");
// }

// void	print_b_undermedflag(t_list *b_head, t_list *b_tail)
// {
// 	if (b_head != NULL)
// 	{	
// 		t_list	*tmp_b_head;
// 		t_list	*tmp_b_tail;

// 		printf("b_undermed :");
// 		tmp_b_tail = b_tail;
// 		tmp_b_head = b_head;
// 		while (tmp_b_head != tmp_b_tail)
// 		{
// 			printf("%d ", tmp_b_head->separate_flag);
// 			tmp_b_head = tmp_b_head->next;
// 		}
// 		printf("%d", tmp_b_head->separate_flag);
// 		printf("\n");
// 	}else
// 		printf("Stack_B is NULL!!!!\n");
// }

// void	print_t_list_a_rangeflag(t_list *a_head, t_list *a_tail)
// {
// 	if (a_head != NULL)
// 	{
// 		t_list	*tmp_a_head;
// 		t_list	*tmp_a_tail;

// 		printf("a_ranflag :");
// 		tmp_a_head = a_head;
// 		tmp_a_tail = a_tail;
// 		while (tmp_a_head != tmp_a_tail)
// 		{
// 			printf("%d ", tmp_a_head->range_f);
// 			tmp_a_head = tmp_a_head->next;
// 		}
// 		printf("%d", tmp_a_head->range_f);
// 		printf("\n");
// 	}else
// 		printf("Stack_A is NULL!!!!\n");
// }

// void	print_t_list_b_rangeflag(t_list *b_head, t_list *b_tail)
// {
// 	if (b_head != NULL)
// 	{	
// 		t_list	*tmp_b_head;
// 		t_list	*tmp_b_tail;

// 		printf("b_ranflag :");
// 		tmp_b_tail = b_tail;
// 		tmp_b_head = b_head;
// 		while (tmp_b_head != tmp_b_tail)
// 		{
// 			printf("%d ", tmp_b_head->range_f);
// 			tmp_b_head = tmp_b_head->next;
// 		}
// 		printf("%d", tmp_b_head->range_f);
// 		printf("\n");
// 	}else
// 		printf("Stack_B is NULL!!!!\n");
// }
