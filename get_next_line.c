#include "get_next_line.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	static int	last_location;
	static int	i;
	char		*line;
	
	line = NULL;
	if (buf[0] != 0 && next_line_check(buf, last_location + 1, i) != -1)
		line = make_line(line, buf, last_location + 1, BUFFER_SIZE);
	last_location = next_line_check(buf, last_location + 1, i);
	if (next_line_check(line, 0, i) != -1)
		return (line);
	i = read(fd, buf, BUFFER_SIZE);
	last_location = next_line_check(buf, 0, i);
	while (i == BUFFER_SIZE && last_location == -1)
	{
		line = make_line(line, buf, 0, BUFFER_SIZE);
		i = read(fd, buf, BUFFER_SIZE);
		last_location = next_line_check(buf, 0, i);
	}
	if (i >= 0)
		line = make_line(line, buf, 0, i);
	return (line);
}

int	main()
{
	int fd;
	char *text;

	fd = open("text", O_RDONLY);
	text = get_next_line(fd);
	while(text)
	{
		printf("%s", text);
		free(text);
		text = get_next_line(fd);
	}
	
	free(text);
}