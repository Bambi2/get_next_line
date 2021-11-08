#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

# define BUFFER_SIZE 12

char	*get_next_line(int fd);

int	next_line_check(char *buf, int last_location, int max);
char *ft_realloc(char *line, char *buf, int max);
int	ft_strlen(char *str);
char	*make_line(char *user_line, char *buf, int start, int max);
char	*ft_strjoin(char const *s1, char const *s2);

#endif