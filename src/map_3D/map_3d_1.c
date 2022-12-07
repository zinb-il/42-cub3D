/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3d_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:18:53 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/07 16:53:08 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	draw_rect(int x, int y, int width, int height, t_data *data)
{
	int	i;
	int	j;

	i = abs(x);
	width += i;
	while (i < width)
	{
		j = abs(y);
		height += j;
		while (j < height)
		{
			mlx_pixel_put(data->gm->mlx, data->mlx_win, i, j, 16777215);
			j++;
		}
		i++;
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
	while (i < data->raycat->num_rays)
	{
		distance = data->raycat->rays[i].distance * \
		cos(data->raycat->rays[i].ray_angl - data->retation);
		wallstrip_h = (SIZE_WIN / distance) * distance_pro;
		draw_rect(data->raycat->wall_strip_width * i, \
		(MAP_H / 2) - (wallstrip_h / 2), \
		data->raycat->wall_strip_width, wallstrip_h, data);
		i++;
	}
}
