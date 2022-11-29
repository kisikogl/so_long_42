/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_png.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:01:01 by kisikogl          #+#    #+#             */
/*   Updated: 2022/11/29 16:21:16 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	load_ship_png(mlx_t *mlx, int x, int y, char direction)
{
	t_textures	*tex;
	t_images	*img;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	if (direction == 'W')
		tex->ship = mlx_load_png("Art/shipu.png");
	if (direction == 'S')
		tex->ship = mlx_load_png("Art/shipd.png");
	if (direction == 'A')
		tex->ship = mlx_load_png("Art/shipl.png");
	if (direction == 'D')
		tex->ship = mlx_load_png("Art/shipr.png");
	if (direction == 'F')
	{
		tex->ship = mlx_load_png("Art/shipr.png");
		mlx_draw_texture(img->ship, tex->ship, 0, 0);
		mlx_image_to_window(mlx, img->ship, x, y);
		mlx_set_instance_depth(img->ship->instances, 5);
	}
	mlx_draw_texture(img->ship, tex->ship, 0, 0);
	mlx_delete_texture(tex->ship);
	check_position(img->viking, 'C');
	check_position(img->portal, 'E');
	return (check_position(img->fire, '1') + check_position(img->pirate, 'F'));
}

void	load_sea_png(mlx_t *mlx, int x, int y, char c)
{
	t_textures	*tex;
	t_images	*img;
	int			i;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	tex->sea = mlx_load_png("Art/sea.png");
	if (c == '0')
	{
		mlx_draw_texture(img->sea, tex->sea, 0, 0);
		mlx_delete_texture(tex->sea);
		i = mlx_image_to_window(mlx, img->sea, x, y);
		mlx_set_instance_depth(img->sea->instances + i, 2);
	}
	if (c == 'C')
		mlx_draw_texture(img->viking, tex->sea, 0, 0);
	if (c == 'F')
		mlx_draw_texture(img->pirate, tex->sea, 0, 0);
}

void	load_fire_png(mlx_t *mlx, int x, int y)
{
	t_textures	*tex;
	t_images	*img;
	int			i;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	i = mlx_image_to_window(mlx, img->fire, x, y);
	tex->fire = mlx_load_png("Art/fire.png");
	mlx_draw_texture(img->fire, tex->fire, 0, 0);
	mlx_set_instance_depth(img->fire->instances + i, 2);
	mlx_delete_texture(tex->fire);
}

void	load_characters_png(mlx_t *mlx, int x, int y, char chr)
{
	t_textures	*tex;
	t_images	*img;
	int			i;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	if (chr == 'C')
	{
		i = mlx_image_to_window(mlx, img->viking, x, y);
		tex->viking = mlx_load_png("Art/viking.png");
		mlx_draw_texture(img->viking, tex->viking, 0, 0);
		mlx_set_instance_depth(img->viking->instances + i, 3);
		mlx_delete_texture(tex->viking);
	}
	if (chr == 'F')
	{
		i = mlx_image_to_window(mlx, img->pirate, x, y);
		tex->pirate = mlx_load_png("Art/pirate.png");
		mlx_draw_texture(img->pirate, tex->pirate, 0, 0);
		mlx_set_instance_depth(img->pirate->instances + i, 3);
		mlx_delete_texture(tex->pirate);
	}
}

void	load_portal_png(mlx_t *mlx, int x, int y, char end)
{
	t_textures	*tex;
	t_images	*img;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	if (end == 'L')
		tex->end_screen = mlx_load_png("Art/lose.png");
	if (end == 'V')
		tex->end_screen = mlx_load_png("Art/victory.png");
	if (end == 'L' || end == 'V')
	{
		img->end_screen = mlx_new_image(mlx, x, y);
		mlx_image_to_window(mlx, img->end_screen, mlx->width / 2 - 190, 0);
		mlx_draw_texture(img->end_screen, tex->end_screen, 0, 0);
		mlx_set_instance_depth(img->end_screen->instances, 8);
		mlx_delete_texture(tex->end_screen);
		return ;
	}
	mlx_image_to_window(mlx, img->portal, x, y);
	tex->portal = mlx_load_png("Art/portal.png");
	mlx_draw_texture(img->portal, tex->portal, 0, 0);
	mlx_set_instance_depth(img->portal->instances, 4);
	mlx_delete_texture(tex->portal);
}
