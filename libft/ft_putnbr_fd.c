/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:19:53 by eleanna           #+#    #+#             */
/*   Updated: 2019/09/15 18:38:34 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	int positive;

	positive = 1;
	if (n < 0)
		positive = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n / 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(ft_abs(n) % 10 + '0', fd);
	}
	else
	{
		if (!positive)
			ft_putchar_fd('-', fd);
		ft_putchar_fd(ft_abs(n) + '0', fd);
	}
}
