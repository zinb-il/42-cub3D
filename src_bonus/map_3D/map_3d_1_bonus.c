/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3d_1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:18:53 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/03 21:09:11 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3D_bonus.h"

void	draw_floor(t_data *data, int in)
{
	int	j;

	if (data->raycat->rays[in].wl_t <= 0)
		return ;
	j = data->raycat->rays[in].wl_b;
	while (j < MAP_H)
	{
		my_mlx_pixel_put(data, in, j, data->gm->c_f);
		j++;
	}
}

void	draw_ceilling(t_data *data, int in)
{
	int	j;

	if (data->raycat->rays[in].wl_t <= 0)
		return ;
	j = 0;
	while (j < data->raycat->rays[in].wl_t)
	{
		my_mlx_pixel_put(data, in, j, data->gm->c_c);
		j++;
	}
}

void	map_3d(t_data *data)
{
	int		i;
	float	distance_pro;
	float	wallstrip_h;
	float	distance;

	i = 0;
	distance_pro = (MAP_W / 2) / tan(data->raycat->fov_angl / 2);
	while (i < MAP_W)
	{
		distance = data->raycat->rays[i].distance * \
		cos(data->raycat->rays[i].ray_angl - data->retation);
		wallstrip_h = (SIZE_WIN / distance) * distance_pro;
		get_walls_dimension(data, wallstrip_h, i);
		draw_wall(data, i, (int)wallstrip_h);
		draw_ceilling(data, i);
		draw_floor(data, i);
		i++;
	}
	get_visible_sprites(data);
	mlx_put_image_to_window(data->gm->mlx, data->mlx_win, data->img->img, 0, 0);
	mini_map(data);
}
