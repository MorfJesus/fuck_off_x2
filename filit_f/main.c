#include "fillit.h"
#include <stdio.h>
#include<fcntl.h>

void draw_dick(t_fill *list, char *str, int border, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 16)
	{
		if (i % 4 == 0 && i != 0)
			j++;
		if (check_bit(list->n, i))
			str[i % 4 + list->i + j * border] = c;
		i++;
	}
}

void hard_draw(t_fill *list, short border)
{
	char str[border * border]; 
	int i;
	char c;
	int len;

	i = 0;
	c = 'A';
	len = border * border;
	while (i < len)
	{
		str[i] = '.';
		i++;
	}
	while (list)
	{
		draw_dick(list, str, border, c);
		c++;
		list = list->next;
	}
	i = 0;
	while (i < len)
	{
		if (i % border == 0 && i != 0)
			ft_putchar('\n');
		ft_putchar(str[i]);
		i++;
	}
}

void debug_b(int n, int border)
{
	while (border && n >> 1)
	{
    if (n & 1)
        printf("1");
    else
        printf("0");
    n >>= 1;
		border--;
	}
	printf("\n");
}

void draw_in(t_fill *list, short int *t, short int x, short int y)
{
	short int i;
	short int j;

	j = -1;
	i = 0;
	while(i < 16)
	{
		if (i % 4 == 0)
			j++;
		if (check_bit(list->n, i))
			set_bit((int *)&(t[j + y]), i % 4 + x);
		i++;
	}
}

int check_tet(t_fill *list, short int *t, short int x, short int y)
{
	short int i;
	short int j;

	j = -1;
	i = 0;
	while(i < 16)
	{
		if (i % 4 == 0)
			j++;
		if (check_bit(list->n, i) && check_bit(t[j + y], i % 4 + x))
			return (0);
		i++;
	}
	return (1);
}

int main(void)
{
	char *ptr;
	char *str;
	int fd;
	short int i;
	short int j;
	short int border;
	short int t[14];
	t_fill *list;
	t_fill *tmp;
	short int placed;

	i = 0;
	border = 7;
	while (i < 14)
	{
		t[i] = 16384;
		i++;
	}
	i = 0;
  	 fd = open("example", O_RDONLY);
  	// printf("%s",str);
  	 str = ft_strnew(1);
  	while(get_next_line(fd, &ptr))
  	{
  		ptr = ft_strjoin(ptr ,"\n");
  		str = ft_strjoin(str ,ptr);
  	}
  	// 	printf("%s",str);
  	 	// printf("\n");
    // if (!ft_check_square(str) && !connactions_count(str))
    //     printf("good");
    // else
    // {
    //    printf("shit");
    // }
	// printf("\n\n\n");
	list = fill(str);
	tmp = list;
	printf("%d\t%d\n", tmp->height, tmp->width);
	printf("\n");
    // printf("\n");
	while (tmp)
	{
		placed = 0;
		i = 0;
		while (i < border)
		{
			j = 0;
			while (j < border)
			{
				if (check_tet(tmp, t, j, i) && !(i + tmp->height > border || j + tmp->width > border))
				{
					printf("I: %d\tJ: %d\n", i, j);
					tmp->i = j + i * border;
					draw_in(tmp, t, j, i);
					j = -1;
					break;
				}
				j++;
			}
			if (j == -1)
				break;
			i++;
		}
		if (j != -1)
			border++;
		else
			tmp = tmp->next;
	}
	i = 0;
	while(i < border)
	{
		debug_b(t[i], border);
		i++;
	}
	hard_draw(list, border);
    return (0);
}
