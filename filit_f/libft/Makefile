# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarole <acarole@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 14:27:56 by acarole           #+#    #+#              #
#    Updated: 2019/11/03 18:48:55 by eleanna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	clear_bit.c	set_bit.c	check_bit.c	get_next_line.c		ft_islower.c	ft_isupper.c	ft_lstadd_back.c	ft_abs.c	ft_lst_last.c	ft_lstmap.c		ft_lstadd.c     ft_lstdel.c     ft_lstdelone.c  ft_lstiter.c    ft_lstnew.c	ft_strsplit.c	ft_memmove.c	ft_strlcat.c	ft_isprint.c	ft_putchar.c	ft_strchr.c	ft_strjoin.c	ft_strnew.c		ft_itoa.c	ft_putchar_fd.c	ft_strclr.c		ft_strnstr.c	ft_memalloc.c	ft_putendl.c	ft_strcmp.c	ft_strlen.c	ft_strrchr.c	ft_atoi.c	ft_memccpy.c	ft_putendl_fd.c	ft_strcpy.c	ft_strmap.c	ft_strstr.c	ft_bzero.c	ft_memchr.c	ft_putnbr.c	ft_strdel.c	ft_strmapi.c	ft_strsub.c	ft_isalnum.c	ft_memcmp.c		ft_strdup.c	ft_strncat.c	ft_strtrim.c	ft_isalpha.c	ft_memcpy.c	ft_putstr.c	ft_strequ.c	ft_strncmp.c	ft_tolower.c	ft_isascii.c	ft_memdel.c	ft_putstr_fd.c	ft_striter.c	ft_strncpy.c	ft_toupper.c	ft_isdigit.c	ft_memset.c	ft_strcat.c	ft_striteri.c	ft_strnequ.c	ft_putnbr_fd.c	ft_putnbr.c

SRCO = $(SRC:.c=.o)

HDR = libft.h

LIB = libft.a

all: $(NAME)

$(NAME): $(SRCO)
	@ar rc $(NAME) $(SRCO)

%.o: %.c
	gcc -c -I . -Wall -Wextra -Werror $< -o $@

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
