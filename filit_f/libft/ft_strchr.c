/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:44:08 by acarole           #+#    #+#             */
/*   Updated: 2019/10/20 20:48:27 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	size_t	i;
	char	*str;
	size_t	count;

	count = ft_strlen(s);
	ch = (char)c;
	i = 0;
	str = (char*)s;
	while (i < (count + 1))
	{
		if (str[i] == ch)
			return (str + i);
		i++;
	}
	return (NULL);
}
