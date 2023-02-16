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
	char *tmp;
	int i;
	i = ft_strchr(str, '\n');
	if (str [i] == '\n')
		tmp = ft_strdup(&str[i + 1]);
	if (str[i] == '\0')
		tmp = NULL;
	free(str);
	return(tmp);
}

static char	*get_line(char *str)
{
	int i;
	char *line;
	int j;

	j = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		line = malloc(sizeof (char) * i + 1);
	if (str[i] == '\n')
		line = malloc(sizeof (char) * i + 2);
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

static char	*readbuff(int fd, char *str)
{
	char buff[BUFFER_SIZE + 1];
	char *strtmp;
	int i;

	i = BUFFER_SIZE;
	strtmp = NULL;
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return(NULL);
		if (str != NULL)
		{
	 		strtmp = ft_strdup(str);
		}
		buff[i] = 0;
		if (strtmp)
			str = ft_strjoin(strtmp, buff);
		else
		{
			str = ft_strdup(buff);
		}
		free (strtmp);
		if (i < BUFFER_SIZE || find_newline(buff, BUFFER_SIZE) == 1)
			break;
	}
	return (str);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}	
	return (i);
}


char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	line = NULL;	
	str = readbuff(fd, str);
	line = get_line(str);
	str = rm_line(str);
	return (line);
}

int main()
{
	int i = 0;
	int fd;
	char *line;
	fd = open("1.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL && i < 8)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
}