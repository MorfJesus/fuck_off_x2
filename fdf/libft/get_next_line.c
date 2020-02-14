/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <eleanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:34:45 by eleanna           #+#    #+#             */
/*   Updated: 2019/10/27 17:41:22 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl		*gnl_add(t_gnl **gnl, const int fd, char *str, t_gnl **fd_gnl)
{
	t_gnl	*new;
	t_gnl	*tmp;

	if (!(new = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	if (!(new->s = ft_strdup(str)))
		return (NULL);
	new->next = NULL;
	if (!*(gnl))
		*gnl = new;
	else
	{
		tmp = *gnl;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	*fd_gnl = new;
	return (*gnl);
}

t_gnl		*set_fd(t_gnl *gnl, const int fd)
{
	while (gnl)
	{
		if (gnl->fd == fd)
			return (gnl);
		gnl = gnl->next;
	}
	return (NULL);
}

void		free_link(t_gnl **gnl, int fd, t_gnl **fd_gnl)
{
	t_gnl	*tmp;
	t_gnl	*prev;

	prev = NULL;
	tmp = *gnl;
	while (tmp)
	{
		if (tmp->fd == fd)
		{
			if (prev)
				prev->next = tmp->next;
			else
				*gnl = tmp->next;
			free((*fd_gnl)->s);
			free(*fd_gnl);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

char		*gnl_to_str(char *str, t_gnl **gnl, const int fd, t_gnl **fd_gnl)
{
	char	*new;

	str = ft_strsub((*fd_gnl)->s, 0,
			ft_strchr((*fd_gnl)->s, '\n') - (*fd_gnl)->s);
	if (!str)
		return (NULL);
	new = ft_strdup(ft_strchr((*fd_gnl)->s, '\n') + 1);
	if (!new)
		return (NULL);
	free((*fd_gnl)->s);
	(*fd_gnl)->s = new;
	if (!((*fd_gnl)->s)[0])
		free_link(gnl, fd, fd_gnl);
	return (str);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl;
	t_gnl			*fd_gnl;
	char			buf[BUFF_SIZE + 1];
	int				re;

	re = 0;
	if (!(fd_gnl = set_fd(gnl, fd)) || !ft_strchr(fd_gnl->s, '\n'))
		while ((re = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[re] = 0;
			if (!fd_gnl)
				gnl_add(&gnl, fd, buf, &fd_gnl);
			else
				fd_gnl->s = ft_strjoin(fd_gnl->s, buf);
			if (ft_strchr(buf, '\n'))
				break ;
		}
	if (re == 0 && !fd_gnl)
		return (0);
	if (re == 0 && !ft_strchr(fd_gnl->s, '\n'))
		fd_gnl->s = ft_strjoin(fd_gnl->s, "\n");
	if (re == -1 || !(*line = gnl_to_str(*line, &gnl, fd, &fd_gnl)))
		return (-1);
	return (1);
}
