/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:10:40 by eleanna           #+#    #+#             */
/*   Updated: 2019/09/18 17:13:09 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lst_size(t_list *list)
{
	size_t	i;
	t_list	*lst;

	i = 0;
	lst = list;
	if (lst)
	{
		i = 1;
		while (lst->next)
		{
			lst = lst->next;
			i++;
		}
	}
	return (i);
}
