/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <eleanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:37:26 by eleanna           #+#    #+#             */
/*   Updated: 2019/10/12 16:46:10 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(len + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		str[i] = s1[i];
		i++;
	}
	str = ft_strcat(str, s2);
	free((void*)s1);
	return (str);
}
