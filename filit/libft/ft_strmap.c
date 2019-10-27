/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:49:50 by acarole           #+#    #+#             */
/*   Updated: 2019/09/18 15:27:30 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
