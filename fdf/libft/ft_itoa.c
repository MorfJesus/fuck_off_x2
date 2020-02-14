/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:33:55 by eleanna           #+#    #+#             */
/*   Updated: 2019/09/15 18:37:30 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count(int n)
{
	int i;
	int pos;

	i = 0;
	pos = 1;
	if (n == 0)
		return (1);
	if (n < 0)
		pos = 0;
	while (n)
	{
		n = ft_abs(n / 10);
		i++;
	}
	if (pos)
		return (i);
	else
		return (i + 1);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		pos;

	pos = 1;
	str = (char *)malloc(count(n) + 1);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		pos = 0;
	str[count(n)] = 0;
	i = count(n) - 1;
	while (n)
	{
		str[i] = ft_abs(n % 10) + '0';
		i--;
		n = n / 10;
	}
	if (!pos)
		str[0] = '-';
	return (str);
}
