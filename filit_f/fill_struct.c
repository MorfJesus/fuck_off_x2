/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:24:57 by eleanna           #+#    #+#             */
/*   Updated: 2019/11/10 20:32:57 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	fill_n(char *str, int *n)
{
	short int	i;
	short int	j;
	short int	start;
	int			k;
	int			p;

	helper_fun2(&i, &j, &k, &p);
	start = -1;
	*n = 65536;
	while (i++ < 20)
	{
		if (i % 5 == 0)
		{
			if (p != 0)
				k++;
			helper_fun1(k, start, &j, *n);
		}
		if (check_i(str, i))
			j++;
		if (str[i] == '#')
		{
			p = 1;
			hepler_fun3(n, &start, &j, k);
		}
	}
}

void	trash_fun(short int i, short int *width2, short int *height, char *str)
{
	short int	j;
	short		fl;

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
	short int width2;

	i = 0;
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
