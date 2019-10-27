/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:08:40 by eleanna           #+#    #+#             */
/*   Updated: 2019/09/12 18:59:18 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int i;
	int i2;

	i = 0;
	i2 = 0;
	while (dest[i])
		i++;
	while (src[i2] && (size_t)i2 < n)
	{
		dest[i] = src[i2];
		i++;
		i2++;
	}
	dest[i] = 0;
	return (dest);
}
