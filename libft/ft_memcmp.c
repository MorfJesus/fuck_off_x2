/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:34:25 by eleanna           #+#    #+#             */
/*   Updated: 2019/09/12 21:10:45 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		if ((unsigned char)((char *)ptr1)[i] !=
				(unsigned char)((char *)ptr2)[i])
			return ((unsigned char)((char *)ptr1)[i] -
					((unsigned char)((char *)ptr2)[i]));
			i++;
	}
	return (0);
}
