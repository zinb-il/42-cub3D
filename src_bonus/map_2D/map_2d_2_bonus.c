/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d_2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:31:58 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/17 14:02:45 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3D_bonus.h"

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
		mlx_pixel_put(data->gm->mlx, data->mlx_win, \
		x * SCALE, y * SCALE, color);
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

int	key_hookdown(int keycode, t_data *data)
{
	if (keycode == KEY_OPNCL)
		ft_close_open_doors(data);
	if (keycode == KEY_ESC || keycode == KEY_ESC1)
		ft_destroy_window(data);
	if (keycode == KEY_LEFT1)
		data->keys[0][0] = 1;
	if (keycode == KEY_RIGHT1)
		data->keys[0][1] = 1;
	if (keycode == KEY_LEFT)
		data->keys[1][0] = 1;
	if (keycode == KEY_RIGHT)
		data->keys[1][1] = 1;
	if (keycode == KEY_DOWN)
		data->keys[2][0] = 1;
	if (keycode == KEY_UP)
		data->keys[2][1] = 1;
	return (0);
}

int	key_hookup(int keycode, t_data *data)
{
	if (keycode == KEY_LEFT1)
		data->keys[0][0] = -1;
	if (keycode == KEY_RIGHT1)
		data->keys[0][1] = -1;
	if (keycode == KEY_LEFT)
		data->keys[1][0] = -1;
	if (keycode == KEY_RIGHT)
		data->keys[1][1] = -1;
	if (keycode == KEY_DOWN)
		data->keys[2][0] = -1;
	if (keycode == KEY_UP)
		data->keys[2][1] = -1;
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
	return (0);
}
