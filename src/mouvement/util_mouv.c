/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_mouv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:49:40 by iouazzan          #+#    #+#             */
/*   Updated: 2022/11/26 00:56:40 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

float	position_pl(t_data *data)
{
	(void)data;
	return 0;
}

int		check_player(t_data *data, int x, int y) // 0 : x | 1 : y | 2 : x,y
{
	x /= 64;
	y /= 64;
	if (data->game->map[x][y] == '1')
		return (1);
	return 0;
}
