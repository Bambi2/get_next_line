#include "get_next_line.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

// char	*get_next_line(int fd)
// {
// 	static char	buf[BUFFER_SIZE];
// 	static int	last_location;
// 	static int	i;
// 	char		*line;
// 	if (buf[BUFFER_SIZE - 1] == '\n')
// 		i = read(fd, buf, BUFFER_SIZE);
// 	last_location = next_line_check(buf, 0, i);
// 	while (i == BUFFER_SIZE && last_location == -1)
// 	{
// 		line = make_line(line, buf, 0, BUFFER_SIZE);
// 		i = read(fd, buf, BUFFER_SIZE);
// 		last_location = next_line_check(buf, 0, i);
// 	}
// 	if (i > 0)
// 		line = make_line(line, buf, 0, i);
// 	return (line);
// }

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	static int	i;
	int			size;
	char		*line;
	char		*temp_line;

	if (buf[i] == '\0')
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size <= 0)
			return (NULL);
		buf[size] = '\0';
		i = 0;
	}
	size = 0;
	while (buf[i + size] != '\0' && buf[i + size] != '\n')
		size++;
	i += size;
	line = (char *) malloc(size + 1);
	if (!line)
		return (NULL);
	size = 0;
	while (buf[i + size] != '\0' && buf[i + size] != '\n')
	{
		line[size] = buf[i + size];
		size++;
	}
	line[size] = '\0';
	while (line[size] != '\n' && size != 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size <= 0)
			return (line);
		buf[size] = '\0';
		i = 0;
		size = 0;
		while (buf[i + size] != '\0' && buf[i + size] != '\n')
			size++;
		i += size;
		temp_line = (char *) malloc(size + 1);
		if (!temp_line)
			return (NULL);
		line = ft_strjoin(line, temp_line);
		size = 0;
		while (buf[i + size] != '\0' && buf[i + size] != '\n')
		{
			line[size] = buf[i + size];
			size++;
		}
	}
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