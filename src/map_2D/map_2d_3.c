/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:34:28 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/01 17:02:35 by iouazzan         ###   ########.fr       */
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
	draw_line(data, data->pp_y, data->pp_x, data->pp_y + \
	cos(data->retation) * 40, data->pp_x + sin(data->retation) * 40);
}
