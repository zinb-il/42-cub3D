/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:39:45 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/03 23:41:55 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

t_point	ft_distance_coordinat(t_data *data, float ray_ang, t_info in)
{
	float	x_grid;
	float	y_grid;
	t_point	point;

	while (!ft_end_win(data, in))
	{
		/* code */
	}
}

t_point	ft_horizontal_intersection(t_data *data, float ray_angl)
{
	t_info	in;

	in.yintercept = floor(data->pp_x / SIZE_WIN) * SIZE_WIN;
	in.yintercept += ft_ray_facing(ray_angl, "up_do");
	in.xintercept = data->pp_y + (in.yintercept - data->pp_y) / tan(ray_angl);
	in.ystep = SIZE_WIN;
	if (!ft_ray_facing(ray_angl, "up_do"))
		in.ystep *= -1;
	in.xstep = in.ystep / tan(ray_angl);
	if (ft_ray_facing(ray_angl, "le_ri") && in.xstep > 0)
		in.xstep *= -1;
	if (!ft_ray_facing(ray_angl, "le_ri") && in.xstep < 0)
		in.xstep *= -1;
	in.xhit = in.xintercept;
	in.yhit = in.yintercept;
	if (!ft_ray_facing(ray_angl, "up_do"))
		in.yhit--;
	return (ft_distance_coordinat(data, ray_angl, in));
}

void	ft_ray_cast(t_data *data, int i)
{
	draw_line(data, data->pp_y + cos(data->raycat->rays[i].ray_angl) * 40, \
		data->pp_x + sin(data->raycat->rays[i].ray_angl) * 40, 16335418);
}
