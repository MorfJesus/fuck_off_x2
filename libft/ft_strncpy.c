/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:01:13 by eleanna           #+#    #+#             */
/*   Updated: 2019/09/14 17:19:56 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < (size_t)ft_strlen(src) && i < n)
	{
		dest[i] = (unsigned char)src[i];
		i++;
	}
	if (i < n)
	{
		while (i < n)
		{
			dest[i] = 0;
			i++;
		}
	}
	return (dest);
}
