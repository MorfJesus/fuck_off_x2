/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:53:29 by acarole           #+#    #+#             */
/*   Updated: 2019/09/18 15:32:47 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*str;
	size_t	len;

	len = ft_strlen(needle);
	str = (char*)haystack;
	if (!*needle)
		return (str);
	while (*str)
	{
		if (!ft_memcmp(str, needle, len))
			return (str);
		str++;
	}
	return (NULL);
}
