/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:36:53 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/14 21:46:21 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3D_bonus.h"

void	get_sprite_dimension(t_data *data, int i)
{
	float	pos_x;
	float	ang;

	data->sprites[i].h = (SIZE_WIN / (data->sprites[i].distance * \
	cos(data->sprites[i].angl))) * data->distance_pro;
	data->sprites[i].top_y = (MAP_H / 2) - (data->sprites[i].h / 2);
	data->sprites[i].bottom_y = (MAP_H / 2) + (data->sprites[i].h / 2);
	if (data->sprites[i].top_y < 0)
		data->sprites[i].top_y = 0;
	if (data->sprites[i].bottom_y > MAP_H)
		data->sprites[i].bottom_y = MAP_H;
	ang = atan2f(data->sprites[i].y - data->pp_x, \
	data->sprites[i].x - data->pp_y) - normalize_angle(data->retation);
	pos_x = tan(ang) * data->distance_pro;
	data->sprites[i].left_x = (MAP_W / 2) + pos_x - (data->sprites[i].h / 2);
	data->sprites[i].right_x = data->sprites[i].left_x + data->sprites[i].h;
}

void	util_draw(t_data *data, int in, int i, int j)
{
	int	x;
	int	y;

	x = (i - data->sprites[in].left_x) * \
	((float)SIZE_WIN / data->sprites[in].h);
	y = (j + (data->sprites[in].h / 2) - (MAP_H / 2)) * \
	((float)SIZE_WIN / data->sprites[in].h);
	if (!(data->anim % 3))
		if (*(unsigned int *)(data->sprite2.addr + y * \
		data->sprite2.line_length + x * 4))
			my_mlx_pixel_put(data, i, j, *(unsigned int *)(data->sprite2.addr + \
			y * data->sprite2.line_length + x * 4));
	if ((data->anim % 3))
		if (*(unsigned int *)(data->sprite1.addr + y * \
		data->sprite1.line_length + x * 4))
			my_mlx_pixel_put(data, i, j, *(unsigned int *)(data->sprite1.addr + \
			y * data->sprite1.line_length + x * 4));
}

void	draw_sprites(t_data *data, int in)
{
	int			j;
	int			i;
	static int	img;

	if (!img || img > 15)
		img = 1;
	else
		++img;
	data->anim = img;
	i = (int)data->sprites[in].left_x;
	while (i < (int)data->sprites[in].right_x)
	{
		j = (int)data->sprites[in].top_y;
		while (j < (int)data->sprites[in].bottom_y)
		{
			if (i > 0 && i < MAP_W && j > 0 && j < MAP_H)
				util_draw(data, in, i, j);
			j++;
		}
		i++;
	}
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
		ang = normalize_angle(data->retation) - atan2f(data->sprites[i].y - \
		(int)data->pp_x, data->sprites[i].x - (int)data->pp_y);
		data->sprites[i].visible = 0;
		ang = ft_nomlize_arctan(ang);
		if (ang < (data->raycat->fov_angl / 2) + EPSILON)
		{
			data->sprites[i].angl = ang;
			data->sprites[i].visible = 1;
			ft_distance_s(data, i);
			get_sprite_dimension(data, i);
			draw_sprites(data, i);
		}
		i++;
	}
}
