/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:16:47 by iouazzan          #+#    #+#             */
/*   Updated: 2022/11/28 16:31:44 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ret_left(t_data *data)
{
	data->retation += ROTATION_SPEED;
	map_2d(data);
}

void	ret_right(t_data *data)
{
	data->retation -= ROTATION_SPEED;
	map_2d(data);
}

void	walk_left(t_data *data)                                                                                   
{
	float x;
	float y;

	x = data->pp_x + cos(data->retation + 90 * PI / 180) * MOVE_SPEED;
	y = data->pp_y + sin(data->retation + 90 * PI / 180) * MOVE_SPEED;
	if (check_next_step(data, x, y, data->pp_x, data->pp_y) == 0)
	{
		data->pp_y = y;
		data->pp_x = x;
		map_2d(data);
	}
}

void	walk_right(t_data *data)
{
	float x;
	float y;

	x = data->pp_x - cos(data->retation + 90 * PI / 180) * MOVE_SPEED;
	y = data->pp_y - sin(data->retation + 90 * PI / 180) * MOVE_SPEED;
	if (check_next_step(data, x, y, data->pp_x, data->pp_y) == 0)
	{
		data->pp_y = y;
		data->pp_x = x;
		map_2d(data);
	}
}

void	walk_up_down(t_data *data, int nb)
{
	float x;
	float y;

	x = data->pp_x + ((cos(data->retation) * MOVE_SPEED) * nb);
	y = data->pp_y + ((sin(data->retation) * MOVE_SPEED) * nb);
	if (check_next_step(data, x, y, data->pp_x, data->pp_y) == 0)
	{
		data->pp_y = y;
		data->pp_x = x;
	}
	map_2d(data);
}

// void	walk_down(t_data *data)
// {
// 	float x;
// 	float y;

// 	y = data->pp_y + ((sin(data->retation) * MOVE_SPEED) * -1);
// 	x = data->pp_x + ((cos(data->retation) * MOVE_SPEED) * -1);
// 	if (check_next_step(data, x, y, data->pp_x, data->pp_y) == 0)
// 	{
// 		data->pp_y = y;
// 		data->pp_x = x;
// 		map_2d(data);
// 	}
// }