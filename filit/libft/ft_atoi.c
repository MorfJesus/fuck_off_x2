/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:29:34 by acarole           #+#    #+#             */
/*   Updated: 2019/09/18 15:13:12 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short int	ft_whitespace(char c)
{
	return (c == '\n' || c == '\t' || c == ' '
			|| c == '\v' || c == '\r' || c == '\f');
}

int			ft_atoi(const char *ptr)
{
	size_t	i;
	size_t	fl;
	size_t	count;

	i = 0;
	fl = 0;
	count = 0;
	while (ft_whitespace(ptr[i]))
		i++;
	if (ptr[i] == '-')
	{
		fl = 1;
		i++;
	}
	else if (ptr[i] == '+')
		i++;
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		count = count * 10 + ptr[i] - '0';
		i++;
	}
	if (fl)
		return ((-1) * count);
	else
		return (count);
}
