#include "get_next_line.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>



int main()
{
	int	fd;
	int i;
	fd = open("text", O_RDONLY);
	char line[] = "aaaaa";
	i = read(fd, line, 5);
	printf("%d %s", i, line);
	i = read(fd, line, 5);
	if (i < 5)
		printf("%d failed to read", i);
	printf("%s", line);
}