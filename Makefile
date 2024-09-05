NAME		=	push_swap

SRCS		=	create_node.c \
				ft_atoi_int.c \
				list_headtail.c \
				push_swap.c \
				ft_push_swap.c \
				swap_a.c \
				swap_b.c \
				swap_pa_ra.c \
				swap_papb.c \
				useful_functions_one.c \
				useful_functions_two.c \
				writing_swap.c \
				find_data_functions.c \
				rra_npositive.c \
				free_functions.c \
				ft_strsplit.c \
				sort_check.c \
				sort_nano_a.c \
				sort_nano_b.c \
				sort_four_separates.c \
				sort_six_separates.c \
				sort_eight_separates.c \
				sort_ten_separates.c \
				sort_twenty_separates.c \
				sort_support.c \
			
OBJS		=	$(SRCS:.c=.o)

CC			=	cc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:		
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean $(NAME)        

.PHONY:			all clean fclean re
