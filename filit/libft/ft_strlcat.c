/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:08:40 by eleanna           #+#    #+#             */
/*   Updated: 2019/09/14 23:15:02 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_n_d(char **d, size_t *n)
{
	while ((*n) != 0 && (**d) != 0)
	{
		*n = (*n) - 1;
		*d = (*d) + 1;
	}
}

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		d_l;

	d = dest;
	s = src;
	set_n_d(&d, &n);
	d_l = d - dest;
	if (n == 0)
		return (d_l + ft_strlen(src));
	while (*s != 0)
	{
		if (n != 1)
		{
			*d = *s;
			d++;
			n--;
		}
		s++;
	}
	*d = 0;
	return (d_l + (s - src));
}
