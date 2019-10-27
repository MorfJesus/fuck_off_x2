/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:47:47 by eleanna           #+#    #+#             */
/*   Updated: 2019/09/17 17:02:44 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

static void	check_beg(char *str, size_t *beg)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(str) - 1)
	{
		if (!ft_isspace(str[0]))
			break ;
		if (ft_isspace(str[i]) && !ft_isspace(str[i + 1]))
		{
			*beg = i + 1;
			break ;
		}
		i++;
	}
}

static void	check_end(char *s, size_t *end)
{
	size_t i;

	i = ft_strlen(s) - 1;
	while (i > 0)
	{
		if (!ft_isspace(s[ft_strlen(s) - 1]))
			return ;
		if (ft_isspace(s[i]) && !ft_isspace(s[i - 1]))
		{
			*end = i;
			return ;
		}
		i--;
	}
	*end = 0;
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	beg;
	size_t	end;

	beg = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	str[ft_strlen(s)] = 0;
	str = ft_strcpy(str, s);
	end = ft_strlen(str);
	check_beg(str, &beg);
	check_end(str, &end);
	str = ft_strsub(str, beg, end - beg);
	return (str);
}
