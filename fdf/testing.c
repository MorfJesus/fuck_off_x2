#include <math.h>
#include <mlx.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "fdf.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

int		add_clr(int clr1, int clr2, double coef)
{
	if (coef > 1)
		coef = 1;
	return (((clr1>>16 & 0xFF) + (int)(((clr2>>16 & 0xFF) - (clr1>>16 & 0xFF)) * coef)) * 65536
				+ ((clr1>>8 & 0xFF) + (int)(((clr2>>8 & 0xFF) - (clr1>>8 & 0xFF)) * coef)) * 256
				+ ((clr1>>0 & 0xFF) + (int)(((clr2>>0 & 0xFF) - (clr1>>0 & 0xFF)) * coef)));
}

int main(int argc, char **argv)
{
	int og;
	int r, g, b;
	int new;
	int og2;
	double td;

	// og = 65535;
	// og2 = 8224255;
	// r = og>>16 & 0xFF;
	// g = og>>8 & 0xFF;
	// b = og>>0 & 0xFF;
	//
	// printf("color 1: %d\n", og);
	// printf("red: %d\n", r);
	// printf("green: %d\n", g);
	// printf("blue: %d\n\n", b);
	//
	// r = og2>>16 & 0xFF;
	// g = og2>>8 & 0xFF;
	// b = og2>>0 & 0xFF;
	// printf("color 2: %d\n", og2);
	// printf("red: %d\n", r);
	// printf("green: %d\n", g);
	// printf("blue: %d\n\n", b);
	//
	// new = ((og>>16 & 0xFF) + (og2>>16 & 0xFF) - (og>>16 & 0xFF)) * 65536
	// + (og>>8 & 0xFF + ((og2>>8 & 0xFF) - (og>>8 & 0xFF))) * 256
	// + (og>>0 & 0xFF + ((og2>>0 & 0xFF) - (og>>0 & 0xFF)));
	// //new = r * 65536 + g * 256 + b;
	// r = new>>16 & 0xFF;
	// g = new>>8 & 0xFF;
	// b = new>>0 & 0xFF;
	// printf("red: %d\n", r);
	// printf("green: %d\n", g);
	// printf("blue: %d\n", b);
	// td = 0;
	// og = 65535;
	// while (td < 1.0)
	// {
	// 	printf("%f\n", td);
	// 	og = add_clr(65535, 8224255, td);
	// 	r = og>>16 & 0xFF;
	// 	g = og>>8 & 0xFF;
	// 	b = og>>0 & 0xFF;
	// //	printf("color: %d\n", og);
	// //	printf("red: %d\n", r);
	// 	printf("green: %d\n", g);
	// //	printf("blue: %d\n\n", b);
	// 	td +=0.1;
	// }
	// printf("%d\t%d\t%d\n", 65535>>8 & 0xFF, 8224255>>8 & 0xFF, (int)(((8224255>>8 & 0xFF) - (65535>>8 & 0xFF)) * 0.2));
	//((clr1>>8 & 0xFF) + floor(((clr2>>8 & 0xFF) - (clr1>>8 & 0xFF)) * coef))

	int fd;
	char *line;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n",line);
}
