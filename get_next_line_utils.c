/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouzel <yabouzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:57:49 by yabouzel          #+#    #+#             */
/*   Updated: 2025/11/27 05:44:43 by yabouzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	int		size;
	int		i;
	char	*str;

	i = 0;
	size = ft_strlen(s);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*ns;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ns = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ns)
		return (NULL);
	while (*s1 != '\0')
	{
		ns[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		ns[i] = *s2;
		i++;
		s2++;
	}
	ns[i] = '\0';
	return (ns);
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = dest;
	s = src;
	if (src == dest)
		return (dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
