# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarole <acarole@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 14:27:56 by acarole           #+#    #+#              #
#    Updated: 2019/11/03 22:21:51 by eleanna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	main.c	fill_struct.c check.c

OBJ = $(SRC:.c=.o)

HDR = fillit.h

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	gcc -I . -Wall -Wextra -o $(NAME) $(OBJ) $(LIB) -I .

%.o: %.c
	gcc -I . -Wall -Wextra -o $@ -c $<

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
