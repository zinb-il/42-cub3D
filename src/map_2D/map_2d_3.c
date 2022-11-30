/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:34:28 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/30 18:54:28 by ziloughm         ###   ########.fr       */
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
	sin(data->retation) * 40, data->pp_x + cos(data->retation) * 40);
}
