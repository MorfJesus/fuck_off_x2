/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:24:57 by eleanna           #+#    #+#             */
/*   Updated: 2019/10/28 21:18:01 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void set_bit(int *num, short int pos)
{
	*num |= (1 << (pos));
}

int check_bit(int num, short int pos)
{
	return (num & 1 << pos);
}

void debug(int n)
{
	int i;

	i = 0;
	while (n)
	{
		if (i == 4)
		{
			printf("\n");
			i = 0;
		}
    if (n & 1)
        printf("1");
    else
        printf("0");
    n >>= 1;
		i++;
	}
	printf("\n");
}

void debug_b(int n)
{
	while (n)
	{
    if (n & 1)
        printf("1");
    else
        printf("0");
    n >>= 1;
	}
	printf("\n");
}

int check_i(char *str, int i)
{
	if (str[i] == '.')
	{
		if (i >= 5 && str[i - 5] == '#')
				return (1);
		if (i + 5 < 19 && str[i + 5] == '#')
			return (1);
	}
	return (0);
}

int		fill_n(char *str)
{
	short int i;
	short int j;
	short int start;
	int n;

	i = 0;
	j = 0;
	n = 65536;
	start = -1;
	while (i < 20)
	{
		if (i % 5 == 0)
		{
			if (i > start + 9)
			{
				if (!(check_bit(n, start) && check_bit(n, start + 1) && !check_bit(n , start + 4)))
					j = 0;
				else
					j--;
			}
			else
				j = 0;
		}
		if (check_i(str, i))
			j++;
		if (str[i] == '#')
		{
			if (start == -1)
				start = i - i / 4;
			printf("start: %d\n", start);
			set_bit(&n, j + 4 * (i / 5));
			j++;
		}
		i++;
	}
	debug(n);
	return (n);
}

void set_sizes(char *str, short int *width, short int *height)
{
	short int i;
	short int j;
	short int width2;

	i = 0;
	j = 0;
	(*width) = 0;
	(*height) = 0;
	while (i < 4)
	{
		width2 = 0;
		j = 0;
		while (j < 4)
		{
			if (str[i * 5 + j] == '#' && width2 == 0)
				(*height)++;
			if (str[i * 5 + j] == '#')
				width2++;
			j++;
		}
		if (width2 > *width)
			*width = width2;
			i++;
	}
}

t_fill *add_list(t_fill *list, char *str)
{
	t_fill *tmp;
	t_fill *new;

	new = (t_fill *)malloc(sizeof(t_fill));
	new->n = fill_n(str);
	new->next = 0;
	set_sizes(str, &(new->width), &(new->height));
	printf("width: %d\theight: %d\n", new->width, new->height);
	if (!list)
		return(new);
	else
	{
		tmp = list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (list);
}

t_fill *fill(char *str)
{
	int len;
	char *str2;
	t_fill *list;

	list = 0;
	str2 = str;
	len = ft_strlen(str);
	while (str < str2 + len)
	{
		list = add_list(list, str);
		str = str + 21;
	}
	return (list);
}

//int main()
//{
//	char *str;
//	str = ft_strdup("##..\n.#..\n.#..\n....\n\n.#..\n###.\n....\n....\n");
//	fill(str);
//
//	//debug_b(17);
//	debug_b(check_bit(17, 0));
//}
