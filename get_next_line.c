/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouzel <yabouzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:36:18 by yabouzel          #+#    #+#             */
/*   Updated: 2025/12/14 18:29:32 by yabouzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int check_nl(char *str)
{
    int j;

    j = 0;
    while(str[j])
    {
        if(str[j] == '\n')
            return(j);
        j++;
    }
    return(-1);
}

char	*str_join(char *result, char *buff, int indxnl)
{
	int		i;
	char	*ns;
	
	i = 0;
	if (result == NULL || buff == NULL)
		return (NULL);
	if (indxnl != -1)
		ns = malloc (ft_strlen(result) + indxnl + 2);	
	else if (indxnl == -1)
		ns = malloc (ft_strlen(result) + ft_strlen(buff) + 1);
	if (!ns)
		return (NULL);
    while (result[i] != '\0')
    {
		ns[i] = result[i];
        i++;
    }
    while (*buff != '\0')
	{
		ns[i++] = *buff;
        if (*(buff++) == '\n')
            break ;
	}
	ns[i] = '\0';
	return (free(result), ns);
}

char *result_combiner(char *result, char *buff, int indxnl, int signal)
{   
    if (signal == 0)
    {
        result = str_join(result, buff, indxnl);
        if (!result)
            return (NULL);
        if (indxnl != -1)
            ft_strcpy(buff, buff + indxnl + 1);
        return (result);
    }
    if (signal == 1)
    {
        if(indxnl != -1)
        {
            result = str_join(result, buff, indxnl);
            if(!result)
                return(NULL);
            ft_strcpy(buff, buff + indxnl + 1);
            return(result);
        }
        if(ft_strlen(result) == 0)
            return(free(result), NULL);
    }
    return(result);
}

char *readncheck(char *buff, int fd, char *result)
{
    int indxnl;
    int readed;
    
    if(ft_strlen(buff) > 0)
    {
        indxnl = check_nl(buff);
        result = result_combiner(result, buff, indxnl, 0);
        if(indxnl != -1)
            return(result);
    }
    readed = read(fd, buff, BUFFER_SIZE);
    buff[readed] = '\0';
    indxnl = check_nl(buff);
    while (indxnl == -1 && readed > 0)
    {
        result = str_join(result, buff, indxnl);
        if(!result)
            return(NULL);
        readed = read(fd, buff, BUFFER_SIZE);
        buff[readed] = '\0';
        indxnl = check_nl(buff);
    }
    result = result_combiner(result, buff, indxnl, 1);
    return(result);
}

char *get_next_line(int fd)
{
    static char *buff;
    char *result;
    
    if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)   
        return (NULL);
    result = ft_strdup("");
    if (!result)
        return (NULL);
    if (buff != NULL)
    {
        result = readncheck(buff, fd, result);
        if(!result)
            return(free(result), free(buff), NULL);
        return(result);
    }
    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return (free(result),NULL);
    result = readncheck(buff, fd, result);
    if(!result)
        return(free(result), free(buff), NULL);
    return(result);
}
