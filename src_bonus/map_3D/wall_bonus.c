/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:46:48 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/16 23:26:49 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3D_bonus.h"

void	get_walls_dimension(t_data *data, float wallstrip_h, int i)
{
	data->raycat->rays[i].wl_t = (MAP_H / 2) - (wallstrip_h / 2);
	data->raycat->rays[i].wl_b = (MAP_H / 2) + (wallstrip_h / 2);
	if (data->raycat->rays[i].wl_t < 0)
		data->raycat->rays[i].wl_t = 0;
	if (data->raycat->rays[i].wl_b > MAP_H)
		data->raycat->rays[i].wl_b = MAP_H;
	data->raycat->rays[i].wl_h = data->raycat->rays[i].wl_b - \
	data->raycat->rays[i].wl_t;
	data->raycat->rays[i].wl_x = data->raycat->wall_strip_width * i;
	data->raycat->rays[i].wl_y = data->raycat->rays[i].wl_t;
}

void	draw_wall(t_data *data, int in, int wallstrip_h)
{
	int	j;
	int	t_setx;
	int	t_sety;
	int	dis_top;
	int	way_d;

	t_setx = (int)data->raycat->rays[in].wallhit_y % SIZE_WIN;
	if (data->raycat->rays[in].was_h_v == 0)
		t_setx = (int)data->raycat->rays[in].wallhit_x % SIZE_WIN;
	j = data->raycat->rays[in].wl_y;
	while (j < data->raycat->rays[in].wl_y + data->raycat->rays[in].wl_h)
	{
		dis_top = j + (wallstrip_h / 2) - (MAP_H / 2);
		t_sety = dis_top * ((float)SIZE_WIN / wallstrip_h);
		if (t_sety < 0)
			t_sety = 0;
		way_d = *(unsigned int *)way(data, in, t_setx, t_sety);
		my_mlx_pixel_put(data, in, j, way_d);
		j++;
	}
}

char	*way(t_data *data, int nb, int t_setx, int t_sety)
{
	if (data->raycat->rays[nb].hi_type == 3)
		return (data->door1.addr + t_sety * data->door1.line_length \
			+ t_setx * 4);
	if (data->raycat->rays[nb].was_h_v == 0)
	{
		if ((data->pp_x - data->raycat->rays[nb].wallhit_y) < 0)
			return (data->south.addr + t_sety * \
				data->south.line_length + t_setx * 4);
		else
			return (data->north.addr + t_sety * \
				data->north.line_length + t_setx * 4);
	}
	else
	{
		if ((data->pp_y - data->raycat->rays[nb].wallhit_x) < 0)
			return (data->east.addr + t_sety * data->east.line_length \
				+ t_setx * 4);
		else
			return (data->west.addr + t_sety * data->west.line_length \
				+ t_setx * 4);
	}
}
