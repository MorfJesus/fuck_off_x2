/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <eleanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:19:24 by eleanna           #+#    #+#             */
/*   Updated: 2019/10/28 20:50:48 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FILLIT_H
#	define FILLIT_H
#include "libft/libft.h"
#include <stdlib.h>

typedef struct		s_fill
{
	short int				height;
	short int				width;
	int							n;
	struct s_fill 	*next;
}					t_fill;

void	initialization(int *i, int *numb_of_blocks, int *buf);
int     ft_check_square(char *ptr);
int     top_botom(char *ptr, int i, int numb_of_blocks);
int     connactions_count(char *ptr);
t_fill 	*fill(char *str);
#endif
