#include <mlx.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "fdf.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

#define CYAN 65535
#define WHITE 0xFFFFFF
#define BLACK 0
#define NEON_PINK 16646554
#define PI 3.14
//COLORS ARE B G R A FOR WHATEVER FUCKING REASON

int		add_clr(int clr1, int clr2, double coef)
{
	if (coef > 1)
		coef = 1;
	return (((clr1>>16 & 0xFF) + (int)(((clr2>>16 & 0xFF) - (clr1>>16 & 0xFF)) * coef)) * 65536
	+ ((clr1>>8 & 0xFF) + (int)(((clr2>>8 & 0xFF) - (clr1>>8 & 0xFF)) * coef)) * 256
	+ ((clr1>>0 & 0xFF) + (int)(((clr2>>0 & 0xFF) - (clr1>>0 & 0xFF)) * coef)));
}

void	turn_iso(t_fdf *fdf)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while(i < (*fdf).height)
	{
		j = 0;
		while(j < (*fdf).width)
		{
			(*fdf).point[k].x = (j - i) * cos(0.523599) * (*fdf).zoom;
			(*fdf).point[k].y = (-(*fdf).p[i][j] * (*fdf).scale + (j + i) * sin(0.523599)) * (*fdf).zoom;

			(*fdf).point[k].x += (*fdf).shift_x;
			(*fdf).point[k].y -= (*fdf).shift_y;
			(*fdf).point[k].clr = add_clr(CYAN, NEON_PINK, (*fdf).p[i][j] / 9.0);
			k++;
			j++;
		}
		i++;
	}
}

void	ft_draw_line(t_p st_p, t_p en_p, t_win win, t_fdf fdf)
{
	double	tx;
	float		dx;
	float		dy;
	int			cl_dif;

	tx = 0.0;
	cl_dif = st_p.clr - en_p.clr;
	dx = en_p.x - st_p.x;
	dy = en_p.y - st_p.y;
	while (tx <= 1)
	{
		mlx_pixel_put(win.mlx_ptr, win.win_ptr, st_p.x + (dx * tx),
		st_p.y +(dy * tx), add_clr(st_p.clr, en_p.clr, tx));
		tx += 1.0 / sqrt((dx * dx) + (dy * dy));
	}
}

int get_height(char *file)
{
	int height;
	int fd;
	char *line;

	height = 0;
	fd = open(file, O_RDONLY);
	while(get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	return(height);
}

void free_double(char **str)
{
	int i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int get_width(char *file)
{
	int width;
	int fd;
	char *line;
	char **str;

	width = 0;
	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	str = ft_strsplit(line, ' ');
	while(str[width])
	{
		free(str[width]);
		width++;
	}
	free(str);
	free(line);
	return(width);
}

int deal_key(int key, t_fdf *fdf)
{
	int i = 0;
	int k = 0;
	int j = 0;

	void *img_ptr;
	int bpp;
	int size_line;
	int endian = 1;
	char *lft_menu;
	if (key == 53)
		exit(0);
	if (key == 24)
		(*fdf).zoom+=1;
	if (key == 27 && (*fdf).zoom > 0.1)
		(*fdf).zoom-=1;
	if (key == 78 && (*fdf).scale > 0)
		(*fdf).scale-=0.05;
	if (key == 69)
		(*fdf).scale+=0.05;
	if (key == 126)
		(*fdf).shift_y+=20;
	if (key == 125)
		(*fdf).shift_y-=20;
	if (key == 124)
		(*fdf).shift_x+=20;
	if (key == 123)
		(*fdf).shift_x-=20;
	if (key == 48)
		(*fdf).is_iso = !(*fdf).is_iso;
	if (key == 91)
		(*fdf).alpha-=5.0;
	if (key == 84)
		(*fdf).alpha+=5.0;
	if (key == 86)
		(*fdf).beta-=5.0;
	if (key == 88)
		(*fdf).beta+=5.0;
	mlx_clear_window((*fdf).win.mlx_ptr, (*fdf).win.win_ptr);
	img_ptr = mlx_new_image((*fdf).win.mlx_ptr, (*fdf).win.win_width / 3, (*fdf).win.win_height);
	lft_menu = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	i = 0;
	while (i < (*fdf).win.win_width * (*fdf).win.win_height * 4 / 3 - 3)
	{
		lft_menu[i] = (char)230;
		lft_menu[i+1] = (char)170;
		lft_menu[i+2] = (char)203;
		i+=4;
	}
	i = 0;
	while(i < (*fdf).height)
	{
		j = 0;
		while(j < (*fdf).width)
		{
			(*fdf).point[k].x_old = ((*fdf).point[k].j - (*fdf).width / 2) * (*fdf).zoom;
			(*fdf).point[k].y_old = ((*fdf).point[k].i - (*fdf).height / 2) * (*fdf).zoom;

			if ((*fdf).is_iso)
			{
				(*fdf).alpha = 90;
				(*fdf).beta = 0;
				(*fdf).point[k].x = ((*fdf).point[k].x_old - (*fdf).point[k].y_old) * cos(0.523599) + (*fdf).win.win_width * 6 / 8;
				(*fdf).point[k].y = (-(*fdf).p[i][j] * (*fdf).scale * (*fdf).zoom + ((*fdf).point[k].x_old + (*fdf).point[k].y_old) * sin(0.523599) + (*fdf).win.win_height / 3);
			}
			else
			{

				(*fdf).point[k].x = ((*fdf).point[k].x_old * cos((*fdf).beta * PI / 180.0) + (*fdf).point[k].y_old * cos((*fdf).alpha * PI / 180.0) * sin((*fdf).beta * PI / 180.0)
				+ ((*fdf).p[i][j] * sin((*fdf).beta * PI / 180.0) * sin((*fdf).alpha * PI / 180.0) * (*fdf).scale * (*fdf).zoom) + (*fdf).win.win_width * 5 / 8);
				(*fdf).point[k].y = ((*fdf).point[k].y_old * sin((*fdf).alpha * PI / 180.0) + (*fdf).win.win_height / 2 + ((*fdf).p[i][j] * sin(((*fdf).alpha - 90) * PI / 180.0) * (*fdf).scale * (*fdf).zoom));

				(*fdf).point[k].x_old = (*fdf).point[k].x;
				(*fdf).point[k].y_old = (*fdf).point[k].y;
			}
			(*fdf).point[k].x += (*fdf).shift_x;
			(*fdf).point[k].y -= (*fdf).shift_y;
			k++;
			j++;
		}
		i++;
	}
	k = 0;
	while(k < (*fdf).width * (*fdf).height - 1)
	{
		if ((k + 1) % ((*fdf).width) != 0)
			ft_draw_line((*fdf).point[k], (*fdf).point[k + 1], (*fdf).win, *fdf);
		if (k + (*fdf).width < (*fdf).width * (*fdf).height)
		 ft_draw_line((*fdf).point[k], (*fdf).point[k + (*fdf).width], (*fdf).win, *fdf);
		k++;
	}
	mlx_put_image_to_window((*fdf).win.mlx_ptr, (*fdf).win.win_ptr, img_ptr, 0, 0);
	return(0);
}

int main(int argc, char **argv)
{
	t_win	win;
	void *img_ptr;
	int bpp;
	int size_line;
	int endian = 1;
	char *img;

	t_fdf fdf;
	int i;
	int j;
	int k;
	int fd;
	char *line;
	int **p;
	t_p *point;
	char **str;

	int height;
	int width;

	i = 0;
	height = get_height(argv[1]);
	width = get_width(argv[1]);
	point = (t_p*)malloc(sizeof(t_p) * width * height);
	fd = open(argv[1], O_RDONLY);
	p = (int**)malloc(sizeof(int) * width * height);
	if (!p || !point)
		return(0);
	while(get_next_line(fd, &line))
	{
		j = 0;
		p[i] = (int*)malloc(sizeof(int) * width);
		str = ft_strsplit(line, ' ');
		while(str[j])
		{
			p[i][j] = ft_atoi(str[j]);
			free(str[j]);
			j++;
		}
		free(str);
		free(line);
		i++;
	}
	close(fd);
	win.win_width = 1920;
	win.win_height = 1200;
	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, win.win_width, win.win_height, "fdf");
	img_ptr = mlx_new_image(win.mlx_ptr, win.win_width / 3, win.win_height);
	img = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	i = 0;
	while (i < win.win_width * win.win_height * 4 / 3 - 3)
	{
		img[i] = (char)230;
		img[i+1] = (char)170;
		img[i+2] = (char)203;
		i+=4;
	}
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, img_ptr, 0, 0);
	fdf.win = win;
	fdf.point = point;
	fdf.width = width;
	fdf.height = height;
	printf(":( %d, %d\n", width, height);
	fdf.p = p;
	fdf.scale = 0.1;
	fdf.shift_x = 0;
	fdf.shift_y = 0;
	fdf.zoom = 25;
	fdf.alpha = 90;
	fdf.beta = 0;
	fdf.is_iso = 0;
	i = 0;
	k = 0;
	while(i < height)
	{
		j = 0;
		while(j < width)
		{
			fdf.point[k].j = j;
			fdf.point[k].i = i;
			fdf.point[k].x = fdf.point[k].j * fdf.zoom + fdf.win.win_width  * 5 / 8 - width / 2 * fdf.zoom;
			fdf.point[k].y = fdf.point[k].i * fdf.zoom + fdf.win.win_height / 2 - height / 2 * fdf.zoom;
			point[k].clr = add_clr(CYAN, NEON_PINK, p[i][j] / 10.0);
			k++;
			j++;
		}
		i++;
	}
	k = 0;
	while(k < width * height - 1)
	{
		if ((k + 1) % (width) != 0)
			ft_draw_line(point[k], point[k + 1], win, fdf);
		if (k + width < width * height)
		 ft_draw_line(point[k], point[k + width], win, fdf);
		k++;
	}
	mlx_hook(win.win_ptr, 2, 0, deal_key, &fdf);
	mlx_loop(win.mlx_ptr);
}
