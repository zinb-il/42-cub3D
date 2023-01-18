/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_open_close.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:03:44 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/18 17:53:29 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3D_bonus.h"

void	ft_switch_char_map(t_data *data, int i)
{
	if (i > 0 && \
	data->raycat->rays[i].door[0] == data->raycat->rays[i - 1].door[0])
		return ;
	if (i > 0 && \
	data->raycat->rays[i].door[1] == data->raycat->rays[i - 1].door[1])
		return ;
	if (data->gm->map[data->raycat->rays[i].door[0]] \
		[data->raycat->rays[i].door[1]] == '3')
		data->gm->map[data->raycat->rays[i].door[0]] \
		[data->raycat->rays[i].door[1]] = '4';
	else if (data->gm->map[data->raycat->rays[i].door[0]] \
		[data->raycat->rays[i].door[1]] == '4')
		data->gm->map[data->raycat->rays[i].door[0]] \
		[data->raycat->rays[i].door[1]] = '3';
}

void	ft_close_open_doors(t_data *data)
{
	int		i;

	ft_print_game(data->gm);
	i = 0;
	while (i < data->raycat->num_rays)
	{
		if (data->raycat->rays[i].door[0] > -1 \
		&& data->raycat->rays[i].door[1] > -1)
			ft_switch_char_map(data, i);
		i++;
	}
	mouve_player(data);
	start_raycast(data);
	map_3d(data);
	ft_print_game(data->gm);
}
