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

static void rm_line2(char *line, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		str[0] = 0;
	else
	{
		i++;
		while (line[i] && str[j])
		{
			str[j] = line[i];
			i++;
			j++;
		}
		str[j] = 0;
	}
}

static void	*ft_memset(void *p, int value, size_t count)
{
	size_t	i;

	i = 0;
	while (count != i)
	{
		((char *)p)[i] = value;
		i++;
	}
	return (p);
}

static char	*get_line2(char *line)
{
	char	*new;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (free(line), NULL);
	ft_memset(new, 0, i + 1);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new[i] = line[i];
		i++;
	}
	new[i] = line[i];
	if (line[i])
		new[i + 1] = 0;
	return (free(line), new);
}

static char	*readbuff(int fd, char *str, int i)
{
	char	*line;

	line = malloc(sizeof(char));
	if (!line)
		return (NULL);
	line[0] = 0;
	while (i > 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
			return(free(line), NULL);
		str[i] = 0;
		if (str[0])
		{
			line = ft_strjoin(line, str);
			if (!line)
				return(NULL);
		}
		else
			return (free(line), NULL);
		if (i < BUFFER_SIZE || ft_strchr(str, '\n', 2))
			break;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	int			i;

	if (!str)
		str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	i = BUFFER_SIZE;
	line = readbuff(fd, str, i);
	if (!line)
		return (free(str), str = NULL, NULL);
	rm_line2(line, str);
	line = get_line2(line);
	if (!line)
		return (free(str), str = NULL, NULL);
	return (line);
}

int main()
{
	int	i;
	int fd;
	char *line;
	fd = open("3.txt", O_RDONLY);
	line = get_next_line(fd);

	i = 0;
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		//line = NULL;
		i++;
	}
	close(fd);
	free (line);
	line = NULL;
	return (0);
}