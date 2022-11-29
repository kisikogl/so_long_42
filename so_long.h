/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:03:38 by kisikogl          #+#    #+#             */
/*   Updated: 2022/11/07 15:42:29 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_textures
{
	mlx_texture_t	*ship;
	mlx_texture_t	*sea;
	mlx_texture_t	*fire;
	mlx_texture_t	*viking;
	mlx_texture_t	*portal;
	mlx_texture_t	*pirate;
	mlx_texture_t	*end_screen;
}	t_textures;

typedef struct s_images
{
	mlx_image_t	*ship;
	mlx_image_t	*sea;
	mlx_image_t	*fire;
	mlx_image_t	*viking;
	mlx_image_t	*portal;
	mlx_image_t	*pirate;
	mlx_image_t	*end_screen;
}	t_images;

t_images	*gset_img(t_images *p_img);
t_textures	*gset_tex(t_textures *p_tex);
mlx_t		*gset_mlx(mlx_t *p_mlx);
void		move_character(void *mlx);
char		check_map(char *argv);
char		get_error(char *argv);
void		create_map(mlx_t *mlx, char *map);
void		call_loads(mlx_t *mlx, char c, int x, int y);
mlx_t		*create_window(char *map, int i);
int			main(int argc, char **argv);
char		load_ship_png(mlx_t *mlx, int x, int y, char direction);
void		load_sea_png(mlx_t *mlx, int x, int y, char c);
void		load_fire_png(mlx_t *mlx, int x, int y);
void		load_portal_png(mlx_t *mlx, int x, int y, char end);
void		load_characters_png(mlx_t *mlx, int x, int y, char chr);
char		check_position(mlx_image_t *obj, char symbol);
char		isfire(int x_margin, int y_margin,
				mlx_instance_t *obj_ins, char symbol);
char		check_for_viking(mlx_instance_t *obj_ins, char symbol);
char		check_for_pirate(char symbol);
char		check_for_exit(void);
int			floodfill(char *argv, size_t rows, size_t columns, int fd);
void		free_map(char **mape, size_t rows);
void		find_p(char **mape, size_t *x, size_t *y, size_t columns);
int			fill(char **mape, size_t x, size_t y, size_t rows);
char		scan_map(int fd, char is_e, char is_c, char is_p);
char		examine_map(int fd, size_t *len, size_t *row, size_t i);
char		what_is_c(char c, char *is_c, char *is_e, char *is_p);
void		create_images(mlx_t *mlx, t_images *img);
void		move_ship(mlx_t *mlx, t_images *img, int *meters);

#endif
