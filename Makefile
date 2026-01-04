# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taalmeid <taalmeid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/04 15:46:01 by taalmeid          #+#    #+#              #
#    Updated: 2026/01/04 16:35:21 by taalmeid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I../libft -I../ft_printf
RM		= rm -f

SRCS	= main.c \
		  Algorit.c \
		  op.c \
		  sort.c \
		  init_stack.c \
		  operations.c \
		  utilits.c \
		  op2.c \
		  sort_utilits.c \
		  move_utilits.c


OBJS	= $(SRCS:.c=.o)

LIBFT		= ../libft/libft.a
FT_PRINTF	= ../ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ../libft

$(FT_PRINTF):
	$(MAKE) -C ../ft_printf

clean:
	$(RM) $(OBJS)
	$(MAKE) -C ../libft clean
	$(MAKE) -C ../ft_printf clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ../libft fclean
	$(MAKE) -C ../ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
