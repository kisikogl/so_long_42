/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:00:46 by kisikogl          #+#    #+#             */
/*   Updated: 2022/11/29 16:21:28 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	t_images	img;
	t_textures	tex;

	if (argc != 2 || !ft_strstr(argv[1], ".ber")
		|| *(ft_strstr(argv[1], ".ber") + 4))
	{
		ft_printf("Error\nGive me a map. And only one.");
		exit(EXIT_FAILURE);
	}
	if (get_error(argv[1]) == 1)
		return (EXIT_FAILURE);
	mlx = gset_mlx(create_window(argv[1], 0));
	if (!mlx)
		exit(EXIT_FAILURE);
	create_images(mlx, &img);
	gset_img(&img);
	gset_tex(&tex);
	create_map(mlx, argv[1]);
	mlx_loop_hook(mlx, move_character, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

void	move_character(void *mlx)
{
	static int	meters;
	t_images	*img;

	img = gset_img(NULL);
	if (img->ship->enabled != false)
		move_ship(mlx, img, &meters);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mlx);
	}
	if (meters > 0)
		ft_printf("\rMeters travelled: %d, which is %d moves.",
			meters, meters / 30);
}

t_images	*gset_img(t_images *p_img)
{
	static t_images	*img;

	if (p_img != NULL)
		img = p_img;
	return (img);
}

t_textures	*gset_tex(t_textures *p_tex)
{
	static t_textures	*tex;

	if (p_tex != NULL)
		tex = p_tex;
	return (tex);
}

mlx_t	*gset_mlx(mlx_t *p_mlx)
{
	static mlx_t	*mlx;

	if (p_mlx != NULL)
		mlx = p_mlx;
	return (mlx);
}
