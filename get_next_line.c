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
{}

char	*readbuff(int fd, char *str)
{}

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
