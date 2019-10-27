/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:52:55 by acarole           #+#    #+#             */
/*   Updated: 2019/09/18 15:32:21 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	ch;
	size_t	len_s;

	ch = (char)c;
	str = (char*)s;
	len_s = ft_strlen(s) + 1;
	while (len_s--)
		if (str[len_s] == ch)
			return (str + len_s);
	return (NULL);
}
