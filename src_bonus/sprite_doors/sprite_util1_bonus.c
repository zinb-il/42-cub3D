/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_util1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:25:36 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/15 21:42:14 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3D_bonus.h"

void	get_elem_xy(t_sprite *sprite, int i, int j, int index)
{
	sprite[index].x = j * SIZE_WIN;
	sprite[index].y = i * SIZE_WIN;
	sprite[index].visible = 0;
	sprite[index].angl = -1;
	sprite[index].left_x = -1;
	sprite[index].right_x = -1;
	sprite[index].h = -1;
	sprite[index].top_y = -1;
	sprite[index].bottom_y = -1;
	sprite[index].distance = -1;
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

void	sort_sprites(t_data *data)
{
	int			i;
	t_sprite	c;
	int			j;

	i = 0;
	while (i < data->num_spri)
	{
		j = 0;
		while (j < (data->num_spri - i - 1))
		{
			if (data->sprites[j].distance < data->sprites[j + 1].distance)
			{
				c = data->sprites[j];
				data->sprites[j] = data->sprites[j + 1];
				data->sprites[j + 1] = c;
			}
			++j;
		}
		++i;
	}
}

void	render_sprites(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_spri)
	{
		if (data->sprites[i].visible)
			draw_sprites(data, i);
		i++;
	}
}
