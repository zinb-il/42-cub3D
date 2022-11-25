/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:16:47 by iouazzan          #+#    #+#             */
/*   Updated: 2022/11/25 15:16:59 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ret_left(t_data *data)
{
	if (data->retation > 2 * PI)
		data->retation -= 0.05;
	else
		data->retation += 0.05;
	map_2d(data);
}

void	ret_right(t_data *data)
{
	data->retation -= 0.05;
	map_2d(data);
}

void	walk_left(t_data *data)                                                                                   
{
	
	if (check_player(data, 1) == 0)
	{
		data->pp_y += 5;
		map_2d(data);
	}
}

void	walk_up(t_data *data)
{
	if (check_player(data, -2) == 0)
	{
		data->pp_x -= 5;
		map_2d(data);
	}
}

void	walk_right(t_data *data)
{
	if (check_player(data, -1) == 0)
	{
		data->pp_y -= 5;
		map_2d(data);
	}
}

void	walk_down(t_data *data)
{
	if (check_player(data, -5) == 0)
	{
		data->pp_x += 5;
		map_2d(data);
	}
}