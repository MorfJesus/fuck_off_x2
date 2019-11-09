/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <eleanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 20:38:59 by eleanna           #+#    #+#             */
/*   Updated: 2019/11/10 00:13:28 by eleanna          ###   ########.fr       */
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

void find_best_solution(int fd)
{
	char *buf;
	char ptr[52];
	int i;
	int num;

	i = 0;
	num = 0;
	while(get_next_line(fd, &buf) && buf[0] != 'A')
	{
		ptr[i] = buf[0];
		i++;
	}
	//get_next_line(fd, buf);
	while (get_next_line(fd,&buf))
	{

	}
}

void solver(t_fill *tmp, short *t, short border, int fd)
{
	short i;
	short j;
	short t2[14];
	t_fill *list;

	if (tmp->i != -1 && tmp->j != -1)
	{
		clear(tmp, t, tmp->j, tmp->i);
		printf("AFTER CLEARING:\n");
		drawer(t, border);
		printf("OK\n\n");
	}
	printf("CHECKING: \n");
	debug(tmp->n);
	printf("WITH BORDER: %d\tAND I: %d\tJ: %d\tHEIGHT: %d\tWIDTH: %d\nAND MAP: \n\n", border, tmp->i, tmp->j, tmp->height, tmp->width);
	drawer(t, border);
	printf("\n");
	if (tmp->i != -1)
		i = tmp->i;
	else
		i = 0;
	while (i < border)
	{
		// j = tmp->j;
		if (tmp->j != -1 && tmp->i != -1 && i == tmp->i)
			j = tmp->j + 1;
		else
			j = 0;
		while (j < border)
		{
			printf("CHECKING AT: I: %d\tJ: %d\t....THE RESULT: CHECK_TET:%d\tHEIGHT/WIDTH: %d\n", i, j,
			check_tet(tmp, t, j, i), !(i + tmp->height > border || j + tmp->width > border));

			if (check_tet(tmp, t, j, i) && !(i + tmp->height > border || j + tmp->width > border))
			{
				ft_memmove(t2, t, 28);
				printf("%s\n", "PLACING:");
				debug(tmp->n);
				tmp->border = border;
				printf("I: %d\tJ: %d\tBorder: %d\tOLD: %d\n", i, j, tmp->border,
				old_border);
				tmp->i = i;
				tmp->j = j;
				draw_in(tmp, t2, j, i);
				drawer(t2, border);
				// if (border < old_border)
				// 	old_border = border;
				if (!tmp->next && border <= old_border)
				{
					old_border = border;
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
					ft_putchar_fd('\n', fd);
					//hard_draw(get_first(tmp), border, fd);
					printf("\n!!!NOTED!!!\n\n");
				}
				if (border > old_border && tmp->prev)
					solver(tmp->prev, t, tmp->prev->border, fd);
				if (border <= old_border && tmp->next)
				{
					tmp->next->i = -1;
					tmp->next->j = -1;
					solver(tmp->next, t2, tmp->border, fd);
				}
			}
			// if ((tmp->i + tmp->height >= border && list->j + tmp->width >= border))
			// 		{
			// 			return ;
			// 		}
			else
			{
				if (i == border - 1 && j == border - 1 && border + 1 <= old_border)
				{
					tmp->i = -1;
					tmp->j = -1;
					printf("YA SDELAL!!!1!\n");
					solver(tmp, t, border + 1, fd);
				}
				if (i == border - 1 && j == border - 1 && tmp->prev && border + 1 >= old_border && is_last(tmp, border, t))
				{
					printf("\n!!!EXITED PREMATURELY!!!\n\n");
					exit(0);
				}
				if (i == border - 1 && j == border - 1 && border + 1 > old_border && tmp->prev)
					solver(tmp->prev, t, tmp->prev->border, fd);
			}
			j++;
		}
		i++;
	}
	// if (tmp->next)
	// 	solver(tmp, t, border + 1);
	printf("\n_____EXITED THE FUNCTION_____\n\n");
}

int main(void)
{
	//static short old_border;
	char *ptr;
	char *str;
	int fd;
	int fd2;
	short int i;
	// short int j;
	short int border;
	short int t[14];
	t_fill *list;
	t_fill *tmp;
	// short int placed;

	i = 0;
	border = 2;
	old_border = 15;
	while (i < 14)
	{
		t[i] = 16384;
		i++;
	}
	i = 0;
  	 fd = open("example2", O_RDONLY);
  	// printf("%s",str);
  	 str = ft_strnew(1);
  	while(get_next_line(fd, &ptr))
  	{
  		ptr = ft_strjoin(ptr ,"\n");
  		str = ft_strjoin(str ,ptr);
  	}
  	// 	printf("%s",str);
  	 	// printf("\n");
    // if (!ft_check_square(str) && !connactions_count(str))
    //     printf("good");
    // else
    // {
    //    printf("shit");
    // }
	// printf("\n\n\n");
	list = fill(str);
	tmp = list;
	printf("%d\t%d\n", tmp->height, tmp->width);
	printf("\n");
    // printf("\n");
	// while (tmp)
	// {
	// 	placed = 0;
	// 	i = 0;
	// 	while (i < border)
	// 	{
	// 		j = 0;
	// 		while (j < border)
	// 		{
	// 			if (check_tet(tmp, t, j, i) && !(i + tmp->height > border || j + tmp->width > border))
	// 			{
	// 				printf("I: %d\tJ: %d\n", i, j);
	// 				tmp->i = j + i * border;
	// 				draw_in(tmp, t, j, i);
	// 				j = -1;
	// 				break;
	// 			}
	// 			j++;
	// 		}
	// 		if (j == -1)
	// 			break;
	// 		i++;
	// 	}
	// 	if (j != -1)
	// 		border++;
	// 	else
	// 		tmp = tmp->next;
	// }
	fd2 = open("creative_solution", O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU|S_IRWXG|S_IRWXO);
	solver(tmp, t, border, fd2);
	close(fd2);
	// tmp = list->next->next->next->next;
	// while (tmp)
	// {
	// 	debug_b(tmp->n, 16);
	// 	tmp = tmp->prev;
	// }
	i = 0;
	printf("\n\n___END___\n\n");
	while(i < border)
	{
		debug_b(t[i], border);
		i++;
	}
	printf("OK\n");
	//hard_draw(list, border, 1);
    return (0);
}
