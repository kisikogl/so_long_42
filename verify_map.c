/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:56:28 by kisikogl          #+#    #+#             */
/*   Updated: 2022/11/29 16:21:32 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	check_map(char *argv)
{
	size_t	len;
	size_t	row;
	char	c;

	row = 0;
	c = examine_map(open(argv, O_RDWR), &len, &row, 0);
	if (c != 0)
		return (c);
	c = scan_map(open (argv, O_RDWR), 0, 0, 0);
	if (c != 0)
		return (c);
	c = floodfill(argv, row, len, 0);
	if (c != 0)
		return (c);
	return (0);
}

char	scan_map(int fd, char is_e, char is_c, char is_p)
{
	char	c;
	char	*line;
	size_t	len;
	size_t	i;

	line = get_next_line(fd);
	len = ft_linelen(line);
	while (line)
	{
		i = 0;
		while (i < len)
		{
			c = line[i++];
			if (what_is_c(c, &is_c, &is_e, &is_p) == 'i')
				return ('i');
		}
		free(line);
		line = get_next_line(fd);
	}
	if (is_p > 1 || is_e > 1)
		return ('p');
	if ((is_c + is_e + is_p) != 3)
		return ('-');
	return (0);
}

char	what_is_c(char c, char *is_c, char *is_e, char *is_p)
{
	if (c == 'C')
		*is_c = 1;
	else if (c == 'E')
		(*is_e)++;
	else if (c == 'P')
		(*is_p)++;
	else if (c != '0' && c != '1' && c != 'F' && c != '\n')
		return ('i');
	return (0);
}

char	examine_map(int fd, size_t *len, size_t *row, size_t i)
{
	char	*line;
	char	*prevline;

	line = get_next_line(fd);
	*len = ft_linelen(line);
	prevline = malloc(*len + 1);
	if (prevline == NULL)
		return ('S');
	while (line)
	{
		if (*len != ft_linelen(line))
			return ('r');
		if (line[0] != '1' || line[*len - 1] != '1')
			return ('1');
		ft_strlcpy(prevline, line, *len + 1);
		free(line);
		line = get_next_line(fd);
		i = 0;
		if ((*row)++ == 0 || line == NULL)
			while (i < *len)
				if (prevline[i++] != '1')
					return ('1');
	}
	free(prevline);
	return (0);
}

void	move_ship(mlx_t *mlx, t_images *img, int *meters)
{
	*meters += 3;
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		if (load_ship_png(mlx, 0, 0, 'W') == 2)
			img->ship->instances[0].y -= 3;
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		if (load_ship_png(mlx, 0, 0, 'S') == 2)
			img->ship->instances[0].y += 3;
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		if (load_ship_png(mlx, 0, 0, 'A') == 2)
			img->ship->instances[0].x -= 3;
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		if (load_ship_png(mlx, 0, 0, 'D') == 2)
			img->ship->instances[0].x += 3;
	}
	else
		*meters -= 3;
}
