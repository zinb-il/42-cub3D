/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_mouv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:49:40 by iouazzan          #+#    #+#             */
/*   Updated: 2022/12/02 17:47:48 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	check_next_step(t_data *data, int x, int y)
{
	x /= 64;
	y /= 64;
	if (data->gm->map[x][y] != '1')
	{
		if (x != (data->pp_x / 64) && y != (data->pp_y / 64))
			return (check_sides(data, x, y));
		return (0);
	}	
	return (1);
}
