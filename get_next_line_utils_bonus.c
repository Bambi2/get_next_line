#include "get_next_line_bonus.h"

int	next_line_check(const char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s1[i])
		result[j++] = s1[i++];
	i = 0;
	while (s2[i])
		result[j++] = s2[i++];
	result[j] = '\0';
	free(s1);
	free(s2);
	return (result);
}

char	*make_line(const char *buf, int *i)
{
	char	*line;
	int		size;

	size = 0;
	while (buf[*i + size] != '\0' && buf[*i + size] != '\n')
		size++;
	if (buf[*i + size] == '\n')
		size++;
	line = (char *) malloc(size + 1);
	if (!line)
		return (NULL);
	size = 0;
	while (buf[*i] != '\0' && buf[*i] != '\n')
	{
		line[size++] = buf[*i];
		(*i)++;
	}
	if (buf[*i] == '\n')
	{
		line[size++] = '\n';
		(*i)++;
	}
	line[size] = '\0';
	return (line);
}

int	fd_read(int	fd, char *buf, int *i)
{
	int	size;

	size = read(fd, buf, BUFFER_SIZE);
	if (size <= 0)
		return (0);
	buf[size] = '\0';
	*i = 0;
	return (size);
}
