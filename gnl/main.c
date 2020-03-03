#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//#include "get_next_line_utils.c"

int get_next_line(int fd, char **line);

int main ()
{
	int fd;
	int ret;
	char *line;
	char *buf;
	
//	line = (char *)malloc(BUFFER_SIZE + 1);
	fd = open("arquivo.txt", O_RDONLY);
	ret = read(fd, buf, 1000);
	printf("%d\n", ret);
	get_next_line(fd, &line);
	printf("%d\n", ret);
	get_next_line(fd, &line);
	printf("%d\n", ret);
	get_next_line(fd, &line);
	printf("%d\n", ret);

	printf("%d\n", fd);
	printf("%s\n", line);
	
	return (0);
}
