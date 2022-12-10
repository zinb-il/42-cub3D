/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:16:47 by iouazzan          #+#    #+#             */
/*   Updated: 2022/12/10 04:32:27 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ret_left(t_data *data)
{
	data->retation -= ROTATION_SPEED;
	map_2d(data);
}

void	ret_right(t_data *data)
{
	data->retation += ROTATION_SPEED;
	map_2d(data);
}

void	mouve(t_data *data, int way, int ang)
{
	float	x;
	float	y;

	
	if (ang == 1)
	{
		x = data->pp_x + (sin(data->retation + 90 * PI / 180) * MOVE_SPEED) \
		* way;
		y = data->pp_y + (cos(data->retation + 90 * PI / 180) * MOVE_SPEED) \
		* way;
	}
	else
	{
		x = data->pp_x + ((sin(data->retation) * MOVE_SPEED) * way);
		y = data->pp_y + ((cos(data->retation) * MOVE_SPEED) * way);
	}
	collisions_wall(data, x, y);
	map_2d(data);
	// map_3d(data);
}
