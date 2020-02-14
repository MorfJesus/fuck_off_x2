/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:31:35 by eleanna           #+#    #+#             */
/*   Updated: 2019/09/14 16:32:31 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				result;

	i = 0;
	result = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i] && s1[i] && s2[i])
		{
			i++;
		}
		else
		{
			result = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (result);
		}
	}
	return (result);
}
