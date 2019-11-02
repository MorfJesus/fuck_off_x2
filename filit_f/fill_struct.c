/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <eleanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:24:57 by eleanna           #+#    #+#             */
/*   Updated: 2019/11/02 20:40:37 by eleanna          ###   ########.fr       */
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

int		fill_n(char *str)
{
	short int	i;
	short int	j;
	short int	start;
	int			n;
	int			k;
	int			p;

	i = 0;
	j = 0;
	p = 0;
	n = 65536;
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
				if (!(check_bit(n, start) && check_bit(n, start + 1)
							&& !check_bit(n, start + 4)))
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
			set_bit(&n, j + 4 * k);
			j++;
		}
		i++;
	}
	return (n);
}

void	set_sizes(char *str, short int *width, short int *height)
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

t_fill	*add_list(t_fill *list, char *str)
{
	t_fill *tmp;
	t_fill *new;

	if (!(new = (t_fill *)malloc(sizeof(t_fill))))
		return(NULL);
	new->n = fill_n(str);
	new->next = 0;
	new->i = 0;
	set_sizes(str, &(new->width), &(new->height));
	if (!list)
		return (new);
	else
	{
		tmp = list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
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
