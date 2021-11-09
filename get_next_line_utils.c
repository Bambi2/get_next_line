#include "get_next_line.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (result);
}