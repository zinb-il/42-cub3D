/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:31:58 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/03 01:17:58 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	draw_line_utl(t_data *data, int x2, int y2)
{
	data->line->dx = abs(x2 - (int)data->pp_y);
	data->line->dy = abs(y2 - (int)data->pp_x);
	if (data->line->dx > data->line->dy)
		data->line->step = data->line->dx;
	else
		data->line->step = data->line->dy;
	data->line->dx /= data->line->step;
	data->line->dy /= data->line->step;
}

void	draw_line(t_data *data, int x2, int y2, int color)
{
	float	x;
	float	y;

	x = data->pp_y;
	y = data->pp_x;
	draw_line_utl(data, x2, y2);
	while (data->line->step >= 0)
	{
		mlx_pixel_put(data->gm->mlx, data->mlx_win, x, y, color);
		if (data->pp_y < x2)
			x += data->line->dx;
		else
			x -= data->line->dx;
		if (data->pp_x < y2)
			y += data->line->dy;
		else
			y -= data->line->dy;
		data->line->step--;
	}
}

void	setup_player(t_data *data)
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
					(y + data->pp_y),
					(x + data->pp_x),
					0x09FF60);
			++y;
		}
		x -= 2;
	}
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->gm->mlx, data->mlx_win);
		exit (0);
	}
	if (keycode == KEY_LEFT1)
		ret_left(data);
	if (keycode == KEY_RIGHT1)
		ret_right(data);
	if (keycode == KEY_LEFT)
		mouve(data, -1, 1);
	if (keycode == KEY_RIGHT)
		mouve(data, 1, 1);
	if (keycode == KEY_DOWN)
		mouve(data, -1, 0);
	if (keycode == KEY_UP)
		mouve(data, 1, 0);
	return (0);
}

int	mouse_hook(int x, int y, t_data *data)
{
	(void)y;
	if (data->old_x_m == -2)
		data->old_x_m = x;
	if (x > data->old_x_m)
	{
		data->old_x_m = x;
		data->retation += 0.05;
	}
	else
	{
		data->old_x_m = x;
		data->retation -= 0.05;
	}
	map_2d(data);
	return (0);
}
