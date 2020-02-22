#	ifndef FDF_H
#	define FDF_H
typedef struct	s_p
{
	int	x;
	int	y;
	int z;
	int	i;
	int	j;
	int	x_old;
	int	y_old;
	int clr;
}		t_p;

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
	int		zoom;
}		t_win;

typedef struct	s_fdf
{
	int is_iso;
	double g;
	double beta;
	double alpha;
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
