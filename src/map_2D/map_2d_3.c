/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:34:28 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/20 15:11:02 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	map_position(t_data *data)
{
	data->st_x = 0;
	data->st_y = 0;
	if (data->gm->nb_col * 64 < MAP_W)
		data->st_x = (MAP_W - data->gm->map_w) / 2;
	if (data->gm->nb_row * 64 < MAP_H)
		data->st_y = (MAP_H - data->gm->map_h) / 2;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!(x >= 0 && x < MAP_W && y >= 0 && y < MAP_H))
		return ;
	dst = data->img->addr + (y * data->img->line_length + x * \
		(data->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	setup_player(t_data *data)
{
	int	x;
	int	y;
	int	width;
	int	length;

	width = 5;
	length = width * 1.5 ;
	x = width;
	while (x >= -width)
	{
		y = -length;
		while (y <= length)
		{
			if (sqrt(pow(x, 2) + pow(y, 2)) <= width)
				mlx_pixel_put(data->gm->mlx, data->mlx_win,
					(y + data->pp_y) * SCALE,
					(x + data->pp_x) * SCALE,
					16101555);
			++y;
		}
		x -= 2;
	}
}

void	mouve_player(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 0, key_hookdown, data);
	mlx_hook(data->mlx_win, 3, 0, key_hookup, data);
	mlx_hook(data->mlx_win, 6, 0, mouse_hook, data);
}
