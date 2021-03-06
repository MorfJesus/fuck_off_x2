/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:53:39 by eleanna           #+#    #+#             */
/*   Updated: 2019/09/18 18:32:11 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
