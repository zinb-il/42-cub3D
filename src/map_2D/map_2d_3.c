/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:34:28 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/07 15:45:44 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	map_2d(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->gm->map[i])
	{
		j = 0;
		while (data->gm->map[i][j])
		{
			//setup_map(data, i, j);
			j++;
		}
		i++;
	}
	//setup_player(data);
	start_raycast(data);
	//draw_line(data, data->pp_y + cos(data->retation) * 40, \
	//data->pp_x + sin(data->retation) * 40, 0);
}

void	mouve_player(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 0, key_hook, data);
	//mlx_hook(data->mlx_win, 6, 0, mouse_hook, data);
}
