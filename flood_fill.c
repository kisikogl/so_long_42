/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:01:05 by kisikogl          #+#    #+#             */
/*   Updated: 2022/11/29 16:21:12 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	floodfill(char *argv, size_t rows, size_t columns, int fd)
{
	char		**map;
	char		*line;
	size_t		i;
	size_t		x;
	size_t		y;

	fd = open(argv, O_RDONLY);
	i = 0;
	map = malloc(rows * sizeof(char *));
	if (map == NULL)
		return ('S');
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = malloc(columns + 1);
		if (map[i] == NULL)
			return ('S');
		ft_strlcpy(map[i++], line, columns + 1);
		free(line);
		line = get_next_line(fd);
	}
	find_p(map, &x, &y, columns);
	i = fill(map, x, y, rows);
	free_map(map, rows);
	return (i);
}

void	free_map(char **map, size_t rows)
{
	size_t	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	find_p(char **map, size_t *x, size_t *y, size_t columns)
{
	char	c;

	c = '0';
	*x = 0;
	*y = 1;
	while (c != 'P')
	{
		if (*x < columns - 2)
			(*x)++;
		else
		{
			*x = 1;
			(*y)++;
		}
		c = map[*y][*x];
	}
}

int	fill(char **map, size_t x, size_t y, size_t rows)
{
	if (x < 1 || y < 1 || x > ft_strlen(*map) - 2 || y > rows
		|| map [y][x] == '1' || map [y][x] == 'F')
		return ('v');
	if (map[y][x] == 'E')
		return (0);
	map[y][x] = '1';
	if (fill(map, x - 1, y, rows) == 0
		|| fill(map, x + 1, y, rows) == 0
		|| fill(map, x, y - 1, rows) == 0
		|| fill(map, x, y + 1, rows) == 0)
		return (0);
	else
		return ('v');
}
