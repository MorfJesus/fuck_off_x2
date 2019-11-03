/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <eleanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 20:38:59 by eleanna           #+#    #+#             */
/*   Updated: 2019/11/03 21:44:11 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <unistd.h>
#include<fcntl.h>

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

void solver(t_fill *tmp, short *t, short border)
{
	short i;
	short j;
	short t2[14];
	int fd;
	t_fill *list;

	if (tmp->i != -1 && tmp->j != -1)
	{
		clear(tmp, t, tmp->j, tmp->i);
		printf("AFTER CLEARING:\n");
		drawer(t, border);
		printf("OK\n");
	}
	if (tmp->i != -1)
		i = tmp->i;
	else
		i = 0;
	while (i < border)
	{
		// j = tmp->j;
		if (tmp->j != -1 && tmp->i != -1)
			j = tmp->j + 1;
		else
			j = 0;
		while (j < border)
		{
			if (check_tet(tmp, t, j, i) && !(i + tmp->height > border || j + tmp->width > border))
			{
				ft_memmove(t2, t, 28);
				printf("%s\n", "PLACING:");
				debug(tmp->n);
				tmp->border = border;
				printf("I: %d\tJ: %d\tBorder: %d\tOLD: %d\nWidth: %d\tHeight: %d\n", i, j, tmp->border,
				old_border, tmp->width, tmp->height);
				tmp->i = i;
				tmp->j = j;
				draw_in(tmp, t2, j, i);
				drawer(t2, border);
				if (!tmp->next && border < old_border)
				{
					old_border = border;
					list = tmp;
					fd = open("creative_solution", O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU|S_IRWXG|S_IRWXO);
					while (list)
					{
						ft_putnbr_fd(list->i, fd);
						ft_putchar_fd('\n', fd);
						ft_putnbr_fd(list->j, fd);
						ft_putchar_fd('\n', fd);
						if (list->prev)
							list = list->prev;
						else
							break;
					}
					hard_draw(list, border, fd);
					close(fd);
				}
				if (border >= old_border && tmp->prev)
					solver(tmp->prev, t, tmp->prev->border);
				if (border < old_border && tmp->next)
					solver(tmp->next, t2, tmp->border);
			}
			else if (i == border - 1 && j == border - 1 && border + 1 < old_border)
				solver(tmp, t, border + 1);
			else if (border + 1 >= old_border)
				solver(tmp->prev, t, tmp->prev->border);
			j++;
		}
		i++;
	}
}

int main(void)
{
	//static short old_border;
	char *ptr;
	char *str;
	int fd;
	short int i;
	short int j;
	short int border;
	short int t[14];
	t_fill *list;
	t_fill *tmp;
	short int placed;

	i = 0;
	border = 2;
	old_border = 15;
	while (i < 14)
	{
		t[i] = 16384;
		i++;
	}
	i = 0;
  	 fd = open("example", O_RDONLY);
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
	solver(tmp, t, border);
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
