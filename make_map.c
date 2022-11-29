/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:01:04 by kisikogl          #+#    #+#             */
/*   Updated: 2022/11/29 16:21:20 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	get_error(char *argv)
{
	char	err;

	err = check_map(argv);
	if (err == 'i')
		ft_printf("Error\nInvalid character. Valid chars: 0, 1, C, E, P, F\n");
	else if (err == 'r')
		ft_printf("Error\nThe map must be rectangular.\n");
	else if (err == '1')
		ft_printf("Error\nThe map must be surrounded and closed by walls.\n");
	else if (err == '-')
		ft_printf("Error\nThe map must contain 'E', 'P', and 'C'.\n");
	else if (err == 'p')
		ft_printf("Error\nThere can only be ONE player and ONE exit.\n");
	else if (err == 'v')
		ft_printf("Error\nThere is no valid path to the exit");
	else if (err == 'S')
		ft_printf("Error\nCouldn't malloc properly...");
	else
		return (0);
	return (1);
}

void	create_map(mlx_t *mlx, char *map)
{
	int		i;
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		i = 0;
		x = 0;
		while (line[i] != '\n' && line[i] != '\0')
		{
			call_loads(mlx, line[i], x, y);
			x += 32;
			i++;
		}
		free(line);
		line = get_next_line(fd);
		y += 32;
	}
	close(fd);
}

void	call_loads(mlx_t *mlx, char c, int x, int y)
{
	if (c == '0' || c == 'P' || c == 'C')
		load_sea_png(mlx, x, y, '0');
	if (c == '1')
		load_fire_png(mlx, x, y);
	if (c == 'C' || c == 'F')
		load_characters_png(mlx, x, y, c);
	if (c == 'E')
		load_portal_png(mlx, x, y, 0);
	if (c == 'P')
		load_ship_png(mlx, x, y, 'F');
}

mlx_t	*create_window(char *map, int i)
{
	mlx_t	*mlx;
	int		x;
	int		y;
	int		fd;
	char	*buf;

	y = 0;
	fd = open(map, O_RDWR);
	buf = get_next_line(fd);
	while (buf != 0)
	{
		x = 0;
		while (buf[i] != '\n' && buf[i] != '\0')
			i++;
		x = i;
		i = 0;
		y++;
		free(buf);
		buf = get_next_line(fd);
	}
	mlx = mlx_init(x * 32, y * 32, "Escape the Ocean", 1);
	return (mlx);
}

void	create_images(mlx_t *mlx, t_images *img)
{
	img->sea = mlx_new_image(mlx, 32, 32);
	img->ship = mlx_new_image(mlx, 64, 64);
	img->fire = mlx_new_image(mlx, 32, 32);
	img->portal = mlx_new_image(mlx, 32, 32);
	img->viking = mlx_new_image(mlx, 32, 32);
	img->pirate = mlx_new_image(mlx, 32, 32);
}
