/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funs_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 22:53:42 by acarole           #+#    #+#             */
/*   Updated: 2019/11/16 23:14:05 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

short	set_i(t_fill *tmp, short *t)
{
	short i;

	if (tmp->i != -1 && tmp->j != -1)
		clear(tmp, t, tmp->j, tmp->i);
	if (tmp->i != -1)
		i = tmp->i;
	else
		i = 0;
	return (i - 1);
}

short	set_j(t_fill *tmp, short i)
{
	short j;

	if (tmp->j != -1 && tmp->i != -1 && i == tmp->i)
		j = tmp->j + 1;
	else
		j = 0;
	return (j - 1);
}

void	for_solver5(short border, short t[14], short t2[14], t_fill *tmp)
{
	ft_memmove(t2, t, 28);
	tmp->border = border;
}

void	triple_solver(t_p index, int fd, t_fill *tmp, short t[14])
{
	if (index.i == index.border - 1 && index.j == index.border - 1 &&
	index.border + 1 <= g_old_border)
		for_solver3(tmp, index.border, fd, t);
	if (index.i == index.border - 1 && index.j == index.border - 1
	&& tmp->prev && index.border + 1 >= g_old_border
	&& is_last(tmp, index.border, t))
		for_solver1(fd, index.border, tmp);
	if (index.i == index.border - 1 && index.j == index.border - 1
	&& index.border + 1 > g_old_border && tmp->prev)
		solver(tmp->prev, t, tmp->prev->border, fd);
}
