# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarole <acarole@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 14:27:56 by acarole           #+#    #+#              #
#    Updated: 2019/11/16 23:29:34 by acarole          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = funs_five.c funs_four.c funs_three.c	funs_two.c	funs_one.c	main.c	fill_struct.c	fill_struct_too.c	check.c

OBJ = $(SRC:.c=.o)

HDR = fillit.h

LIB = libft/check_bit.c	libft/clear_bit.c	libft/ft_atoi.c	libft/ft_memmove.c	libft/ft_putchar_fd.c libft/ft_putnbr_fd.c	libft/ft_putstr.c	libft/ft_putstr_fd.c	libft/ft_strjoin.c	libft/ft_strlen.c	libft/ft_strnew.c	libft/get_next_line.c	libft/set_bit.c libft/ft_putchar.c	libft/ft_strchr.c	libft/ft_strdup.c	libft/ft_strsub.c

all: $(NAME)

$(NAME): $(OBJ)
	gcc -I . -g -Wall -Wextra -o $(NAME) $(OBJ) $(LIB) -I .

%.o: %.c
	gcc -I . -Wall -Wextra -o $@ -c $<

clean:
	@/bin/rm -f *.o
	@/bin/rm -f libft/*.o

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft/libft.a
re: fclean all
