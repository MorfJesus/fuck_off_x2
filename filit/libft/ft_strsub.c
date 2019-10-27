/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:54:08 by acarole           #+#    #+#             */
/*   Updated: 2019/09/18 15:12:15 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!str || !s)
		return (NULL);
	i = start;
	while (len)
	{
		str[j++] = s[i++];
		len--;
	}
	str[j] = 0;
	return (str);
}
