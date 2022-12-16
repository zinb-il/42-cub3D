/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:16:47 by iouazzan          #+#    #+#             */
/*   Updated: 2022/12/16 17:32:15 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ret_left_right(t_data *data, float speed)
{
	data->retation += speed;
	// map_2d(data);
	// map_3d(data);
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
	// map_2d(data);
	// map_3d(data);
}
