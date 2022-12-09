/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_mouv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:49:40 by iouazzan          #+#    #+#             */
/*   Updated: 2022/12/08 20:21:41 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	check_next_step(t_data *data, int x, int y)
{
	x /= SIZE_WIN;
	y /= SIZE_WIN;
	if (data->gm->map[x][y] != '1')
	{
		if (x != (((int)data->pp_x) / SIZE_WIN) && y != ((int)data->pp_y / SIZE_WIN))
			return (check_sides(data, x, y));
		return (0);
	}	
	return (1);
}
