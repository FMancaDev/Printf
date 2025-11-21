# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 15:18:03 by fomanca           #+#    #+#              #
#    Updated: 2025/10/29 11:42:59 by fomanca          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c \
		ft_printf_utils.c

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

CC = gcc

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
