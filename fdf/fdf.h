#	ifndef FDF_H
#	define FDF_H
typedef struct	s_p
{
	int	x;
	int	y;
	int clr;
}		t_p;

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		zoom;
}		t_win;

typedef struct	s_fdf
{
	int shift_y;
	double zoom;
	int shift_x;
	t_win win;
	double scale;
	t_p *point;
	int width;
	int height;
	int **p;
}		t_fdf;
#	endif
