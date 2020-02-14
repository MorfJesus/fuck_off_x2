/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:57:15 by eleanna           #+#    #+#             */
/*   Updated: 2019/09/15 18:38:05 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int n)
{
	int positive;

	positive = 1;
	if (n < 0)
		positive = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n / 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(ft_abs(n) % 10 + '0');
	}
	else
	{
		if (!positive)
			ft_putchar('-');
		ft_putchar(ft_abs(n) + '0');
	}
}
