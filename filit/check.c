/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:49:22 by acarole           #+#    #+#             */
/*   Updated: 2019/10/27 22:05:59 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_square(char *ptr)
{
	int i;
	int j;
	int numb_of_blocks;

	i = 0;
	numb_of_blocks = 0;
	j = 0;
	while (ptr[i] && numb_of_blocks < 26)
	{
		j = 0;
		while (ptr[i] && ptr[i] != '\n')
		{
			j++;
			i++;
		}
		if (j != 4)
			return (1);
		i++;
		if ((i - numb_of_blocks) % 20 == 0)
		{
			numb_of_blocks++;
			i++;
		}
	}
	if ((i - numb_of_blocks) % 20 || (j % 4) || (numb_of_blocks > 26) || (ptr[0] == 0)
			|| (i != 0 && ptr[i] == '\0' && ptr[i - 1] == '\n'))
		return (1);
	return (0);
}

int		top_botom(char *ptr, int i, int numb_of_blocks)
{
	int count_connection;

	count_connection = 0;
	if ((i < (15 + 21 * numb_of_blocks)) && ptr[i] == '#')
		if (ptr[i + 5] == '#')
			count_connection++;
	if ((i < (18 + 21 * numb_of_blocks)) && ptr[i] == '#')
		if (ptr[i + 1] == '#')
			count_connection++;
	if ((i > (4 + 21 * numb_of_blocks)) && ptr[i] == '#')
		if (ptr[i - 5] == '#')
			count_connection++;
	if ((i > (21 * numb_of_blocks)) && ptr[i] == '#')
		if (ptr[i - 1] == '#')
			count_connection++;
	return (count_connection);
}

int		connactions_count(char *ptr)
{
	int count_connection;
	int i;
	int count_gratings;
	int numb_of_blocks;

	i = 0;
	count_connection = 0;
	count_gratings = 0;
	numb_of_blocks = 0;
	while (ptr[i])
	{
		if (!(ptr[i] == '\n' || ptr[i] == '#' || ptr[i] == '.'))
			return (1);
		if (ptr[i] == '#')
			count_gratings++;
		count_connection += top_botom(ptr, i, numb_of_blocks);
		i++;
		if ((i - numb_of_blocks) % 20 == 0)
		{
			numb_of_blocks++;
			if (count_gratings != 4 || count_connection < 6)
				return (1);
			count_gratings = 0;
			count_connection = 0;
			i++;
		}
	}
	return (0);
}