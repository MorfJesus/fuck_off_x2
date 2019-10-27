/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <eleanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:19:24 by eleanna           #+#    #+#             */
/*   Updated: 2019/10/27 21:10:09 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FILLIT_H
#	define FILLIT_H

typedef struct		s_fill
{
	short int				height;
	short int				width;
	int							n;
	struct s_fill 	*next;
}									t_fill;

#endif
