/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funs_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 22:28:28 by acarole           #+#    #+#             */
/*   Updated: 2019/11/16 23:10:52 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fill	*get_first(t_fill *list)
{
	while (list)
	{
		if (list->prev)
			list = list->prev;
		else
			break ;
	}
	return (list);
}

void	draw_dick(t_fill *list, int border, char str[border][border], char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 16)
	{
		if (i % 4 == 0 && i != 0)
			j++;
		if (check_bit(list->n, i))
			str[j + list->i][i % 4 + list->j] = c;
		i++;
	}
}

void	draw_out(short border, short fd, char str[border][border])
{
	short i;
	short j;

	i = 0;
	j = 0;
	while (i < border)
	{
		j = 0;
		while (j < border)
		{
			ft_putchar_fd(str[i][j], fd);
			j++;
		}
		ft_putchar_fd('\n', fd);
		i++;
	}
}

void	hard_draw(t_fill *list, short border, int fd)
{
	char	str[border][border];
	short	i;
	short	j;
	char	c;

	i = 0;
	c = 'A';
	while (i < border)
	{
		j = 0;
		while (j < border)
		{
			str[i][j] = '.';
			j++;
		}
		i++;
	}
	while (list)
	{
		draw_dick(list, border, str, c);
		c++;
		list = list->next;
	}
	draw_out(border, fd, str);
}

void	draw_in(t_fill *list, short int *t, short int x, short int y)
{
	short int i;
	short int j;

	j = -1;
	i = 0;
	while (i < 16)
	{
		if (i % 4 == 0)
			j++;
		if (check_bit(list->n, i))
			set_bit((int *)&(t[j + y]), i % 4 + x);
		i++;
	}
}
