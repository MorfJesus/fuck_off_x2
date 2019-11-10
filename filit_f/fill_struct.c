/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:24:57 by eleanna           #+#    #+#             */
/*   Updated: 2019/11/10 19:10:23 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		check_i(char *str, int i)
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

void	fill_n(char *str, int *n)
{
	short int	i;
	short int	j;
	short int	start;
	int			k;
	int			p;

	i = 0;
	j = 0;
	p = 0;
	*n = 65536;
	k = 0;
	start = -1;
	while (i < 20)
	{
		if (i % 5 == 0)
		{
			if (p != 0)
				k++;
			if (k >= (start + 8) / 4)
			{
				if (!(check_bit(*n, start) && check_bit(*n, start + 1)
							&& !check_bit(*n, start + 4)))
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
			p = 1;
			if (start == -1)
				start = j + 4 * k;
			set_bit(n, j + 4 * k);
			j++;
		}
		i++;
	}
}

void	trash_fun(short int i, short int *width2, short int *height, char *str)
{
	short int j;
	short fl;

	j = 0;
	(*width2) = 0;
	fl = 0;
	while (j < 4)
		{
			if (str[i * 5 + j] == '#' && fl == 0)
				(*height)++;
			if ((str[i * 5 + j] == '.' && str[i * 5 + j + 1] == '#'
			&& str[(i + 1) * 5 + j] == '#') ||
			(str[i * 5 + j] == '#' && (fl = 1)))
				(*width2)++;
			j++;
		}
}

void	set_sizes(char *str, short int *width, short int *height)
{
	short int i;
//	short int j;
	short int width2;
//	short fl;

	i = 0;
//	j = 0;
	(*width) = 0;
	(*height) = 0;
	while (i < 4)
	{
		trash_fun(i, &width2, height, str);
		if (width2 > *width)
			*width = width2;
		i++;
	}
}

t_fill	*add_list(t_fill *list, char *str)
{
	t_fill *tmp;
	t_fill *new;

	if (!(new = (t_fill *)malloc(sizeof(t_fill))))
		return (NULL);
	fill_n(str, &(new->n));
	new->next = 0;
	new->i = -1;
	new->j = -1;
	new->border = 0;
	set_sizes(str, &(new->width), &(new->height));
	if (!list)
	{
		new->prev = 0;
		return (new);
	}
	else
	{
		tmp = list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	return (list);
}

t_fill	*fill(char *str)
{
	int		len;
	char	*str2;
	t_fill	*list;

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
