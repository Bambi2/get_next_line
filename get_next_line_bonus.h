#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);

int		next_line_check(const char *line);
int		ft_strlen(const char *str);
char	*make_line(const char *buf, int *i);
char	*ft_strjoin(char *s1, char *s2);
int		fd_read(int	fd, char *buf, int *i);

typedef struct s_file {
	int		i;
	char	buf[BUFFER_SIZE * (-1 + (BUFFER_SIZE >= 0) * 2) + 1];
}	t_file;

#endif