/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_min_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:20:39 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/03 21:41:18 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3D_bonus.h"

void	draw_line_utl_m(t_data *data, int x2, int y2)
{
	data->line->dx = abs(x2 - data->p_p_mini);
	data->line->dy = abs(y2 - data->p_p_mini);
	if (data->line->dx > data->line->dy)
		data->line->step = data->line->dx;
	else
		data->line->step = data->line->dy;
	data->line->dx /= data->line->step;
	data->line->dy /= data->line->step;
}

void	draw_line_m(t_data *data, int x2, int y2, int color)
{
	float	x;
	float	y;

	x = data->p_p_mini;
	y = data->p_p_mini;
	draw_line_utl_m(data, x2, y2);
	while (data->line->step >= 0)
	{
		mlx_pixel_put(data->gm->mlx, data->mlx_win, x, y, color);
		if (data->p_p_mini < x2)
			x += data->line->dx;
		else
			x -= data->line->dx;
		if (data->p_p_mini < y2)
			y += data->line->dy;
		else
			y -= data->line->dy;
		data->line->step--;
	}
}

void	setup_player_min(t_data *data)
{
	int	x;
	int	y;
	int	width;
	int	length;

	width = 5;
	length = width * 1.5;
	x = width;
	while (x >= -width)
	{
		y = -length;
		while (y <= length)
		{
			if (sqrt(pow(x, 2) + pow(y, 2)) <= width)
				mlx_pixel_put(data->gm->mlx, data->mlx_win,
					y + data->p_p_mini, x + data->p_p_mini, 16101555);
			++y;
		}
		x -= 2;
	}
}
