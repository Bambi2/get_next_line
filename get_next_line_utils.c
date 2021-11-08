#include "get_next_line.h"

int	next_line_check(char *buf, int start, int max)
{
	int	i;

	if (!buf)
		return (-1);
	i = start;
	while (i < max)
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char *ft_realloc(char *line, char *buf, int max)
{
	int		length;
	char	*new_line;
	int		j;
	int		z;

	length = 0;
	while(buf[length] != '\n' && length != max)
		length++;
	if (length != max)
		new_line = (char * ) malloc(length + ft_strlen(line) + 1);
	else
		new_line = (char * ) malloc(length + ft_strlen(line) + 2);
	j = 0;
	while (*line)
		new_line[j++] = *(line++);
	line -= j;
	z = 0;
	while(buf[j] != '\n' && z != max)
		new_line[j++] = buf[z++];
	if (z != max)
		new_line[j++] = '\n';
	new_line[j] = '\0';
	free(line);
	return (new_line);
}

int	ft_strlen(char *str)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

char	*make_line(char *user_line, char *buf, int start, int max)
{
	char	*line;
	int		j;
	int		length;

	if (user_line != NULL)
		return (ft_realloc(user_line, buf, max));
	length = 0;
	j = start;
	while(buf[j] != '\n' && j != max)
	{
		length++;
		j++;
	}
	if (j != max)
		line = (char *) malloc(length + 2);
	else
		line = (char *) malloc(length + 1);
	j = 0;
	while (buf[start] != '\n' && start != max)
		line[j++] = buf[start++];
	if (start != max)
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}