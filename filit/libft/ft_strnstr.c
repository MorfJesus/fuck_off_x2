/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:52:42 by acarole           #+#    #+#             */
/*   Updated: 2019/09/18 15:17:30 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	size_t	len_needle;

	len_needle = ft_strlen(needle);
	str = (char*)haystack;
	if (!(*needle))
		return (str);
	if (len_needle != ft_strlen(haystack))
		while (*str && ((int)(len - len_needle) >= 0))
		{
			if (!ft_memcmp(str, needle, len_needle))
				return (str);
			len--;
			str++;
		}
	else if (len >= len_needle)
	{
		if (!ft_memcmp(str, needle, len_needle))
			return (str);
	}
	return (NULL);
}
