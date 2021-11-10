#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE * (-1 + (BUFFER_SIZE >= 0) * 2) + 1];
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
