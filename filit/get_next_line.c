/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:10:46 by acarole           #+#    #+#             */
/*   Updated: 2019/10/20 20:42:37 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_lst	*ft_old_fd(t_lst *lst, const int fd, t_lst **list2)
{
	t_lst	*tmp;
	char	*ptr;

	tmp = lst;
	while (tmp)
	{
		if (tmp->fd == fd)
		{
			ptr = ft_strdup(tmp->str);
			free(tmp->str);
			tmp->str = ft_strjoin(ptr, (*list2)->str);
			free(ptr);
			free((*list2)->str);
			free(*list2);
			return (lst);
		}
		if (tmp->next)
			tmp = tmp->next;
		else
		{
			tmp->next = (*list2);
			return (lst);
		}
	}
	return (lst);
}

t_lst	*ft_createlst(t_lst *lst, const int fd, char *buf)
{
	t_lst	*list2;

	list2 = (t_lst *)malloc(sizeof(t_lst));
	list2->str = ft_strdup(buf);
	list2->fd = fd;
	list2->next = NULL;
	if (!lst)
		lst = list2;
	else
		lst = ft_old_fd(lst, fd, &list2);
	return (lst);
}

void	ft_dell(t_lst **list2, t_lst **list)
{
	t_lst	*list3;

	list3 = (*list);
	if ((*list2)->str[0] == 0)
	{
		if (list3 == *list2)
		{
			*list = (*list2)->next;
			free((*list2)->str);
			free(*list2);
			return ;
		}
		while (list3->next != (*list2))
			list3 = list3->next;
		list3->next = (*list2)->next;
		free((*list2)->str);
		free(*list2);
	}
}

int		ft_checks(t_lst **list2, char **line, int re, t_lst **list)
{
	int		i;
	char	*ptr;

	i = 0;
	if (re == 0 && !(*list2))
		return (0);
	while ((*list2)->str[i] != '\n' && (*list2)->str[i])
		i++;
	if (i == 0 && (*list2)->str[i] == 0)
		return (0);
	if (!(*line = ft_strsub((*list2)->str, 0, i)))
		return (-1);
	if (i > 0 && (*list2)->str[i] == 0)
	{
		ptr = ft_strdup("");
		free((*list2)->str);
	}
	else
	{
		ptr = ft_strdup(ft_strchr((*list2)->str, '\n') + 1);
		free((*list2)->str);
	}
	(*list2)->str = ptr;
	ft_dell(list2, list);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int				re;
	static	t_lst	*list;
	t_lst			*list2;
	char			buf[BUFF_SIZE + 1];

	re = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	list2 = list;
	while (list2 && list2->fd != fd)
		list2 = list2->next;
	if (!list2 || !(list2->fd == fd) || !(ft_strchr(list2->str, '\n')))
		while ((re = read(fd, buf, BUFF_SIZE)))
		{
			if (re == -1)
				return (-1);
			buf[re] = 0;
			list = ft_createlst(list, fd, buf);
			if (ft_strchr(buf, '\n'))
				break ;
		}
	list2 = list;
	while (list2 && list2->fd != fd)
		list2 = list2->next;
	return (ft_checks(&list2, line, re, &list));
}
