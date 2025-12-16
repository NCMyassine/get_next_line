#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, char *src);
char    *get_next_line(int fd);

#endif