/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouzel <yabouzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:50:49 by yabouzel          #+#    #+#             */
/*   Updated: 2025/12/23 05:24:13 by yabouzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H


#include <stddef.h>
#include <stdlib.h>

char    *ft_strdup(const char *s);
size_t  ft_strlen(const char *str);
char    *ft_strcpy(char *dest, char *src);
void    free_helper(char *str);
int check_nl(char *str);
char    *get_next_line(int fd);

#endif