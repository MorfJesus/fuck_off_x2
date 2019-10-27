/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:54:36 by eleanna           #+#    #+#             */
/*   Updated: 2019/09/17 16:55:20 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_arr(char ***words, int j)
{
	while (j >= 0)
	{
		free(*words[j]);
		j--;
	}
	free(*words);
	return (NULL);
}

static char	**split(char const *s, char c, char **words)
{
	int i;
	int j;
	int beg;
	int end;

	j = 0;
	beg = 0;
	end = ft_strlen(s);
	i = 0;
	while (i < (int)ft_strlen(s))
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			beg = i + 1;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
		{
			end = i + 1;
			words[j] = ft_strsub(s, beg, end - beg);
			if (words[j] == NULL)
				return (free_arr(&words, j - 1));
			j++;
		}
		i++;
	}
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	int		w_count;
	char	**words;

	i = 0;
	w_count = 0;
	if (!s || !c)
		return (NULL);
	while (i < ft_strlen(s))
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			w_count++;
		i++;
	}
	words = (char **)malloc(sizeof(char *) * (w_count + 1));
	if (!words)
		return (NULL);
	words[w_count] = 0;
	return (split(s, c, words));
}
