/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_too.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:17:36 by acarole           #+#    #+#             */
/*   Updated: 2019/11/10 20:24:09 by acarole          ###   ########.fr       */
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

void	helper_fun1(int k, short int start, short int *j, int n)
{
	if (k >= (start + 8) / 4)
	{
		if (!(check_bit(n, start) && check_bit(n, start + 1)
					&& !check_bit(n, start + 4)))
			(*j) = 0;
		else
			(*j)--;
	}
	else
		(*j) = 0;
}

void	helper_fun2(short int *i, short int *j, int *k, int *p)
{
	*i = -1;
	*j = 0;
	*p = 0;
	*k = 0;
}

void	hepler_fun3(int *n, short int *start, short int *j, int k)
{
	if ((*start) == -1)
		(*start) = (*j) + 4 * k;
	set_bit(n, (*j) + 4 * k);
	(*j)++;
}
