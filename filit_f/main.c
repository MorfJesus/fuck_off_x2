/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 20:38:59 by eleanna           #+#    #+#             */
/*   Updated: 2019/11/16 23:36:09 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void	find_best_solution(int fd, t_fill *list, short border)
{
	short	arr[52];
	char	*buf;
	short	i;
	short	fl;

	fl = 0;
	fill_arr(fd, border, arr);
	i = 0;
	buf = 0;
	loop_fun(buf, fd, arr);
	i = 0;
	fill_list(list, arr);
	hard_draw(list, border, 1);
}

void	solver(t_fill *tmp, short *t, short border, int fd)
{
	t_p		index;
	short	t2[14];

	index.border = border;
	index.i = set_i(tmp, t);
	while (++index.i < border)
	{
		index.j = set_j(tmp, index.i);
		while (++index.j < border)
		{
			if (check_tet(tmp, t, index.j, index.i) &&
			!(index.i + tmp->height > border || index.j + tmp->width > border))
			{
				for_solver5(border, t, t2, tmp);
				for_solver2(index.i, index.j, tmp, t2);
				display_solver(tmp, border, fd, t);
				for_solver4(border, tmp, fd, t2);
			}
			else
				triple_solver(index, fd, tmp, t);
		}
	}
}

char	*read_file(char *argv)
{
	char	*str;
	char	*ptr;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	str = ft_strnew(1);
	while (get_next_line(fd, &ptr))
	{
		ptr = ft_strjoin(ptr, "\n");
		str = ft_strjoin(str, ptr);
	}
	close(fd);
	return (str);
}

int		main(int argc, char **argv)
{
	char		*str;
	int			fd2;
	short int	t[14];
	t_fill		*list;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [input_file]\n");
		return (0);
	}
	g_old_border = 15;
	str = read_file(argv[1]);
	if (str == NULL)
		return (0);
	if (!check_all(str))
	{
		ft_putstr("error\n");
		return (0);
	}
	list = fill(str);
	fd2 = open("creative_solution", O_WRONLY | O_CREAT | O_TRUNC,
	S_IRWXU | S_IRWXG | S_IRWXO);
	solver(list, t, 2, fd2);
	return (0);
}
