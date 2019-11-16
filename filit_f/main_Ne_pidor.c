/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_Ne_pidor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <eleanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 20:38:59 by eleanna           #+#    #+#             */
/*   Updated: 2019/11/16 22:23:51 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <unistd.h>
#include<fcntl.h>

void solver(t_fill *tmp, short *t, short border, int fd);

t_fill *get_first(t_fill *list)
{
	while (list)
	{
		if (list->prev)
			list = list->prev;
		else
			break;
	}
	return (list);
}

void draw_dick(t_fill *list, int border, char str[border][border], char c)
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

void draw_out(short border, short fd, char str[border][border])
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

void hard_draw(t_fill *list, short border, int fd)
{
	char str[border][border];
	short i;
	short j;
	char c;

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

void debug_b(int n, int border)
{
	while (border && n >> 1)
	{
    if (n & 1)
        printf("1");
    else
        printf("0");
    n >>= 1;
		border--;
	}
	printf("\n");
}

void debug(int n)
{
	int i;

	i = 0;
	while (n >> 1)
	{
		if (i % 4 == 0 && i != 0)
			printf("\n");
    if (n & 1)
        printf("1");
    else
        printf("0");
    n >>= 1;
		i++;
	}
	printf("\n");
}

void draw_in(t_fill *list, short int *t, short int x, short int y)
{
	short int i;
	short int j;

	j = -1;
	i = 0;
	while(i < 16)
	{
		if (i % 4 == 0)
			j++;
		if (check_bit(list->n, i))
			set_bit((int *)&(t[j + y]), i % 4 + x);
		i++;
	}
}

int check_tet(t_fill *list, short int *t, short int x, short int y)
{
	short int i;
	short int j;

	j = -1;
	i = 0;
	while(i < 16)
	{
		if (i % 4 == 0)
			j++;
		if (check_bit(list->n, i) && check_bit(t[j + y], i % 4 + x))
			return (0);
		i++;
	}
	return (1);
}

void drawer(short *t, int border)
{
	int i;

	i = 0;
	while(i < border)
	{
		debug_b(t[i], border);
		i++;
	}
}

void clear(t_fill *list, short int *t, short int x, short int y)
{
	short int i;
	short int j;

	j = -1;
	i = 0;
	while(i < 16)
	{
		if (i % 4 == 0)
			j++;
		if (check_bit(list->n, i))
			clear_bit((int *)&(t[j + y]), i % 4 + x);
		i++;
	}
}

short experiment(short border, short t[border],t_fill *list)
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
		if (list->j != -1 && list->i != -1 && i == list->i)
			j = list->j;
		else
			j = -1;
		while (++j < border)
		{
			if (!(i + list->height > border || j + list->width > border) && (check_tet(list, t2, j, i)))
				return (1);
		}
	}
	return (0);
}

short is_last(t_fill *tmp, short border, short t[border])
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

void skip_rest(int fd, char *buf)
{
	free(buf);
	while(get_next_line(fd, &buf) == 1 && buf[0] != 'A')
		free(buf);
}

void fill_arr(int fd, int border, short arr[52])
{
	int i;
	char *buf;

	i = 0;
	while(1)
	{
		get_next_line(fd, &buf);
		if (buf[1] == border + 'A')
		{
			free(buf);
			while(get_next_line(fd, &buf) == 1 && buf[0] != 'A')
			{
				arr[i] = ft_atoi(buf);
				i++;
				free(buf);
			}
			arr[i] = -1;
			break;
		}
		else
			skip_rest(fd, buf);
	}
}

void odd_j(int fd, short *i, short arr[52], char *buf)
{
	if (ft_atoi(buf) > arr[*i])
		skip_rest(fd, buf);
	else if (ft_atoi(buf) > arr[*i])
	{
		arr[*i] = ft_atoi(buf);
		free(buf);
		(*i)++;
		while(get_next_line(fd, &buf) == 1 && buf[0] != 'A')
		{
			arr[*i] = ft_atoi(buf);
			(*i)++;
			free(buf);
		}
		*i = 0;
	}
}

void even_i(int fd, short *i, short arr[52], char *buf)
{
	if (*i % 2 == 0 && ft_atoi(buf) > arr[*i])
	{
		free(buf);
		while(get_next_line(fd, &buf) == 1 && buf[0] != 'A')
			free(buf);
		*i = 0;
		return ;
	}
	if (*i % 2 == 0 && ft_atoi(buf) < arr[*i])
	{
		arr[*i] = ft_atoi(buf);
		free(buf);
		(*i)++;
		while(get_next_line(fd, &buf) == 1 && buf[0] != 'A')
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

void loop_fun(char *buf, int fd, short arr[52])
{
	short i;
	int fl;

	i = 0;
	fl = 0;
	while(get_next_line(fd, &buf) == 1)
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

void fill_list(t_fill *tmp, short arr[52])
{
	short i;

	i = 0;
	while(arr[i] != -1)
	{
		if (i % 2 == 0 && i != 0)
			tmp = tmp->next;
		if (!tmp)
			break;
		if (i % 2 == 0)
			tmp->i = arr[i];
		else
			tmp->j = arr[i];
		i++;
	}
}

void find_best_solution(int fd, t_fill *list, short border)
{
	short arr[52];
	char *buf;
	short i;
	short fl;

	fl = 0;
	fill_arr(fd, border, arr);
	i = 0;
	buf = 0;
	loop_fun(buf, fd, arr);
	i = 0;
	fill_list(list, arr);
	hard_draw(list, border, 2);
}

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
				break;
		}
		ft_putstr_fd("A\n", fd);
	}
	if (border > g_old_border && tmp->prev)
		solver(tmp->prev, t, tmp->prev->border, fd);
}

void for_solver1(int fd, short border, t_fill *tmp)
{
	close(fd);
	fd = open("creative_solution", O_RDONLY);
	find_best_solution(fd, get_first(tmp), border);
	exit(0);
}

void for_solver2(short i, short j, t_fill *tmp, short t2[14])
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
		return(j - 1);
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
	&& tmp->prev && index.border + 1 >= g_old_border && is_last(tmp, index.border, t))
		for_solver1(fd, index.border, tmp);
	if (index.i == index.border - 1 && index.j == index.border - 1
	&& index.border + 1 > g_old_border && tmp->prev)
		solver(tmp->prev, t, tmp->prev->border, fd);
}

void solver(t_fill *tmp, short *t, short border, int fd)
{
	t_p index;
	short t2[14];

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
  while(get_next_line(fd, &ptr))
  {
  	ptr = ft_strjoin(ptr ,"\n");
  	str = ft_strjoin(str ,ptr);
  }
	close(fd);
	return(str);
}

int		main(int argc, char **argv)
{
	char			*str;
	int				fd2;
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
