/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_mouv_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:49:40 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/18 19:20:03 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3D_bonus.h"

void	util_collisions(t_data *data, int x, int y)
{
	if (data->gm->map[x / 64][(int)data->pp_y / 64] != '1' && \
		data->gm->map[x / 64][(int)data->pp_y / 64] != '2' && \
		data->gm->map[x / 64][(int)data->pp_y / 64] != '3')
			data->pp_x = data->n_p_x;
	else if (data->gm->map[(int)data->pp_x / 64][y / 64] != '1' && \
			data->gm->map[(int)data->pp_x / 64][y / 64] != '2' && \
			data->gm->map[(int)data->pp_x / 64][y / 64] != '3')
				data->pp_y = data->n_p_y;
}

void	collisions_wall(t_data *data, int x, int y)
{
	if (data->gm->map[x / 64][y / 64] != '1' && \
		data->gm->map[x / 64][y / 64] != '2' && \
		data->gm->map[x / 64][y / 64] != '3')
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
			util_collisions(data, x, y);
	}
}
