/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:19:11 by eleanna           #+#    #+#             */
/*   Updated: 2019/09/12 20:17:08 by eleanna          ###   ########.fr       */
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
