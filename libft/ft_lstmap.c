/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 23:29:47 by eleanna           #+#    #+#             */
/*   Updated: 2019/09/17 17:43:34 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;

	if (lst)
	{
		list = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		if (!lst)
			return (NULL);
		list->next = ft_lstmap(lst->next, f);
		return (list);
	}
	return (NULL);
}
