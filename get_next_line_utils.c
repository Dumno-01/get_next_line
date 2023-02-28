/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:07:54 by ffreze            #+#    #+#             */
/*   Updated: 2023/01/26 13:15:23 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	i = 0;
	j = 0;
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (free(s1), NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = 0;
	return (free(s1), join);
}

char	*ft_strdup(char *src)
{
	char	*s2;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (0);
	while (src[i] != '\0')
	{
		s2[i] = src[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i])
		return (&s[i]);
	return (NULL);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	t_src;
	size_t	t_dest;

	i = 0;
	t_dest = ft_strlen(dest);
	t_src = ft_strlen(src);
	if (size == 0)
		return (t_src);
	while (src[i] != '\0' && t_dest + i < size - 1)
	{
		dest[t_dest + i] = src[i];
		i++;
	}
	dest[t_dest + i] = '\0';
	if (size < t_dest)
		return (t_src + size);
	return (t_dest + t_src);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}	
	return (i);
}
