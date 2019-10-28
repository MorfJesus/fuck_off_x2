/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:53:58 by acarole           #+#    #+#             */
/*   Updated: 2019/09/21 13:55:37 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count_words(char const *s, char c)
{
	size_t world;
	size_t i;

	i = 0;
	world = 0;
	if (s[0] != c && s[0] != 0)
	{
		world++;
		i++;
	}
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i - 1] == c)
			world++;
		i++;
	}
	return (world);
}

static void		ft_start(char const *s, char c, size_t *j, size_t *length)
{
	while (s[*j] == c)
		(*j)++;
	(*length) = (*j);
	while (s[*length] && s[*length] != c)
		(*length)++;
}

static	int		ft_free(char **words, size_t *i)
{
	if (!words[*i])
	{
		while (*i)
		{
			free(words[*i]);
			(*i)--;
		}
		free(words);
		return (1);
	}
	else
		return (0);
}

static char		**split(char **words, const char *s, char c, size_t count_words)
{
	size_t j;
	size_t length;
	size_t i;

	j = 0;
	length = 0;
	i = 0;
	while (i < count_words)
	{
		ft_start(s, c, &j, &length);
		if (length == j)
			break ;
		words[i] = ft_strsub(s, j, length - j);
		if (ft_free(words, &i))
			return (NULL);
		j += length - j;
		i++;
	}
	words[i] = 0;
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**words;
	size_t	count_words;

	if (!s || !c)
		return (NULL);
	count_words = ft_count_words(s, c);
	words = (char **)malloc(sizeof(char *) * (count_words + 1));
	if (words == NULL)
		return (NULL);
	else
		return (split(words, s, c, count_words));
}
