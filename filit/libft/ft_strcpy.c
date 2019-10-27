/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:45:24 by acarole           #+#    #+#             */
/*   Updated: 2019/09/18 15:21:02 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t i;
	size_t len;

	len = ft_strlen(src);
	i = 0;
	while (i <= len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
