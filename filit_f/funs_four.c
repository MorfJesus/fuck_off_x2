/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funs_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 22:46:45 by acarole           #+#    #+#             */
/*   Updated: 2019/11/16 23:11:54 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	display_solver(t_fill *tmp, short border, int fd, short t[14])
{
	t_fill *list;

	list = get_first(tmp);
	if (!tmp->next && border <= g_old_border)
	{
		ft_putchar_fd('B', fd);
		ft_putchar_fd(border + 'A', fd);
		ft_putchar_fd('\n', fd);
		g_old_border = border;
		list = get_first(tmp);
		while (list)
		{
			ft_putnbr_fd(list->i, fd);
			ft_putchar_fd('\n', fd);
			ft_putnbr_fd(list->j, fd);
			ft_putchar_fd('\n', fd);
			if (list->next)
				list = list->next;
			else
				break ;
		}
		ft_putstr_fd("A\n", fd);
	}
	if (border > g_old_border && tmp->prev)
		solver(tmp->prev, t, tmp->prev->border, fd);
}

void	for_solver1(int fd, short border, t_fill *tmp)
{
	close(fd);
	fd = open("creative_solution", O_RDONLY);
	find_best_solution(fd, get_first(tmp), border);
	exit(0);
}

void	for_solver2(short i, short j, t_fill *tmp, short t2[14])
{
	tmp->i = i;
	tmp->j = j;
	draw_in(tmp, t2, j, i);
}

void	for_solver3(t_fill *tmp, short border, int fd, short t[14])
{
	tmp->i = -1;
	tmp->j = -1;
	solver(tmp, t, border + 1, fd);
}

void	for_solver4(short border, t_fill *tmp, int fd, short t2[14])
{
	if (border <= g_old_border && tmp->next)
	{
		tmp->next->i = -1;
		tmp->next->j = -1;
		solver(tmp->next, t2, tmp->border, fd);
	}
}
