#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

# define BUFFER_SIZE 5

char	*get_next_line(int fd);

int	next_line_check(const char *line);
char *ft_realloc(char *line, char *buf, int max);
int	ft_strlen(const char *str);
char	*make_line(const char *buf, int *i);
char	*ft_strjoin(char const *s1, char const *s2);
int	fd_read(int	fd, char *buf, int *i);

struct	s_file {
	int		fd;
	int		i;
	char	buf[BUFFER_SIZE];
} typedef t_file;

#endif