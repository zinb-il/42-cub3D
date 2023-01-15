/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_mouv_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:49:40 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/15 21:19:06 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3D_bonus.h"

void	collisions_wall(t_data *data, int x, int y)
{
	if (data->gm->map[x / 64][y / 64] != '1')
	{
		if (x / 64 != (((int)data->pp_x) / SIZE_WIN) \
			&& y / 64 != ((int)data->pp_y / SIZE_WIN))
		{
			if (check_sides(data, x / 64, y / 64) == 1)
				return ;
		}
		data->pp_x = data->n_p_x;
		data->pp_y = data->n_p_y;
	}
	else
	{
		if ((int)data->pp_x != x && (int)data->pp_y != y)
		{
			if (data->gm->map[x / 64][(int)data->pp_y / 64] != '1')
				data->pp_x = data->n_p_x;
			else if (data->gm->map[(int)data->pp_x / 64][y / 64] != '1')
				data->pp_y = data->n_p_y;
		}
	}
}
