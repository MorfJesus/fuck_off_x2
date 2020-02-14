/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:36:53 by eleanna           #+#    #+#             */
/*   Updated: 2019/09/18 17:35:59 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_at(t_list *lst, size_t nbr)
{
	t_list			*elem;
	size_t			i;

	i = 1;
	elem = lst;
	while (i <= nbr)
	{
		if (elem->next == 0 && i != nbr)
		{
			elem = 0;
			return (elem);
		}
		elem = elem->next;
		i++;
	}
	return (elem);
}
