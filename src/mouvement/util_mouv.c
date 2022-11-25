/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_mouv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:49:40 by iouazzan          #+#    #+#             */
/*   Updated: 2022/11/24 10:23:38 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

float	position_pl(t_data *data)
{
	(void)data;
	return 0;
}

int		check_player(t_data *data, int nb) // 0 : x | 1 : y | 2 : x,y
{
	int x;
	int y;

	if (nb == 0)
	{
		x = (data->pp_x + 5) / 64;
		y = data->pp_y / 64;
	}
	else if (nb == 1)
	{
		y = (data->pp_y + 5) / 64;
		x = data->pp_x / 64;
	}
	else if (nb == -1)
	{
		y = (data->pp_y - 5) / 64;
		x = data->pp_x / 64;
	}
	else
	{
		x = (data->pp_x - 5) / 64;
		y = data->pp_y / 64;
	}
	if (data->game->map[x][y] == '1')
		return (1);
	return 0;
}