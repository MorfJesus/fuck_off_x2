/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funs_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 22:35:39 by acarole           #+#    #+#             */
/*   Updated: 2019/11/16 23:09:47 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_tet(t_fill *list, short int *t, short int x, short int y)
{
	short int i;
	short int j;

	j = -1;
	i = 0;
	while (i < 16)
	{
		if (i % 4 == 0)
			j++;
		if (check_bit(list->n, i) && check_bit(t[j + y], i % 4 + x))
			return (0);
		i++;
	}
	return (1);
}

void	clear(t_fill *list, short int *t, short int x, short int y)
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
			clear_bit((int *)&(t[j + y]), i % 4 + x);
		i++;
	}
}

short	experiment(short border, short t[border], t_fill *list)
{
	short t2[border];
	short i;
	short j;

	ft_memmove(t2, t, border * 2);
	i = -1;
	j = -1;
	clear(list, t2, list->j, list->i);
	if (list->i != -1)
		i = list->i - 1;
	else
		i = -1;
	while (++i < border)
	{
		j = set_j(list, i);
		while (++j < border)
		{
			if (!(i + list->height > border || j + list->width > border)
			&& (check_tet(list, t2, j, i)))
				return (1);
		}
	}
	return (0);
}

short	is_last(t_fill *tmp, short border, short t[border])
{
	t_fill *list;

	list = get_first(tmp);
	while (list && list != tmp)
	{
		if (experiment(border, t, list))
			return (0);
		list = list->next;
	}
	return (1);
}

void	skip_rest(int fd, char *buf)
{
	free(buf);
	while (get_next_line(fd, &buf) == 1 && buf[0] != 'A')
		free(buf);
}
