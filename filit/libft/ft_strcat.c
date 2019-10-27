/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:43:05 by acarole           #+#    #+#             */
/*   Updated: 2019/09/14 23:05:07 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t i;
	size_t num;

	i = ft_strlen(dest);
	num = i;
	while (i < (num + ft_strlen(src)))
	{
		dest[i] = src[i - num];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
