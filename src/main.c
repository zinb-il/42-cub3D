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
			ret_left_right(data, -ROTATION_SPEED);
		else if (data->keys[0][1] == 1)
			ret_left_right(data, ROTATION_SPEED);
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
	map_2d(data);
	print_rays(data);
	mouve_player(data);
	map_3d(data);
	return (0);
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
	data->img->img = mlx_new_image(data->gm->mlx, MAP_W, MAP_H);
	data->img->addr = mlx_get_data_addr(data->img->img, \
		&data->img->bits_per_pixel, &data->img->line_length, \
		&data->img->endian);
	mlx_loop_hook(data->gm->mlx, game, data);
	mlx_loop(data->gm->mlx);
	return (0);
}
