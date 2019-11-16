/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:19:24 by eleanna           #+#    #+#             */
/*   Updated: 2019/11/16 23:18:19 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FILLIT_H
#	define FILLIT_H
#include "libft/libft.h"
#include <stdlib.h>

typedef struct		s_fill
{
	short int		height;
	short int		width;
	short int		i;
	short int		j;
	short int		border;
	int				n;
	struct s_fill	*next;
	struct s_fill	*prev;
}					t_fill;

typedef struct		s_p
{
	short			i;
	short			j;
	short			border;
}					t_p;

void				fill_arr(int fd, int border, short arr[52]);
void				odd_j(int fd, short *i, short arr[52], char *buf);
void				even_i(int fd, short *i, short arr[52], char *buf);
void				loop_fun(char *buf, int fd, short arr[52]);
void				fill_list(t_fill *tmp, short arr[52]);
void				find_best_solution(int fd, t_fill *list, short border);
void				solver(t_fill *tmp, short *t, short border, int fd);
void				initialization(int *i, int *numb_of_blocks, int *buf);
short int			check_all(char *str);
int					check_bit(int num, short int pos);
void				set_bit(int *num, short int pos);
int					check_i(char *str, int i);
void				helper_fun1(int k, short int start, short int *j, int n);
void				helper_fun2(short int *i, short int *j, int *k, int *p);
void				hepler_fun3(int *n, short int *start, short int *j, int k);
t_fill				*fill(char *str);
t_fill				*get_first(t_fill *list);
void				draw_dick(t_fill *list, int b, char str[b][b], char c);
void				draw_out(short border, short fd, char str[border][border]);
void				hard_draw(t_fill *list, short border, int fd);
void				draw_in(t_fill *list, short *t, short x, short y);
int					check_tet(t_fill *list, short *t, short x, short y);
void				clear(t_fill *list, short int *t, short int x, short int y);
short				experiment(short border, short t[border], t_fill *list);
short				is_last(t_fill *tmp, short border, short t[border]);
void				skip_rest(int fd, char *buf);
void				display_solver(t_fill *tmp, short b, int fd, short t[14]);
void				for_solver1(int fd, short border, t_fill *tmp);
void				for_solver2(short i, short j, t_fill *tmp, short t2[14]);
void				for_solver3(t_fill *tmp, short border, int fd, short t[14]);
void				for_solver4(short b, t_fill *tmp, int fd, short t2[14]);
short				set_i(t_fill *tmp, short *t);
short				set_j(t_fill *tmp, short i);
void				for_solver5(short b, short t[14], short t2[14], t_fill *tm);
void				triple_solver(t_p index, int fd, t_fill *tmp, short t[14]);

short				g_old_border;
#	endif
