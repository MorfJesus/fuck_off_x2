/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:32:19 by acarole           #+#    #+#             */
/*   Updated: 2019/09/20 18:35:07 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*buf;

	if (del != NULL)
	{
		while (*alst != NULL)
		{
			buf = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = buf;
		}
		*alst = NULL;
	}
}
