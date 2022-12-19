/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3d_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:18:53 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/19 16:41:09 by iouazzan         ###   ########.fr       */
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
		j + data->st_y, 16772045);
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
		j + data->st_y, 13166335);
		j++;
	}
}

int	way(t_data *data, int nb, int t_setX, int t_setY)
{
	if (data->raycat->rays[nb].was_H_V == 1)
	{
		if ((data->pp_y - data->raycat->rays[nb].wallhit_x) < 0)
			return (*(int*)(data->east.addr + t_setY * data->east.line_length + t_setX * 4));
		else
			return (*(int*)(data->west.addr + t_setY * data->west.line_length + t_setX * 4));
	}
	else
	{
		if ((data->pp_x - data->raycat->rays[nb].wallhit_y) < 0)
			return (*(int*)(data->north.addr + t_setY * data->north.line_length + t_setX * 4));
		else
			return (*(int*)(data->south.addr + t_setY * data->south.line_length + t_setX * 4));
	}
}

void	draw_wall(t_data *data, int in, int wallstrip_h)
{
	int				j;
	int				t_setX;
	int				t_setY;
	int				dis_top;
	int				way_d;

	t_setX = (int)data->raycat->rays[in].wallhit_y % SIZE_WIN;
	if (data->raycat->rays[in].was_H_V == 0)
		t_setX = (int)data->raycat->rays[in].wallhit_x % SIZE_WIN;
	j = data->raycat->rays[in].wl_y;
	while (j < data->raycat->rays[in].wl_y + data->raycat->rays[in].wl_h)
	{
		dis_top = j + (wallstrip_h / 2) - (data->gm->map_h / 2);
		t_setY = dis_top * ((float)SIZE_WIN / wallstrip_h);
		way_d = way(data, in , t_setX, t_setY);
		my_mlx_pixel_put(data, in, j, way_d);
		j++;
	}
}

void	get_walls_dimension(t_data *data, float wallstrip_h, int i)
{
	data->raycat->rays[i].wl_t = (data->gm->map_h / 2) - (wallstrip_h / 2);
	data->raycat->rays[i].wl_b = (data->gm->map_h / 2) + (wallstrip_h / 2);
	if (data->raycat->rays[i].wl_t < 0)
		data->raycat->rays[i].wl_t = 0;
	if (data->raycat->rays[i].wl_b > data->gm->map_h)
		data->raycat->rays[i].wl_b = data->gm->map_h;
	data->raycat->rays[i].wl_h = data->raycat->rays[i].wl_b - \
	data->raycat->rays[i].wl_t;
	data->raycat->rays[i].wl_x = data->raycat->wall_strip_width * i;
	data->raycat->rays[i].wl_y = data->raycat->rays[i].wl_t;
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
