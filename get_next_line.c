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

static char	*rm_line(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = ft_strchr(str, '\n', 1);
	if (str[i] == '\n')
	{
		tmp = ft_strdup(&str[i + 1]);
			if (!tmp)
				return (NULL);
	}
	if (str[i] == '\0')
		tmp = NULL;
	free(str);
	return(tmp);
}

static char	*get_line(char *str, char *line)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		line = malloc(sizeof (char) * i + 1);
	if (str[i] == '\n')
		line = malloc(sizeof (char) * i + 2);
	if (!line)
		return (NULL);
	while (str[j] != '\n' && str[j] != '\0')
	{
		line[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
	{
		line[j] = '\n';
		j++;
	}
	line[j] = '\0';
	return(line);
}

static char	*readbuff(int fd, char *str, int i)
{
	char strtmp[BUFFER_SIZE + 1];

	while (i > 0)
	{
		i = read(fd, strtmp, BUFFER_SIZE);
		if (i == -1)
			return(NULL);
		if (strtmp[i] != '\0')	
			strtmp[i] = 0;
		if (str)
		{
			str = ft_strjoin(str, strtmp);
			if (str == NULL)
				return(NULL);
		}
		else
			str = ft_strdup(strtmp);
			if (str == NULL)
				return(NULL);
				
		if (i < BUFFER_SIZE || ft_strchr(strtmp, '\n', 2) == 1)
			break;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	int			i;

	i = BUFFER_SIZE;
	line = NULL;	
	str = readbuff(fd, str, i);
	if (!str)
		return (NULL);
	line = get_line(str, line);
	if (!line)
		return (NULL);
	if (ft_strlen(str) == 0)
		line = NULL;
	str = rm_line(str);
	return (line);
}

int main()
{
	int fd;
	char *line;
	fd = open("1.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
}