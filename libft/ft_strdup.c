/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:50:52 by eleanna           #+#    #+#             */
/*   Updated: 2019/09/29 21:28:38 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *strl)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(ft_strlen(strl) + 1);
	if (!str)
		return (NULL);
	while (strl[i])
	{
		str[i] = strl[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
