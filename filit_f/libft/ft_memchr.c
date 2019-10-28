/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:33:25 by acarole           #+#    #+#             */
/*   Updated: 2019/09/18 15:55:21 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	numb;
	size_t			i;

	i = 0;
	src = (unsigned char *)s;
	numb = (unsigned char)c;
	if (!n)
		return (NULL);
	while (i < n)
	{
		if (numb == src[i])
			return ((void *)(src + i));
		i++;
	}
	return (NULL);
}
