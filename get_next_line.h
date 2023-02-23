/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:08:29 by ffreze            #+#    #+#             */
/*   Updated: 2023/01/26 13:21:16 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char    *ft_strchr(char *s, char c);
size_t	ft_strlcat(char *dest, char *src, size_t size);
int     find_newline(char *s, int bs);
int     ft_strlen(char *str);
char	*get_next_line(int fd);
# endif