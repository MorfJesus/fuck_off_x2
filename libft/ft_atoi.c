/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:41:28 by eleanna           #+#    #+#             */
/*   Updated: 2019/09/14 16:59:21 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\r' || c == '\t' ||
			c == '\n' || c == '\v' || c == '\f')
		return (1);
	else
		return (0);
}

int					ft_atoi(const char *str)
{
	int i;
	int positive;
	int res;

	i = 0;
	positive = 1;
	res = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		positive = 0;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (positive)
		return (res);
	else
		return (-res);
}
