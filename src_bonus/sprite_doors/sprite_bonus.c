/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:36:53 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/03 21:41:10 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3D_bonus.h"

void	get_elem_xy(t_sprite *sprite, int i, int j, int index)
{
	sprite[index].x = j * SIZE_WIN / 2;
	sprite[index].y = i * SIZE_WIN / 2;
	sprite[index].visible = 0;
}

void	init_sprites(t_data *data)
{
	int	i;
	int	j;
	int	s;

	s = count_elements(data->gm->map, '2');
	if (!s)
		return ;
	data->sprites = (t_sprite *)malloc(s * sizeof(t_sprite));
	data->num_spri = s;
	i = 0;
	s = 0;
	while (data->gm->map[i])
	{
		j = 0;
		while (data->gm->map[i][j])
		{
			if (data->gm->map[i][j] == '2')
			{
				get_elem_xy(data->sprites, i, j, s);
				s++;
			}
			j++;
		}
		i++;
	}
}

void	get_visible_sprites(t_data *data)
{
	int		i;
	float	ang;

	i = 0;
	while (i < data->num_spri)
	{
		ang = data->retation - atan2(data->sprites[i].x - data->pp_y, \
		data->sprites[i].y - data->pp_x);
		if (ang > PI)
			ang -= PI * 2;
		if (ang < -PI)
			ang += PI * 2;
		ang = fabs(ang);
		data->sprites[i].visible = 0;
		if (ang < data->raycat->fov_angl / 2)
			data->sprites[i].visible = 1;
		i++;
	}
}
