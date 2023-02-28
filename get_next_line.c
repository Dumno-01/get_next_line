/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:07:15 by ffreze            #+#    #+#             */
/*   Updated: 2023/01/26 15:32:03 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char	*rm_line2(char *line, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i])
		i++;
	while (line[i] && j < BUFFER_SIZE)
	{
		str[j] = line[i];
		i++;
		j++;
	}
	while (j < BUFFER_SIZE)
	{
		str[j] = 0;
		j++;
	}
	return (str);
}

static char	*get_line2(char *line)
{
	int		i;
	int		len;
	char	*trim;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (line[len])
		len++;
	trim = malloc(sizeof(char) * (len + 1));
	if (!trim)
		return (free(line), NULL);
	i = 0;
	while (i < len)
	{
		trim[i] = line[i];
		i++;
	}
	trim[i] = 0;
	free(line);
	return (trim);
}

static char	*readbuff(int fd, char *str)
{
	int		i;
	char	*line;

	i = 1;
	line = malloc(sizeof(char));
	if (!line)
		return (NULL);
	line[0] = 0;
	if (str[0])
	{
		line = ft_strjoin(line, str);
		if (!line)
			return (NULL);
	}
	while (!ft_strchr(str, '\n') && i)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (!i && str[0] == 0)
			return (free(line), NULL);
		str[i] = 0;
		line = ft_strjoin(line, str);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (BUFFER_SIZE < 1 || BUFFER_SIZE > (SIZE_MAX - 1) || \
		read(fd, 0, 0) == -1)
		return (free(str), str = NULL, NULL);
	if (!str)
	{
		str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str)
			return (NULL);
		str[0] = 0;
	}
	line = readbuff(fd, str);
	if (!line)
		return (free(str), str = NULL, NULL);
	str = rm_line2(line, str);
	line = get_line2(line);
	if (!line)
		return (free(str), str = NULL, NULL);
	return (line);
}
