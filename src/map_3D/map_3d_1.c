/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3d_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:18:53 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/13 21:37:07 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	draw_floor(t_data *data, int in)
{
	int	i;
	int	j;

	if (data->raycat->rays[in].wl_t <= 0)
		return ;
	i = data->raycat->rays[in].wl_x;
	while (i < (data->raycat->rays[in].wl_x + data->raycat->wall_strip_width))
	{
		j = data->raycat->rays[in].wl_b;
		while (j < data->gm->map_h)
		{
			mlx_pixel_put(data->gm->mlx, data->mlx_win, i + data->st_x, \
			j + data->st_y, data->gm->c_f);
			j++;
		}
		i++;
	}
}

void	draw_ceilling(t_data *data, int in)
{
	int	i;
	int	j;

	if (data->raycat->rays[in].wl_t <= 0)
		return ;
	i = data->raycat->rays[in].wl_x;
	while (i < (data->raycat->rays[in].wl_x + data->raycat->wall_strip_width))
	{
		j = 0;
		while (j < data->raycat->rays[in].wl_t)
		{
			mlx_pixel_put(data->gm->mlx, data->mlx_win, i + data->st_x, \
			j + data->st_y, data->gm->c_c);
			j++;
		}
		i++;
	}
}

void	draw_wall(t_data *data, int in)
{
	int				i;
	int				j;
	unsigned long	col;

	i = data->raycat->rays[in].wl_x;
	col = 16777215;
	if (data->raycat->rays[in].ray_angl >= (5 * PI / 4) \
		&& data->raycat->rays[in].ray_angl <= (7 * PI / 4))
		col = 0;
	else if (data->raycat->rays[in].ray_angl >= (PI / 4) \
		&& data->raycat->rays[in].ray_angl <= (3 * PI / 4))
		col = 13229012;
	else if (data->raycat->rays[in].ray_angl > (7 * PI / 4) \
		|| data->raycat->rays[in].ray_angl < (PI / 4))
		col = 11691563;
	while (i < (data->raycat->rays[in].wl_x + data->raycat->wall_strip_width))
	{
		j = data->raycat->rays[in].wl_y;
		while (j < data->raycat->rays[in].wl_y + data->raycat->rays[in].wl_h)
		{
			mlx_pixel_put(data->gm->mlx, data->mlx_win, i + data->st_x, \
			j + data->st_y, col);
			j++;
		}
		i++;
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
		draw_wall(data, i);
		draw_ceilling(data, i);
		draw_floor(data, i);
		i++;
	}
}
