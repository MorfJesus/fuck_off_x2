/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:28:36 by eleanna           #+#    #+#             */
/*   Updated: 2019/09/17 17:03:17 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *targ, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (targ[0] == 0)
		return ((char *)src);
	while (src[i] && i + ft_strlen(targ) - 1 < n)
	{
		while (src[i] == targ[j] && src[i] && targ[j])
		{
			i++;
			j++;
		}
		if (j == ft_strlen(targ))
			return ((char *)src + i - j);
		i = i - j;
		j = 0;
		i++;
	}
	return (NULL);
}
