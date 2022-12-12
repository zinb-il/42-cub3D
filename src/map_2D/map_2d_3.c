/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:34:28 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/12 00:08:44 by iouazzan         ###   ########.fr       */
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
			setup_map(data, i, j);
			j++;
		}
		i++;
	}
	setup_player(data);
	start_raycast(data);
	draw_line(data, data->pp_y + cos(data->retation) * 40, \
	data->pp_x + sin(data->retation) * 40, 9126929);
	mini_map(data);
}

void	mouve_player(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 0, key_hook, data);
	// mlx_hook(data->mlx_win, 6, 0, mouse_hook, data);
}
