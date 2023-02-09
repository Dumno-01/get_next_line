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

char	*rm_line(char *str, char *line)
{
	char *tmp;
	int i;
	i = ft_strchr(str, line);
	tmp = ft_strdup(&str[i + 1], tmp);
	free(str);
	return(tmp);
}

char	*get_line(char *str)
{
	int i;
	char *line;
	int j;

	j = 0;
	i = ft_strnlen(str);
	line = malloc(sizeof (char) * i + 1);
	while (j != '\n' || j != '\0')
	{
		line[j] = str[j];
		j++;
	}
	return(line);
}

char	*readbuff(int fd, char *str)
{
	char *buff[BUFFER_SIZE + 1];
	char *strtmp;
	int i;
	while (find_newline(buff) != 1)
	{
		i = read(fd, buff, BUFFER_SIZE);
		strtmp = ft_strdup(str, strtmp);
		free(str);
		str = ft_strjoin(str, strtmp);
		free (strtmp);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	
	str = readbuff(fd, str);
	line = get_line(str);
	str = rm_line(str, line);
	return (line);
}