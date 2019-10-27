/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:24:09 by acarole           #+#    #+#             */
/*   Updated: 2019/09/21 13:57:16 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_last(t_list *begin_list)
{
	t_list *list;

	list = begin_list;
	if (!list)
		return (0);
	while (list->next)
		list = list->next;
	return (list);
}
