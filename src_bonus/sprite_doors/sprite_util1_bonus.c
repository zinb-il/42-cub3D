/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_util1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:25:36 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/05 18:17:40 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3D_bonus.h"

void	get_elem_xy(t_sprite *sprite, int i, int j, int index)
{
	sprite[index].x = j * SIZE_WIN;
	sprite[index].y = i * SIZE_WIN;
	sprite[index].visible = 0;
}

void	ft_distance_s(t_data *data, int i)
{
	t_point	point;

	point.x = data->sprites[i].x;
	point.y = data->sprites[i].y;
	data->sprites[i].distance = ft_calc_distance(data, point);
}

float	ft_nomlize_arctan(float ang)
{
	if (ang > PI)
		ang -= (PI * 2);
	if (ang < -PI)
		ang += (PI * 2);
	return (fabs(ang));
}
