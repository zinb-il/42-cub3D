/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:16:47 by iouazzan          #+#    #+#             */
/*   Updated: 2022/12/27 18:02:52 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3D_bonus.h"

void	mouve(t_data *data, int way, int ang)
{
	float	x;
	float	y;

	if (ang == 1)
	{
		x = data->pp_x + (sin(data->retation + 90 * PI / 180) \
		* (MOVE_SPEED + DIS)) * way;
		data->n_p_x = data->pp_x + (sin(data->retation + 90 * PI / 180) \
		* MOVE_SPEED) * way;
		y = data->pp_y + (cos(data->retation + 90 * PI / 180) \
		* (MOVE_SPEED + DIS)) * way;
		data->n_p_y = data->pp_y + (cos(data->retation + 90 * PI / 180) \
		* MOVE_SPEED) * way;
	}
	else
	{
		x = data->pp_x + ((sin(data->retation) * (MOVE_SPEED + DIS)) * way);
		data->n_p_x = data->pp_x + ((sin(data->retation) * MOVE_SPEED) * way);
		y = data->pp_y + ((cos(data->retation) * (MOVE_SPEED + DIS)) * way);
		data->n_p_y = data->pp_y + ((cos(data->retation) * MOVE_SPEED) * way);
	}
	collisions_wall(data, x, y);
}
