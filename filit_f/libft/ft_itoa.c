/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:32:46 by acarole           #+#    #+#             */
/*   Updated: 2019/09/21 13:35:01 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_check(int *num, int n, char **ptr)
{
	if (*num < 0)
		*ptr[0] = '-';
	if (!n)
		**ptr = '0';
}

static size_t	ft_iteration(int num, int count)
{
	while (num)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char	*ptr;
	size_t	count;
	int		num;

	num = n;
	count = 0;
	count = ft_iteration(num, count);
	num = n;
	if (num <= 0)
		count++;
	ptr = (char *)malloc(sizeof(*ptr) * (count + 1));
	if (ptr)
	{
		ft_bzero(ptr, count + 1);
		ft_check(&num, n, &ptr);
		while (n)
		{
			ptr[count - 1] = (ft_abs(n % 10) + '0');
			count--;
			n /= 10;
		}
		return (ptr);
	}
	return (NULL);
}
