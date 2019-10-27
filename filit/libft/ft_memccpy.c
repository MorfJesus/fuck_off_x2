/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:54:10 by acarole           #+#    #+#             */
/*   Updated: 2019/09/14 21:54:13 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t count)
{
	const unsigned char		*srcc;
	unsigned char			*destc;
	size_t					i;

	srcc = (unsigned char *)src;
	destc = (unsigned char *)dest;
	i = 0;
	while (i < count)
	{
		*destc = *srcc;
		if (*srcc == (unsigned char)c)
			return (dest + i + 1);
		srcc++;
		destc++;
		i++;
	}
	return (NULL);
}
