/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 23:12:03 by acarole           #+#    #+#             */
/*   Updated: 2019/09/21 14:08:27 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;

	if (lst && f)
	{
		newlist = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (newlist)
		{
			newlist->next = ft_lstmap(lst->next, f);
			return (newlist);
		}
	}
	return (NULL);
}
