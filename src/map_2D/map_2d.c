/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:10 by iouazzan          #+#    #+#             */
/*   Updated: 2022/11/28 20:12:53 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	init_data(t_game *game, t_data *data, t_player *player)
{
	data->game = game;
	data->player = player;
	data->player_x = -2;
	data->player_y = -2;
	data->pp_y = (((NB_COL) / 2) * 64) + 32;
	data->pp_x = (((NB_LINE) / 2 + 5) * 64) + 32;
	data->player->width = NB_COL * 64;
	data->player->heght = NB_LINE * 64;
	// data->retation = (RECTANGLE * (PI / 180) / 2);
	data->retation = PI / 2;
	data->mlx_win = mlx_new_window(data->game->mlx, WIDTH_MAP, HEIGHT_MAP, "test");
}

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	setup_map(t_data *data, int i, int j)
{
	if (data->game->map[i][j] == '1')
		mlx_put_image_to_window
			(data->game->mlx, data->mlx_win, data->game->w_no, j * SIZE_WIN, i * SIZE_WIN);
	else if (data->game->map[i][j] == '0')
		mlx_put_image_to_window
			(data->game->mlx, data->mlx_win, data->game->w_so, j * SIZE_WIN, i * SIZE_WIN);
}

int pth (int x,int y)
{ 
    return sqrt (pow(x,2)+pow(y,2)); 
}


void	ft_swap(int *n1, int *n2)
{
	int tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

int	check_sides(t_data *data, int px, int py, int x, int y)
{
	if (x > px)
	{
		if (y > py)
		{
			if (data->game->map[x][y - 1] == '1' && data->game->map[x - 1][y] == '1')
				return (1);
		}
		else
			if (data->game->map[x - 1][y] == '1' && data->game->map[x][y + 1] == '1')
				return (1);
	}
	else
	{
		if (y > py)
		{
			if (data->game->map[x][y - 1] == '1' && data->game->map[x + 1][y] == '1')
					return (1);
		}
		else
			if (data->game->map[x + 1][y] == '1' && data->game->map[x][y + 1] == '1')
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
		mlx_pixel_put(data->game->mlx, data->mlx_win, x, y, 0);
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
	int x;
	int y;
 
    int width = 5; 
    int length = width * 1.5;
	x = width;
    while (x >= -width)
	{
		y = -length;
        while (y <= length)
		{
            if (sqrt(pow(x,2)+pow(y,2)) <= width)
				mlx_pixel_put(data->game->mlx, data->mlx_win,
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
		mlx_destroy_window(data->game->mlx, data->mlx_win);
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

void	map_2d(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->game->map[i])
	{
		j = 0;
		while (data->game->map[i][j])
		{
			setup_map(data, i , j);
			j++;
		}
		i++;
	}
	setup_player(data);
	draw_line(data, data->pp_y, data->pp_x, data->pp_y + sin(data->retation) * 40,  data->pp_x + cos(data->retation) * 40);
}


	// pseudo code with python

	
	// if x > px:
	// 	if y > py:
	// 		if t[x][y - 1] == '1' and t[x - 1][y] == '1':
	// 			return (1)
	// 	else:
	// 		if t[x - 1][y] == '1' and t[x][y + 1] == '1':
	// 			return (1)
	// else:
	// 	if y > py:
	// 		if t[x][y - 1] == '1' and t[x + 1][y] == '1':
	// 			return (1)
	// 	else:
	// 		if t[x + 1][y] == '1' and t[x][y + 1] == '1':
	// 			return (1)
	// return (0)
