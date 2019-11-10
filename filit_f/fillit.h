/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:19:24 by eleanna           #+#    #+#             */
/*   Updated: 2019/11/10 22:20:44 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FILLIT_H
#	define FILLIT_H
#include "libft/libft.h"
#include <stdlib.h>

typedef struct		s_fill
{
	short int		height;
	short int		width;
	short int		i;
	short int		j;
	short int		border;
	int				n;
	struct s_fill	*next;
	struct s_fill	*prev;
}					t_fill;

void				initialization(int *i, int *numb_of_blocks, int *buf);
short int			check_all(char *str);
int					check_bit(int num, short int pos);
void				set_bit(int *num, short int pos);
int					check_i(char *str, int i);
void				helper_fun1(int k, short int start, short int *j, int n);
void				helper_fun2(short int *i, short int *j, int *k, int *p);
void				hepler_fun3(int *n, short int *start, short int *j, int k);
t_fill				*fill(char *str);
short				g_old_border;
#	endif
