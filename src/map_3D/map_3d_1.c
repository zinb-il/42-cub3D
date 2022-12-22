/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3d_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:18:53 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/22 14:07:23 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	draw_floor(t_data *data, int in)
{
	int	j;

	if (data->raycat->rays[in].wl_t <= 0)
		return ;
	j = data->raycat->rays[in].wl_b;
	while (j < data->gm->map_h)
	{
		my_mlx_pixel_put(data, in + data->st_x, \
		j + data->st_y, data->gm->c_f);
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
		my_mlx_pixel_put(data, in + data->st_x, \
		j + data->st_y, data->gm->c_c);
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
	distance_pro = (data->gm->map_w / 2) / tan(data->raycat->fov_angl / 2);
	while (i < data->raycat->num_rays)
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
	mlx_put_image_to_window(data->gm->mlx, data->mlx_win, data->img->img, 0, 0);
	mini_map(data);
}
