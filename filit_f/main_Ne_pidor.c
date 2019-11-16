/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_Ne_pidor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 20:38:59 by eleanna           #+#    #+#             */
/*   Updated: 2019/11/16 17:27:05 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <unistd.h>
#include<fcntl.h>

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
	i = 0;
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

short is_last(t_fill *tmp, short border, short t[border])
{
	t_fill *list;
	short i;
	short j;
	short t2[border];

	if (!tmp->prev)
		return (0);
	list = tmp;
	while (list)
	{
		if (list->prev)
			list = list->prev;
		else
			break;
	}
	while (list && list != tmp)
	{
		ft_memmove(t2, t, border * 2);
		i = 0;
		j = 0;
		clear(list, t2, list->j, list->i);
		if (list->i != -1)
			i = list->i;
		else
			i = 0;
		while (i < border)
		{
			if (list->j != -1 && list->i != -1 && i == list->i)
				j = list->j + 1;
			else
				j = 0;
			while (j < border)
			{
				if ((check_tet(list, t2, j, i) && !(i + list->height > border || j + list->width > border)))
					return (0);
				j++;
			}
			i++;
		}
		list = list->next;
	}
	return (1);
}

void find_best_solution(int fd, t_fill *list, short border)
{
	short arr[52];
	char *buf;
	short i;
	t_fill *tmp;
	short fl;

	i = 0;
	fl = 0;
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
		{
			free(buf);
			while(get_next_line(fd, &buf) == 1 && buf[0] != 'A')
				free(buf);
		}
	}
	i = 0;
	while(get_next_line(fd, &buf) == 1)
	{
		if (buf[0] == 'A' || buf[0] == 'B')
		{
			i = 0;
			continue;
		}
		if (fl && i % 2 == 1)
		{
			if (ft_atoi(buf) > arr[i])
			{
				free(buf);
				while(get_next_line(fd, &buf) == 1 && buf[0] != 'A')
					free(buf);
			}
			else if (ft_atoi(buf) > arr[i])
			{
				arr[i] = ft_atoi(buf);
				free(buf);
				i++;
				while(get_next_line(fd, &buf) == 1 && buf[0] != 'A')
				{
					arr[i] = ft_atoi(buf);
					i++;
					free(buf);
				}
				i = 0;
				continue;
			}
		}
		if (fl)
			fl = 0;
		if (i % 2 == 0 && ft_atoi(buf) == arr[i])
		{
			free(buf);
			i++;
			fl = 1;
			continue;
		}
		if (i % 2 == 0 && ft_atoi(buf) > arr[i])
		{
			free(buf);
			while(get_next_line(fd, &buf) == 1 && buf[0] != 'A')
				free(buf);
			i = 0;
			continue;
		}
		if (i % 2 == 0 && ft_atoi(buf) < arr[i])
		{
			arr[i] = ft_atoi(buf);
			free(buf);
			i++;
			while(get_next_line(fd, &buf) == 1 && buf[0] != 'A')
			{
				arr[i] = ft_atoi(buf);
				i++;
				free(buf);
			}
			i = 0;
			continue;
		}
		else
			i++;
	}
	i = 0;
	tmp = list;
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
	tmp = list;
	while (tmp)
		tmp = tmp->next;
	hard_draw(list, border, 2);
}

void	display_solver(t_fill *tmp, short border, int fd, t_fill **list)
{
	if (!tmp->next && border <= g_old_border)
	{
		ft_putchar_fd('B', fd);
		ft_putchar_fd(border + 'A', fd);
		ft_putchar_fd('\n', fd);
		g_old_border = border;
		(*list) = get_first(tmp);
		while (list)
		{
			ft_putnbr_fd((*list)->i, fd);
			ft_putchar_fd('\n', fd);
			ft_putnbr_fd((*list)->j, fd);
			ft_putchar_fd('\n', fd);
			if ((*list)->next)
				(*list) = (*list)->next;
			else
				break;
		}
		ft_putstr_fd("A\n", fd);
	}
}

void for_solver(int fd, short border, t_fill *tmp)
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



void solver(t_fill *tmp, short *t, short border, int fd)
{
	short i;
	short j;
	short t2[14];
	t_fill *list;

	if (tmp->i != -1 && tmp->j != -1)
		clear(tmp, t, tmp->j, tmp->i);
	if (tmp->i != -1)
		i = tmp->i;
	else
		i = 0;
	while (i < border)
	{
		if (tmp->j != -1 && tmp->i != -1 && i == tmp->i)
			j = tmp->j + 1;
		else
			j = 0;
		while (j < border)
		{
			if (check_tet(tmp, t, j, i) && !(i + tmp->height > border || j + tmp->width > border))
			{
				ft_memmove(t2, t, 28);
				tmp->border = border;
				for_solver2(i, j, tmp, t2);
				display_solver(tmp, border, fd, &list);
				if (border > g_old_border && tmp->prev)
					solver(tmp->prev, t, tmp->prev->border, fd);
				if (border <= g_old_border && tmp->next)
				{
					tmp->next->i = -1;
					tmp->next->j = -1;
					solver(tmp->next, t2, tmp->border, fd);
				}
			}
			else
			{
				if (i == border - 1 && j == border - 1 && border + 1 <= g_old_border)
				{
					tmp->i = -1;
					tmp->j = -1;
					solver(tmp, t, border + 1, fd);
				}
				if (i == border - 1 && j == border - 1 && tmp->prev && border + 1 >= g_old_border && is_last(tmp, border, t))
					for_solver(fd, border, tmp); 
				if (i == border - 1 && j == border - 1 && border + 1 > g_old_border && tmp->prev)
					solver(tmp->prev, t, tmp->prev->border, fd);
			}
			j++;
		}
		i++;
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
