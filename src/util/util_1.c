/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:38:41 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/19 11:20:44 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	print_ray(t_ray ray)
{
	printf("distance %f hitX %f hitY %f angl %f\n", ray.distance, ray.wallhit_x, \
	ray.wallhit_y, ray.ray_angl);
}

void	print_rays(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->raycat->num_rays)
	{
		print_ray(data->raycat->rays[i]);
		i++;
	}
}
