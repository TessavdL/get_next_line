/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/09 15:33:30 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/06/10 14:26:54 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	free_and_return(char **ret, int n)
{
	free(*ret);
	*ret = NULL;
	return (n);
}

static int	put_in_line(char **ret, char **line, int newline, int n)
{
	int	len;

	len = (gnl_strlen(*ret) - (newline - 1));
	if (newline == 0)
		newline = len;
	*line = gnl_strdup(*ret, newline - 1);
	if (!*line)
		return (free_and_return(ret, -1));
	if (n != 0)
		*ret = gnl_memmove(*ret, (*ret + newline), len);
	if (n == 0)
		return (free_and_return(ret, 0));
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*ret[1024];
	int			n;

	n = 1;
	if (fd < 0 || !line)
		return (-1);
	if (!ret[fd])
		ret[fd] = gnl_strdup("", 0);
	if (!ret[fd])
		return (-1);
	if (ret[fd] && (gnl_strchr(ret[fd], '\n') > 0))
		return (put_in_line(&ret[fd], line, gnl_strchr(ret[fd], '\n'), 1));
	while (n > 0 && !(gnl_strchr(ret[fd], '\n')))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
			return (free_and_return(&ret[fd], -1));
		buffer[n] = '\0';
		ret[fd] = gnl_strjoin(ret[fd], buffer);
		if (!ret[fd])
			return (-1);
	}
	return (put_in_line(&ret[fd], line, gnl_strchr(ret[fd], '\n'), n));
}
