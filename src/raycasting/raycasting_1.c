/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 22:28:36 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/06 16:47:58 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

t_raycast	*init_raycat(t_data *data)
{
	t_raycast	*raycast;

	raycast = (t_raycast *)malloc(sizeof(t_raycast));
	if (!raycast)
		ft_print_errors(strerror(errno));
	raycast->fov_angl = RECTANGLE * (PI / 180);
	raycast->wall_strip_width = floor(data->gm->map_w / 100);
	raycast->num_rays = data->gm->map_w / raycast->wall_strip_width;
	raycast->rays = (t_ray *)malloc(sizeof(t_ray) * raycast->num_rays);
	if (!raycast->rays)
		ft_print_errors(strerror(errno));
	return (raycast);
}

float	normalize_angle(float angle)
{
	angle = remainderf(angle, PI * 2);
	if (angle < 0)
		angle += (2 * PI);
	return (angle);
}

void	cast_allrays(t_data *data)
{
	int		i;
	float	ray_ang;

	i = 0;
	ray_ang = data->retation - (data->raycat->fov_angl / 2);
	while (i < data->raycat->num_rays)
	{
		data->raycat->rays[i].ray_angl = normalize_angle(ray_ang);
		ft_ray_cast(data, data->raycat->rays[i].ray_angl, i);
		ray_ang += data->raycat->fov_angl / data->raycat->num_rays;
		i++;
	}
}

void	start_raycast(t_data *data)
{
	cast_allrays(data);
}
