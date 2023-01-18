/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_open_close.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:03:44 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/18 21:41:48 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3D_bonus.h"

void	ft_switch_char_map(t_data *data, int i)
{
	/*if (i > 0 && \
	data->raycat->rays[i].door[0] == data->raycat->rays[i - 1].door[0])
		return ;
	if (i > 0 && \
	data->raycat->rays[i].door[1] == data->raycat->rays[i - 1].door[1])
		return ;
	if (data->gm->map[data->raycat->rays[i].door[0]] \
		[data->raycat->rays[i].door[1]] == '3')
		data->gm->map[data->raycat\
		->rays[i].door[0]] \
		[data->raycat->rays[i].door[1]] = '4';
	else if (data->gm->map[data->raycat->rays[i].door[0]] \
		[data->raycat->rays[i].door[1]] == '4')
		data->gm->map[data->raycat->rays[i].door[0]] \
		[data->raycat->rays[i].door[1]] = '3';*/
	int	x;
	int	j;

	x = floor(data->raycat->rays[i].wallhit_x / SIZE_WIN);
	j = floor(data->raycat->rays[i].wallhit_y / SIZE_WIN);
	/*if (i > 0 && \
	data->raycat->rays[i].hi_type == data->raycat->rays[i - 1].hi_type)
		return ;*/
	if (data->gm->map[j][x] == '3')
		data->gm->map[j][x] = '4';
	else if (data->gm->map[j][x] == '4')
		data->gm->map[j][x] = '3';
}

void	ft_close_open_doors(t_data *data)
{
	int		i;

	print_dstr(data->gm->map);
	printf("*********************************\n");
	i = 0;
	while (i < data->raycat->num_rays)
	{
		/*if (data->raycat->rays[i].door[0] > -1 \
		&& data->raycat->rays[i].door[1] > -1)*/
		printf("hittype %d\n", data->raycat->rays[i].hi_type);
		if (data->raycat->rays[i].hi_type == 3 || \
		data->raycat->rays[i].hi_type == 4) 
			ft_switch_char_map(data, i);
		i++;
	}
	mouve_player(data);
	start_raycast(data);
	map_3d(data);
	print_dstr(data->gm->map);
}
