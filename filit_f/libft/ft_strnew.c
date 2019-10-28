/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:52:05 by acarole           #+#    #+#             */
/*   Updated: 2019/10/14 18:49:51 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (size + 1 < size)
		return (NULL);
	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (str)
	{
		while (i <= size)
		{
			str[i] = 0;
			i++;
		}
	}
	return (str);
}
