/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouzel <yabouzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:11:34 by yabouzel          #+#    #+#             */
/*   Updated: 2025/11/29 18:10:45 by yabouzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int check_nl(char *str)
{
    int j;

    while(str[j])
    {
        if(str[j] == "\n")
            return(j);
        j++;
    }
    return(0);
}
char *get_next_line(int fd)
{
    static char *buff;
    char *result;
    int i;
    int indxnl;
    int readed;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    result = ft_strdup("");
    if (!buff)
    {
        buff = malloc(BUFFER_SIZE + 1);
        if(!buff)
            return(free(result),free(buff),NULL);
        readed = read(fd, buff, BUFFER_SIZE);
    }
    while(0 == (indxnl = check_nl(buff)))
    {
        if(readed < BUFFER_SIZE)
            return(NULL);
        result = ft_strjoin(result, buff);
        readed = read(fd, buff, BUFFER_SIZE);
    }
    return(result);
}
int main()
{
    int fd = open("yas.txt", O_RDONLY);
    char *str = get_next_line(fd);
    printf("%s\n", str);
    printf("%d", fd);
    close(fd);
}
