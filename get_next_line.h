/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouzel <yabouzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:55:49 by yabouzel          #+#    #+#             */
/*   Updated: 2025/12/14 12:04:12 by yabouzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, char *src);
char    *get_next_line(int fd);

#endif