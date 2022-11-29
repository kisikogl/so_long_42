/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:22:28 by kisikogl          #+#    #+#             */
/*   Updated: 2022/07/14 13:40:10 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	read_until_n(char *buf, char **line_pointer, int fd, int error)
{
	int	i;

	while (1)
	{
		error = read(fd, buf, BUFFER_SIZE);
		if (error == 0 && **line_pointer != '\0')
			break ;
		if (error <= 0)
		{
			free(*line_pointer);
			return (-3);
		}
		if (error < BUFFER_SIZE)
			buf[error] = '\0';
		i = 0;
		while (buf[i] != '\n' && buf[i] != '\0')
			i++;
		if (buf[i] == '\n')
			break ;
		*line_pointer = join_string(*line_pointer, buf, 1);
	}
	return (error);
}

char	*get_one_line(int fd, char *line, char *buf)
{
	static char	*save;
	char		**line_pointer;
	int			error;

	line_pointer = &line;
	error = 0;
	if (save)
	{
		line = join_string(line, until_n(save, &error), 2);
		save = after_n(save, 1);
		if (error == 1)
			return (line);
	}
	error = read_until_n(buf, line_pointer, fd, error);
	if (error == -3)
		return (NULL);
	if (error != 0)
	{
		line = join_string(line, until_n(buf, &error), 2);
		save = after_n(buf, 0);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;

	if (fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	buf[BUFFER_SIZE] = '\0';
	line = malloc(1);
	*line = '\0';
	line = get_one_line(fd, line, buf);
	free(buf);
	return (line);
}
