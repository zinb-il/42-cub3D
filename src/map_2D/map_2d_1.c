/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:10 by iouazzan          #+#    #+#             */
/*   Updated: 2022/12/07 15:24:29 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	init_data(t_game *game, t_data *data)
{
	t_line		*line;
	t_raycast	*raycast;

	line = (t_line *)malloc(sizeof(t_line));
	if (!line)
		ft_print_errors(strerror(errno));
	data->gm = game;
	data->line = line;
	data->pp_y = game->p_width + (SIZE_WIN / 2);
	data->old_x_m = -2;
	data->pp_x = game->p_height + (SIZE_WIN / 2);
	data->retation = game->p_view;
	data->mlx_win = mlx_new_window(data->gm->mlx, MAP_W, MAP_H, "CUB3D");
	raycast = init_raycat(data);
	data->raycat = raycast;
}

void	setup_map(t_data *data, int i, int j)
{
	int	i1;
	int	j1;

	i1 = (int)(i * SIZE_WIN * SCALE);
	j1 = (int)(j * SIZE_WIN * SCALE);
	if (data->gm->map[i][j] == '1')
	{
		mlx_put_image_to_window
			(data->gm->mlx, data->mlx_win, data->gm->wall, \
			j1, i1);
	}
	else if (data->gm->map[i][j] == '0')
		mlx_put_image_to_window
			(data->gm->mlx, data->mlx_win, data->gm->space, \
			j1, i1);
	else
		mlx_put_image_to_window
			(data->gm->mlx, data->mlx_win, data->gm->empty, \
			j1, i1);
}

int	check_sides(t_data *data, int x, int y)
{
	if (x > (data->pp_x / 64))
	{
		if (y > (data->pp_y / 64))
		{
			if (data->gm->map[x][y - 1] && data->gm->map[x - 1][y])
				return (1);
		}
		else
			if (data->gm->map[x - 1][y] && data->gm->map[x][y + 1])
				return (1);
	}
	else
	{
		if (y > (data->pp_y / 64))
		{
			if (data->gm->map[x][y - 1] && data->gm->map[x + 1][y])
				return (1);
		}
		else
			if (data->gm->map[x + 1][y] && data->gm->map[x][y + 1])
				return (1);
	}
	return (0);
}
