#include <mlx.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "fdf.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

#define CYAN 65535
#define PURPLE 8224255
#define WHITE 0xFFFFFF
#define BLACK 0
#define NEON_PINK 16646554
#define RED 16711680
//COLORS ARE B G R A FOR WHATEVER FUCKING REASON

int		add_clr(int clr1, int clr2, double coef)
{
	if (coef > 1)
		coef = 1;
	return (((clr1>>16 & 0xFF) + (int)(((clr2>>16 & 0xFF) - (clr1>>16 & 0xFF)) * coef)) * 65536
	+ ((clr1>>8 & 0xFF) + (int)(((clr2>>8 & 0xFF) - (clr1>>8 & 0xFF)) * coef)) * 256
	+ ((clr1>>0 & 0xFF) + (int)(((clr2>>0 & 0xFF) - (clr1>>0 & 0xFF)) * coef)));
}

void	ft_draw_line(t_p st_p, t_p en_p, t_win win)
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
		mlx_pixel_put(win.mlx_ptr, win.win_ptr, st_p.x + 200 + (dx * tx), st_p.y + 200 + (dy * tx), add_clr(st_p.clr, en_p.clr, tx));//st_p.clr + ft_abs(cl_dif * tx));
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
	//close(fd);
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
	//close(fd);
	return(width);
}

int deal_key(int key, t_fdf *fdf)
{
	int i = 0;
	int k = 0;
	int j = 0;
	if (key == 53)
		exit(0);
	if (key == 24 && (*fdf).zoom < 3.8)
	{
		(*fdf).zoom+=0.1;
		(*fdf).scale += 0.3;
	}
	if (key == 27 && (*fdf).zoom > 0.1)
	{
		(*fdf).zoom-=0.1;
		(*fdf).scale-=0.3;
	}
	if (key == 78 && (*fdf).scale > 0.3)
		(*fdf).scale-=0.5;
	if (key == 69)
		(*fdf).scale+=0.5;
	if (key == 126)
		(*fdf).shift_y+=10;
	if (key == 125)
		(*fdf).shift_y-=10;
	if (key == 124)
		(*fdf).shift_x+=10;
	if (key == 123)
		(*fdf).shift_x-=10;
	while(i < (*fdf).height)
	{
		j = 0;
		while(j < (*fdf).width)
		{
			//printf("%d\t%d\n", p[i][j], k);
			(*fdf).point[k].y = -(((j * 20 * (*fdf).zoom + i * 20 * (*fdf).zoom) * sin(30)) + (*fdf).p[i][j] * (*fdf).scale) - (*fdf).shift_y;
			(*fdf).point[k].x = (j * 300 * (*fdf).zoom - i * 200 * (*fdf).zoom) * cos(30) + (*fdf).shift_x;
			(*fdf).point[k].clr = add_clr(CYAN, NEON_PINK, (*fdf).p[i][j] / 10.0);
			//printf("%d\n", point[k].clr);
			k++;
			j++;
		}
		i++;
	}
	k = 0;
	while(k < (*fdf).width * (*fdf).height - 1)
	{
		if ((k + 1) % ((*fdf).width) != 0)
			ft_draw_line((*fdf).point[k], (*fdf).point[k + 1], (*fdf).win);
		if (k + (*fdf).width < (*fdf).width * (*fdf).height)
		 ft_draw_line((*fdf).point[k], (*fdf).point[k + (*fdf).width], (*fdf).win);
		k++;
	}
	printf("%f\n", (*fdf).zoom);
	mlx_clear_window((*fdf).win.mlx_ptr, (*fdf).win.win_ptr);
	return(0);
}

int main(int argc, char **argv)
{
	t_win	win;
	// void *img_ptr;
	// int bpp;
	// int size_line;
	// int endian = 1;
	// char *img;

	t_fdf fdf;
	int i;
	int j;
	int k;
	int fd;
	char *line;
	int y;
	int x;
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
	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, 2000, 1600, "heh");
	// img_ptr = mlx_new_image(mlx_ptr, 800, 600);
	// img = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	// mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	i = 0;
	k = 0;
	while(i < height)
	{
		j = 0;
		while(j < width)
		{
			//printf("%d\t%d\n", p[i][j], k);
			point[k].y = -(((j * 10 * 2 + i * 10 * 2) * sin(30)) + p[i][j] * 3);
			point[k].x = (j * 150 * 2 - i * 100 * 2) * cos(30);
			point[k].clr = add_clr(CYAN, NEON_PINK, p[i][j] / 10.0);
			//printf("%d\n", point[k].clr);
			k++;
			j++;
		}
		i++;
	}
	k = 0;
	while(k < width * height - 1)
	{
		if ((k + 1) % (width) != 0)
			ft_draw_line(point[k], point[k + 1], win);
		if (k + width < width * height)
		 ft_draw_line(point[k], point[k + width], win);
		k++;
	}
	fdf.win = win;
	fdf.point = point;
	fdf.width = width;
	fdf.height = height;
	fdf.p = p;
	fdf.scale = 3;
	fdf.shift_x = 0;
	fdf.shift_y = 0;
	fdf.zoom = 1;
	mlx_key_hook(win.win_ptr, deal_key, &fdf);
	mlx_loop(win.mlx_ptr);
}
