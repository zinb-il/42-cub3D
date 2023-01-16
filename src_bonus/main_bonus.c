/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:08:36 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/16 23:26:57 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3D_bonus.h"

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
	mouve_player(data);
	start_raycast(data);
	map_3d(data);
	return (0);
}

void	init_img_sprite(t_data *data)
{
	int		w;
	int		y;
	void	*img;

	w = 0;
	y = 0;
	img = mlx_xpm_file_to_image(data->gm->mlx, SPRITE1, &w, &y);
	if (!img)
		ft_print_errors(strerror(errno));
	data->sprite1.img = img;
	data->sprite1.addr = mlx_get_data_addr(data->sprite1.img, \
		&data->sprite1.bits_per_pixel, &data->sprite1.line_length, \
		&data->sprite1.endian);
	img = mlx_xpm_file_to_image(data->gm->mlx, SPRITE2, &w, &y);
	if (!img)
		ft_print_errors(strerror(errno));
	data->sprite2.img = img;
	data->sprite2.addr = mlx_get_data_addr(data->sprite2.img, \
		&data->sprite2.bits_per_pixel, &data->sprite2.line_length, \
		&data->sprite2.endian);
}

void	init_img_door(t_data *data)
{
	int		w;
	int		y;
	void	*img;

	w = 0;
	y = 0;
	img = mlx_xpm_file_to_image(data->gm->mlx, DOOR1, &w, &y);
	if (!img)
		ft_print_errors(strerror(errno));
	data->door1.img = img;
	data->door1.addr = mlx_get_data_addr(data->door1.img, \
		&data->door1.bits_per_pixel, &data->door1.line_length, \
		&data->door1.endian);
}

void	init_img(t_data *data)
{
	init_img_sprite(data);
	init_img_door(data);
	data->img->img = mlx_new_image(data->gm->mlx, MAP_W, MAP_H);
	data->img->addr = mlx_get_data_addr(data->img->img, \
		&data->img->bits_per_pixel, &data->img->line_length, \
		&data->img->endian);
	data->north.img = data->gm->w_no;
	data->north.addr = mlx_get_data_addr(data->north.img, \
		&data->north.bits_per_pixel, &data->north.line_length, \
		&data->north.endian);
	data->west.img = data->gm->w_we;
	data->west.addr = mlx_get_data_addr(data->west.img, \
		&data->west.bits_per_pixel, &data->west.line_length, \
		&data->west.endian);
	data->east.img = data->gm->w_ea;
	data->east.addr = mlx_get_data_addr(data->east.img, \
		&data->east.bits_per_pixel, &data->east.line_length, \
		&data->east.endian);
	data->south.img = data->gm->w_so;
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
	init_sprites(data);
	// mouve_player(data);
	// start_raycast(data);
	// map_3d(data);
	//ft_print_game(gm);
	//print_sprite(data);
	mlx_loop_hook(data->gm->mlx, game, data);
	mlx_loop(data->gm->mlx);
	return (0);
}
