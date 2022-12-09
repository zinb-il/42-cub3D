/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:49:41 by iouazzan          #+#    #+#             */
/*   Updated: 2022/12/09 04:35:09 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	s_m_map(t_data *data, int i, int j, int k, int l)
{
	int	y;
	int	x;

	y = (data->pp_x / 64) - j;
	x = (data->pp_y / 64) - i;
	if ((y < 0 || y > data->gm->nb_row) || (x < 0 || x > data->gm->nb_col))
	{
		printf("px %f, py %f\n", data->pp_x, data->pp_y);
		printf("py %d, px %d\n", y, x);
		printf("i %d, j %d\n", i, j);
		printf("k %d, l %d\n", k, l);
		printf("SGV\n");
		draw_win_null(data, k, l);
		  
	}
	else
	{
		if (data->gm->map[y][x] == '1')
			draw_win(data, k, l, 16113151);
		else if (data->gm->map[y][x] == '0')
			draw_win(data, k, l, 16777177);
		else
			draw_win(data, k, l, 14742783);
	}
}

void	draw_line_utl_m(t_data *data, int x2, int y2)
{
	data->line->dx = abs(x2 - 176);
	data->line->dy = abs(y2 - 176);
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

	x = 176;
	y = 176;
	draw_line_utl_m(data, x2, y2);
	while (data->line->step >= 0)
	{
		mlx_pixel_put(data->gm->mlx, data->mlx_win, x, y, color);
		if (176 < x2)
			x += data->line->dx;
		else
			x -= data->line->dx;
		if (176 < y2)
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
	length = width * 1.5 ;
	x = width;
	while (x >= -width)
	{
		y = -length;
		while (y <= length)
		{
			if (sqrt(pow(x, 2) + pow(y, 2)) <= width)
				mlx_pixel_put(data->gm->mlx, data->mlx_win,
					y + 176, x + 176, 16101555);
			++y;
		}
		x -= 2;
	}
}

void	draw_win_null(t_data *data, int i, int j)
{
	int	x;
	int	y;

	y = (i * S_MIN_WIN);
	while (y < ((i * S_MIN_WIN) + S_MIN_WIN))
	{
		x = (j * S_MIN_WIN);
		while (x < ((j * S_MIN_WIN) + S_MIN_WIN))
		{
			if ((x % 2) == 0)
				mlx_pixel_put(data->gm->mlx, data->mlx_win, \
					x, y, 15655113);
			else
				mlx_pixel_put(data->gm->mlx, data->mlx_win, \
					x, y, 8759482);
			x++;
		}
		y++;
	}
}

void	draw_win(t_data *data, int i, int j, int clr)
{
	int	x;
	int	y;

	y = (i * S_MIN_WIN);
	while (y < ((i * S_MIN_WIN) + S_MIN_WIN))
	{
		x = (j * S_MIN_WIN);
		while (x < ((j * S_MIN_WIN) + S_MIN_WIN))
		{
			mlx_pixel_put(data->gm->mlx, data->mlx_win, \
				x, y, clr);
			x++;
		}
		y++;
	}
}

void	mini_map(t_data *data)
{
	int	x;
	int	y;
	int	i;
	int j;
	
	y = 5;
	i = 0; 
	while (i < NB_WIN)
	{
		j = 0;
		x = 5;
		while (j < NB_WIN)
		{
			s_m_map(data, x, y, i, j);
			x--;
			j++;
		}
		y--;
		i++;
	}
	setup_player_min(data);
	draw_line_m(data, 176 + cos(data->retation) * 40, \
		176 + sin(data->retation) * 40, 9126929);
}