/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:49:41 by iouazzan          #+#    #+#             */
/*   Updated: 2022/12/09 18:21:31 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	s_m_win(t_data *data, int k, int l)
{
	int	y;
	int	x;

	y = (data->pp_x / 64) - data->c_y;
	x = (data->pp_y / 64) - data->c_x;
	if ((y < 0 || y > data->gm->nb_row - 1) || (x < 0 || x > data->gm->nb_col))
		draw_win_null(data, k, l);
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
	int	i;
	int	j;

	i = 0;
	data->c_y = 5;
	while (i < NB_WIN)
	{
		j = 0;
		data->c_x = 5;
		while (j < NB_WIN)
		{
			s_m_win(data, i, j);
			j++;
			data->c_x--;
		}
		i++;
		data->c_y--;
	}
	setup_player_min(data);
	draw_line_m(data, data->p_p_mini + cos(data->retation) * 40, \
		data->p_p_mini + sin(data->retation) * 40, 9126929);
}
