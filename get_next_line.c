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

char	*rm_line(char *buff)
{}

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
	int i;
	int j;
	int k;

	while (i < j)
	{
		if (i == '\n' || i == '\0')
		{
			k++;
			break;
		}
		i++;
	}
	if (k > 0)
		
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*buff;

	buff = readbuff(fd, str);
	line = get_line(buff);
	str = rm_line(buff);
	return (line);
}
