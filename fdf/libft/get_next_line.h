/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <eleanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:07:41 by eleanna           #+#    #+#             */
/*   Updated: 2020/02/02 13:31:52 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H
#define BUFF_SIZE 50
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

typedef struct		s_gnl
{
	int				fd;
	struct s_gnl	*next;
	char			*s;
}					t_gnl;

int					get_next_line(const int fd, char **line);
#	endif
