#include "fillit.h"
#include <stdio.h>
#include<fcntl.h>

void debug_b(int n)
{
	while (n)
	{
    if (n & 1)
        printf("1");
    else
        printf("0");
    n >>= 1;
	}
	printf("\n");
}


int main(void)
{
	char *ptr;
	char *str;
	int fd;
	short int i;
	short n[14];
	t_fill *list;

	i = 0;
	while (i < 14)
	{
		n[i] = 16384;
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
	printf("\n");
    // printf("\n");
	while(i < 14)
	{
		debug_b(n[i]);
		i++;
	}
    return (0);
}
