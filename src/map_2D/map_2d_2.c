/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:31:58 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/01 14:56:14 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	check_sides(t_data *data, int px, int py, int x, int y)
{
	if (x > px)
	{
		if (y > py)
		{
			if (data->gm->map[x][y - 1] == '1' && data->gm->map[x - 1][y] == '1')
				return (1);
		}
		else
			if (data->gm->map[x - 1][y] == '1' && data->gm->map[x][y + 1] == '1')
				return (1);
	}
	else
	{
		if (y > py)
		{
			if (data->gm->map[x][y - 1] == '1' && data->gm->map[x + 1][y] == '1')
					return (1);
		}
		else
			if (data->gm->map[x + 1][y] == '1' && data->gm->map[x][y + 1] == '1')
				return (1);
	}
	return (0);
}

void	draw_line(t_data *data ,int x1, int y1, int x2, int y2)
{
	float x,y,dx,dy,step;
	int i;


	dx=abs(x2-x1);
	dy=abs(y2-y1);
	if(dx>=dy)
		step=dx;
	else
		step=dy;
	dx=dx/step;
	dy=dy/step;
	x=x1;
	y=y1;
	i=1;
	while(i<=step)
	{
		mlx_pixel_put(data->gm->mlx, data->mlx_win, x, y, 0);
		if (x1 < x2)
			x += dx;
		else
			x -= dx;
		if (y1 < y2)
			y += dy;
		else
			y -= dy;
		i=i+1;
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
		walk_left(data);
	if (keycode == KEY_RIGHT)
		walk_right(data);
	if (keycode == KEY_DOWN)
		walk_down(data);
	if (keycode == KEY_UP)
		walk_up(data);
	return (0);
}

void	mouve_player(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 0, key_hook, data);
}
