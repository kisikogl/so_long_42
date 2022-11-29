/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:00:51 by kisikogl          #+#    #+#             */
/*   Updated: 2022/11/29 16:21:23 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	check_position(mlx_image_t *obj, char symbol)
{
	int				i;
	int				x_margin;
	int				y_margin;
	mlx_instance_t	*ins;
	t_images		*img;

	i = 0;
	img = gset_img(NULL);
	ins = obj->instances;
	while (i < obj->count)
	{
		if (ins[i].x < img->ship->instances->x)
			x_margin = 32;
		else
			x_margin = 32;
		if (ins[i].y < img->ship->instances->y)
			y_margin = 16;
		else
			y_margin = 32;
		if (fabs((float)(ins[i].x - img->ship->instances->x)) < x_margin)
			if (fabs((float)(ins[i].y - img->ship->instances->y)) < y_margin)
				return (isfire(x_margin, y_margin, ins + i, symbol));
		i++;
	}
	return (1);
}

char	isfire(int x_margin, int y_margin, mlx_instance_t *obj_ins, char symbol)
{
	t_images		*img;
	mlx_instance_t	*ship_ins;

	if (symbol != '1')
		return (check_for_viking(obj_ins, symbol));
	img = gset_img(NULL);
	ship_ins = img->ship->instances;
	if (!(fabs((float)((obj_ins->x + 6) - ship_ins->x)) < x_margin))
		ship_ins->x -= 1;
	if (!(fabs((float)(obj_ins->x - (ship_ins->x + 6))) < x_margin))
		ship_ins->x += 1;
	if (!(fabs((float)((obj_ins->y + 6) - ship_ins->y)) < y_margin))
		ship_ins->y -= 1;
	if (!(fabs((float)(obj_ins->y - (ship_ins->y + 6))) < y_margin))
		ship_ins->y += 1;
	return (0);
}

char	check_for_viking(mlx_instance_t *obj_ins, char symbol)
{
	if (symbol != 'C')
		return (check_for_pirate(symbol));
	obj_ins->enabled = false;
	return (1);
}

char	check_for_pirate(char symbol)
{
	t_images	*img;

	if (symbol != 'F')
		return (check_for_exit());
	img = gset_img(NULL);
	if (img->ship->enabled == true)
		load_portal_png(gset_mlx(NULL), 370, 140, 'L');
	img->ship->enabled = false;
	img->viking->enabled = false;
	return (1);
}

char	check_for_exit(void)
{
	t_images	*img;
	int			i;

	img = gset_img(NULL);
	i = 0;
	while (i < img->viking->count)
	{
		if (img->viking->instances[i].enabled == true)
			return (0);
		i++;
	}
	load_portal_png(gset_mlx(NULL), 389, 170, 'V');
	img->ship->enabled = false;
	if (img->viking->enabled == false)
		img->end_screen->enabled = false;
	return (1);
}
