/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:50:48 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/05 13:55:04 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>

typedef struct Node
{
	struct Node	*prev;
	int			data;
	int			presort_i;
	bool		separate_flag;
	int			range_f;
	struct Node	*next;
}	t_list;

typedef struct s_list_ptrs
{
	t_list	**h;
	t_list	**t;
}	t_list_ht;

typedef struct stack_list
{
	t_list_ht	a;
	t_list_ht	b;
}	t_list_ht_l;
//main.c
int		main(int argc, char **argv);
//push_swap.c
void	ft_push_swap(int a_size, int *array_a);
///SWAP//////////////////////////////////////////SWAP
//sort_nano_a.c
void	swap_two_a(t_list_ht st_a);
void	swap_three_a(t_list_ht st_a);
void	swap_four_a(t_list_ht st_a, t_list_ht st_b);
void	swap_five_a(t_list_ht st_a, t_list_ht st_b);
//sort_nano_b.c
void	swap_two_b(t_list_ht st_b);
void	swap_three_b(t_list_ht st_b);
//swap_papb.c
void	swap_pa(t_list_ht st_a, t_list_ht st_b);
void	swap_pb(t_list_ht st_a, t_list_ht st_b);
// swap_a.c
void	swap_sa(t_list_ht st_a);
void	swap_ra(t_list_ht st_a);
void	swap_rra(t_list_ht st_a);
// swap_b.c
void	swap_sb(t_list_ht st_b);
void	swap_rb(t_list_ht st_b);
void	swap_rrb(t_list_ht st_b);
//swap_pa_ra.c
void	swap_rb_para(t_list_ht_l stl, int *rra_n, int range, int *w_n);
void	swap_rrb_para(t_list_ht_l stl, int *rra_n, int range);
// writing_swap.c
void	writing_swap(int id);
//SWAP///////////////////////////////////////////SWAP
//ft_atoi_int.c
int		ft_atoi_int(const char *str, int *array_a);
//useful_functions.c
void	print_error(int *array_a);
void	sentinel_stack(t_list_ht st);
void	initialize_list(t_list_ht *list_ht);
// list_function.c
void	t_list_head_add(t_list_ht st, int data);
void	t_list_tail_add(t_list_ht st, int data);
void	t_list_head_del(t_list **head);
void	t_list_tail_del(t_list **tail);
void	connect_tail_to_head(t_list_ht st);
void	print_t_list_a(t_list *a_head, t_list *a_tail);
void	print_t_list_b(t_list *b_head, t_list *b_tail);
//sort_cheack.c
int		sort_check(int stack_size, t_list **head);
//create_node.c
t_list	*create_node(t_list **a_head);
void	array_a_atoi(int **array_a, int a_size, char **argv);
//free_functions.c
void	free_t_list(t_list *head, int a_size);
void	free_list_ht(t_list_ht *list_ht);
void	free_tab(char **tab);

int		find_i_f_t(t_list_ht st, int index);
int		find_i_f_b(t_list_ht st, int index);
int		find_mindata_node(t_list *head, int index, long limit_min);
int		find_min_from_top(t_list_ht st);
int		find_min_presort_i(t_list_ht_l stl, int range);

void	swap_rrr_rrapositive(t_list_ht_l stl, int w_n, int *rra_n);
void	swap_rra_rrapositive(t_list_ht_l stl, int *rra_n);
int		rb_or_rrb_rrapositive(int rb_num, int rrb_num, int rra_num);
void	rra_n_positive(t_list_ht_l stl, int *b_i, int *rra_n);

int		list_len(t_list *a_head, t_list *a_tail);
int		rb_or_rrb(int rb_num, int rrb_num);

// sort_suppourt.c
void	push_b_ra(t_list_ht_l stl, int pbnum, int pbrbnum);
void	while_pa(t_list_ht_l stl, int *b_i, int *rra_n, int range);
void	push_all_a(t_list_ht_l stl, int a_size, int range);
void	while_b_ra(t_list_ht_l stl, int pbnum, int pbrbnum);

void	sort_four_separates(t_list_ht *st_a, t_list_ht *st_b, int a_size);
void	sort_six_separates(t_list_ht *st_a, t_list_ht *st_b, int a_size);
void	sort_eight_separates(t_list_ht *st_a, t_list_ht *st_b, int a_size);
void	sort_ten_separates(t_list_ht *st_a, t_list_ht *st_b, int a_size);
void	sort_twenty_separates(t_list_ht *st_a, t_list_ht *st_b, int a_size);

char	**ft_strsplit(char const *str, char c);
#endif