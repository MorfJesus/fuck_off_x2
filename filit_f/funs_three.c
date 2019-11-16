/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funs_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 22:39:53 by acarole           #+#    #+#             */
/*   Updated: 2019/11/16 23:07:03 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_arr(int fd, int border, short arr[52])
{
	int		i;
	char	*buf;

	i = 0;
	while (1)
	{
		get_next_line(fd, &buf);
		if (buf[1] == border + 'A')
		{
			free(buf);
			while (get_next_line(fd, &buf) == 1 && buf[0] != 'A')
			{
				arr[i] = ft_atoi(buf);
				i++;
				free(buf);
			}
			arr[i] = -1;
			break ;
		}
		else
			skip_rest(fd, buf);
	}
}

void	odd_j(int fd, short *i, short arr[52], char *buf)
{
	if (ft_atoi(buf) > arr[*i])
		skip_rest(fd, buf);
	else if (ft_atoi(buf) > arr[*i])
	{
		arr[*i] = ft_atoi(buf);
		free(buf);
		(*i)++;
		while (get_next_line(fd, &buf) == 1 && buf[0] != 'A')
		{
			arr[*i] = ft_atoi(buf);
			(*i)++;
			free(buf);
		}
		*i = 0;
	}
}

void	even_i(int fd, short *i, short arr[52], char *buf)
{
	if (*i % 2 == 0 && ft_atoi(buf) > arr[*i])
	{
		free(buf);
		while (get_next_line(fd, &buf) == 1 && buf[0] != 'A')
			free(buf);
		*i = 0;
		return ;
	}
	if (*i % 2 == 0 && ft_atoi(buf) < arr[*i])
	{
		arr[*i] = ft_atoi(buf);
		free(buf);
		(*i)++;
		while (get_next_line(fd, &buf) == 1 && buf[0] != 'A')
		{
			arr[*i] = ft_atoi(buf);
			(*i)++;
			free(buf);
		}
		*i = 0;
		return ;
	}
	else
		(*i)++;
}

void	loop_fun(char *buf, int fd, short arr[52])
{
	short	i;
	int		fl;

	i = 0;
	fl = 0;
	while (get_next_line(fd, &buf) == 1)
	{
		if (buf[0] == 'A' || buf[0] == 'B')
		{
			i = 0;
			continue;
		}
		if (fl && i % 2 == 1)
			odd_j(fd, &i, arr, buf);
		if (fl)
			fl = 0;
		if (i % 2 == 0 && ft_atoi(buf) == arr[i])
		{
			free(buf);
			i++;
			fl = 1;
			continue;
		}
		even_i(fd, &i, arr, buf);
	}
}

void	fill_list(t_fill *tmp, short arr[52])
{
	short i;

	i = 0;
	while (arr[i] != -1)
	{
		if (i % 2 == 0 && i != 0)
			tmp = tmp->next;
		if (!tmp)
			break ;
		if (i % 2 == 0)
			tmp->i = arr[i];
		else
			tmp->j = arr[i];
		i++;
	}
}
