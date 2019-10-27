/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <eleanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:24:57 by eleanna           #+#    #+#             */
/*   Updated: 2019/10/27 22:14:06 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void set_bit(int *num, short int pos)
{
	*num |= (1 << (pos));
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

int		fill_n(char *str)
{
	short int i;
	int n;

	i = 0;
	n = 65536;
	while (i < 20)
	{
		if (str[i] == '#')
			set_bit(&n, i - ((i + 1) / 5));
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

int main()
{
	char *str;
	str = ft_strdup("...#\n...#\n...#\n...#\n\n....\n....\n....\n####\n\n.###\n...#\n....\n....\n\n....\n..##\n.##.\n....");
	fill(str);
}
