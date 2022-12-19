;/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:08:36 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/01 14:58:25 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	game(t_data *data)
{
	if (data->keys[0][0] > 0 || data->keys[0][1] > 0)
	{
		if (data->keys[0][0] == 1)
			data->retation -= ROTATION_SPEED;
		else if (data->keys[0][1] == 1)
			data->retation += ROTATION_SPEED;
	}
	if (data->keys[1][0] > 0 || data->keys[1][1] > 0)
	{
		if (data->keys[1][0] == 1)
			mouve(data, -1, 1);
		else if (data->keys[1][1] == 1)
			mouve(data, 1, 1);
	}
	else if (data->keys[2][0] > 0 || data->keys[2][1] > 0)
	{
		if (data->keys[2][0] == 1)
			mouve(data, -1, 0);
		else if (data->keys[2][1] == 1)
			mouve(data, 1, 0);
	}
	start_raycast(data);
	mouve_player(data);
	map_3d(data);
	return (0);
}

void	init_img(t_data *data)
{
	int	x;
	int	y;

	data->img->img = mlx_new_image(data->gm->mlx, MAP_W, MAP_H);
	data->img->addr = mlx_get_data_addr(data->img->img, \
		&data->img->bits_per_pixel, &data->img->line_length, \
		&data->img->endian);
	data->north.img = mlx_xpm_file_to_image(data->gm->mlx, "img_cub/wall_2.xpm", &x, &y);
	data->north.addr = mlx_get_data_addr(data->north.img, \
		&data->north.bits_per_pixel, &data->north.line_length, \
		&data->north.endian);
	data->west.img = mlx_xpm_file_to_image(data->gm->mlx, "img_cub/wall_1.xpm", &x, &y);
	data->west.addr = mlx_get_data_addr(data->west.img, \
		&data->west.bits_per_pixel, &data->west.line_length, \
		&data->west.endian);
	data->east.img = mlx_xpm_file_to_image(data->gm->mlx, "img_cub/wall_4.xpm", &x, &y);
	data->east.addr = mlx_get_data_addr(data->east.img, \
		&data->east.bits_per_pixel, &data->east.line_length, \
		&data->east.endian);
	data->south.img = mlx_xpm_file_to_image(data->gm->mlx, "img_cub/wall_3.xpm", &x, &y);
	data->south.addr = mlx_get_data_addr(data->south.img, \
		&data->south.bits_per_pixel, &data->south.line_length, \
		&data->south.endian);
}

int	main(int ac, char **av)
{
	t_game		*gm;
	t_data		*data;

	gm = first_part_cub3d(ac, av);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_print_errors(strerror(errno));
	init_data(gm, data);
	init_img(data);
	mlx_loop_hook(data->gm->mlx, game, data);
	mlx_loop(data->gm->mlx);
	return (0);
}
