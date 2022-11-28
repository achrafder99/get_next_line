#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <time.h>

int main(){
	clock_t t;
    t = clock();
	
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	int fd4;
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	fd4 = open("test4.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("%s",line);
		free(line);
		line = get_next_line(fd2);
		printf("%s",line);
		free(line);
		line = get_next_line(fd3);
		printf("%s\n",line);
		free(line);
		line = get_next_line(fd4);
		printf("%s\n",line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf("took %f seconds to execute \n", time_taken);
	return (0);
}