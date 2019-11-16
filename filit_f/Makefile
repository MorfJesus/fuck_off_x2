# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarole <acarole@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 14:27:56 by acarole           #+#    #+#              #
#    Updated: 2019/11/16 16:12:51 by acarole          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit2

SRC =	main_Ne_pidor.c	fill_struct.c	fill_struct_too.c	check.c

OBJ = $(SRC:.c=.o)

HDR = fillit.h

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	gcc -I . -g -Wall -Wextra -o $(NAME) $(OBJ) $(LIB) -I .

%.o: %.c
	gcc -I . -Wall -Wextra -o $@ -c $<

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
