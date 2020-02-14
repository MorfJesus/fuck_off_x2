/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:55:40 by eleanna           #+#    #+#             */
/*   Updated: 2019/09/12 20:06:43 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	const unsigned char		*srcc;
	unsigned char			*destc;

	srcc = src;
	destc = dest;
	if (!dest && !src)
		return (NULL);
	while (count > 0)
	{
		*destc = *srcc;
		srcc++;
		destc++;
		count--;
	}
	return (dest);
}
