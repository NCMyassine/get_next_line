/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouzel <yabouzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:50:39 by yabouzel          #+#    #+#             */
/*   Updated: 2025/12/24 22:48:20 by yabouzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*str_join(char *result, char *buff, int indxnl)
{
	int		i;
	char	*ns;

	i = 0;
	if (result == NULL || buff == NULL)
		return (NULL);
	if (indxnl != -1)
		ns = malloc (ft_strlen(result) + indxnl + 2);
	else
		ns = malloc (ft_strlen(result) + ft_strlen(buff) + 1);
	if (!ns)
		return (free(result), NULL);
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

char	*readncheck(char *buff, int fd, char *result)
{
	int	readed;
	int	indxnl;

	readed = 1;
	indxnl = -1;
	while (indxnl == -1 && readed > 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed < 0)
			return (free(result), NULL);
		buff[readed] = '\0';
		indxnl = check_nl(buff);
		result = str_join(result, buff, indxnl);
		if (!result)
			return (NULL);
	}
	if (indxnl != -1)
		ft_strcpy(buff, buff + indxnl + 1);
	else if (readed == 0 && ft_strlen(result) == 0)
		return (free(result), NULL);
	return (result);
}

char	*result_combiner(char *result, char *buff, int fd)
{
	int	indxnl;

	indxnl = check_nl(buff);
	if (indxnl == -1)
	{
		result = str_join(result, buff, indxnl);
		if (!result)
			return (NULL);
		result = readncheck(buff, fd, result);
		if (!result)
			return (NULL);
	}
	else
	{
		result = str_join(result, buff, indxnl);
		if (!result)
			return (NULL);
		ft_strcpy(buff, buff + indxnl + 1);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buff[1024];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (free_helper(&buff[fd]), NULL);
	result = ft_strdup("");
	if (!result)
		return (free_helper(&buff[fd]), NULL);
	if (buff[fd] == NULL)
	{
		buff[fd] = malloc((size_t)BUFFER_SIZE + 1);
		if (!buff[fd])
			return (free(result), NULL);
		result = readncheck(buff[fd], fd, result);
		if (!result)
			return (free_helper(&buff[fd]), NULL);
		return (result);
	}
	result = result_combiner(result, buff[fd], fd);
	if (!result)
		return (free_helper(&buff[fd]), NULL);
	return (result);
}
