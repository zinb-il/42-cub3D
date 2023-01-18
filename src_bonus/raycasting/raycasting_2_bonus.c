/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:39:45 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/18 18:03:36 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3D_bonus.h"

t_point	ft_distance_coordinat(t_data *data, t_info in, int i, int true_if_hor)
{
	t_point	point;

	point.x = data->pp_y;
	point.y = data->pp_x;
	while (!ft_end_win(data, in.xhit, in.yhit))
	{
		in.xhit += in.xdecre;
		in.yhit += in.ydecre;
		data->raycat->rays[i].hi_type = ft_wall_grid(data, in, i);
		if (data->raycat->rays[i].hi_type && data->raycat->rays[i].hi_type != 4)
			return (ft_distance_coordinat2(data, in, i, true_if_hor));
		in.xhit -= in.xdecre;
		in.yhit -= in.ydecre;
		in.xhit += in.xstep;
		in.yhit += in.ystep;
	}
	return (point);
}

void	ft_short_distance(t_point point_h, t_point point_v, t_data *data, int i)
{
	float	dis_h;
	float	dis_v;

	dis_h = ft_calc_distance(data, point_h);
	if (!data->raycat->rays[i].was_h)
		dis_h = INT_MAX;
	dis_v = ft_calc_distance(data, point_v);
	if (!data->raycat->rays[i].was_v)
		dis_v = INT_MAX;
	data->raycat->rays[i].wallhit_x = point_v.x;
	data->raycat->rays[i].wallhit_y = point_v.y;
	data->raycat->rays[i].distance = dis_v;
	data->raycat->rays[i].was_h_v = 1;
	data->raycat->rays[i].hi_type = point_v.hit;
	if (dis_h < dis_v)
	{
		data->raycat->rays[i].wallhit_x = point_h.x;
		data->raycat->rays[i].wallhit_y = point_h.y;
		data->raycat->rays[i].distance = dis_h;
		data->raycat->rays[i].was_h_v = 0;
		data->raycat->rays[i].hi_type = point_h.hit;
	}
}

t_point	ft_horizontal_intersection(t_data *data, float ray_angl, int i)
{
	t_info	in;

	in.yintercept = floor(data->pp_x / SIZE_WIN) * SIZE_WIN;
	in.yintercept += ft_ray_facing(ray_angl, "up_do");
	in.xintercept = data->pp_y + (in.yintercept - data->pp_x) / tan(ray_angl);
	in.ystep = SIZE_WIN;
	if (!ft_ray_facing(ray_angl, "up_do"))
		in.ystep *= -1;
	in.xstep = SIZE_WIN / tan(ray_angl);
	if (!ft_ray_facing(ray_angl, "le_ri") && in.xstep > 0)
		in.xstep *= -1;
	if (ft_ray_facing(ray_angl, "le_ri") && in.xstep < 0)
		in.xstep *= -1;
	in.xhit = in.xintercept;
	in.yhit = in.yintercept;
	in.ydecre = 0;
	in.xdecre = 0;
	if (!ft_ray_facing(ray_angl, "up_do"))
		in.ydecre--;
	return (ft_distance_coordinat(data, in, i, 1));
}

t_point	ft_vertical_intersection(t_data *data, float ray_angl, int i)
{
	t_info	in;

	in.xintercept = floor(data->pp_y / SIZE_WIN) * SIZE_WIN;
	if (ft_ray_facing(ray_angl, "le_ri"))
		in.xintercept += SIZE_WIN;
	in.yintercept = data->pp_x + (in.xintercept - data->pp_y) * tan(ray_angl);
	in.xstep = SIZE_WIN;
	if (!ft_ray_facing(ray_angl, "le_ri"))
		in.xstep *= -1;
	in.ystep = SIZE_WIN * tan(ray_angl);
	if (!ft_ray_facing(ray_angl, "up_do") && in.ystep > 0)
		in.ystep *= -1;
	if (ft_ray_facing(ray_angl, "up_do") && in.ystep < 0)
		in.ystep *= -1;
	in.xhit = in.xintercept;
	in.yhit = in.yintercept;
	in.ydecre = 0;
	in.xdecre = 0;
	if (!ft_ray_facing(ray_angl, "le_ri"))
		in.xdecre--;
	return (ft_distance_coordinat(data, in, i, 0));
}

void	ft_ray_cast(t_data *data, float ray_angl, int i)
{
	data->raycat->rays[i].was_h = 0;
	data->raycat->rays[i].was_v = 0;
	data->raycat->rays[i].door[0] = -1;
	data->raycat->rays[i].door[1] = -1;
	data->raycat->rays[i].hi_type = -1;
	data->raycat->rays[i].hit_door = 0;
	ft_short_distance(ft_horizontal_intersection(data, ray_angl, i), \
	ft_vertical_intersection(data, ray_angl, i), data, i);
}
