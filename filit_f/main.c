#include "check.c"
#include <stdio.h>
#include<fcntl.h>
#include "get_next_line.h"

int main(void)
{
  //char ptr[1000] = "....\n##..\n.#..\n.#..\n\n....\n##..\n.#..\n.#..\n\n....\n##..\n.#..\n.#..\n\n....\n##..\n.#..\n.#..\n\n....\n##..\n.#..\n.#..\n\n....\n##..\n.#..\n.#..\n\n";
 	char *ptr;
  char *str;
  int fd;
  	 fd = open("example", O_RDONLY);
  	// printf("%s",str);
  	 str = ft_strnew(1);
  	while(get_next_line(fd, &ptr))
  	{
  		ptr = ft_strjoin(ptr ,"\n");
  		str = ft_strjoin(str ,ptr);
  	}
  		printf("%s",str);
  		printf("\n");
    if (!ft_check_square(str) && !connactions_count(str))
        printf("good");
    else
    {
       printf("shit");
    }
    printf("\n");
    return (0);
}