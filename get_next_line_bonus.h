/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/09 15:33:49 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/06/10 14:26:58 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

void	*gnl_memmove(void *dst, const void *src, int n);
int		gnl_strchr(const char *s, int c);
char	*gnl_strdup(char *s1, int len);
char	*gnl_strjoin(const char *s1, const char *s2);
int		gnl_strlen(const char *s);
int		get_next_line(int fd, char **line);

#endif
