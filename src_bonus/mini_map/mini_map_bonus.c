/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:49:41 by iouazzan          #+#    #+#             */
/*   Updated: 2022/12/27 20:23:15 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3D_bonus.h"

void	s_m_win(t_data *data, int k, int l)
{
	int	y;
	int	x;

	y = (data->pp_x / 64) - data->c_y;
	x = (data->pp_y / 64) - data->c_x;
	if ((y < 0 || y > data->gm->nb_row - 1) || (x < 0 || x > data->gm->nb_col))
		draw_win(data, k, l, 16113151);
	else
	{
		if (data->gm->map[y][x] == '0' || ft_isalpha(data->gm->map[y][x]))
			draw_win(data, k, l, 16777177);
		else if (data->gm->map[y][x] == '2')
			draw_win(data, k, l, 16101555);
		else if (data->gm->map[y][x] == '3')
			draw_win(data, k, l, 9126929);
		else
			draw_win(data, k, l, 14742783);
	}
}

int	check_des(t_data *data, int x, int y)
{
	int	step;
	int	dx;
	int	dy;

	dx = abs(data->p_p_mini - x);
	dy = abs(data->p_p_mini) - y;
	step = sqrt(dx * dx + dy * dy);
	if (step > 130)
		return (1);
	return (0);
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
			if (check_des(data, x, y) == 0)
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
