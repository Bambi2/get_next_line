#include "get_next_line.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	static int		i;
	char			*line;
	char			*temp_line;

	if (buf[i] == '\0')
		if (!fd_read(fd, buf, &i))
			return (NULL);
	line = make_line(buf, &i);
	if (!line)
		return (NULL);
	while (!next_line_check(line))
	{
		if (!fd_read(fd, buf, &i))
			return (line);
		temp_line = make_line(buf, &i);
		if (!temp_line)
		{
			free(line);
			return (NULL);
		}
		line = ft_strjoin(line, temp_line);
	}
	return (line);
}

int	main()
{
	int fd;
	char *text;

	// fd = open("text", O_RDONLY);
	fd = 0;
	text = get_next_line(fd);
	while(text)
	{
		printf("%s", text);
		free(text);
		text = get_next_line(fd);
	}
	
	free(text);
}