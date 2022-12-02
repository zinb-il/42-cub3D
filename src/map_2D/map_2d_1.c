/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:10 by iouazzan          #+#    #+#             */
/*   Updated: 2022/12/02 22:31:29 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	init_data(t_game *game, t_data *data)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	if (!line)
		ft_print_errors(strerror(errno));
	data->gm = game;
	data->line = line;
	data->pp_y = game->p_width + 32;
	data->old_x_m = -2;
	data->pp_x = game->p_height + 32;
	data->retation = game->p_view;
	data->mlx_win = mlx_new_window(data->gm->mlx, game->map_w, game->map_h, \
	"CUB3D");
}

void	setup_map(t_data *data, int i, int j)
{
	if (data->gm->map[i][j] == '1')
		mlx_put_image_to_window
			(data->gm->mlx, data->mlx_win, data->gm->wall, j * SIZE_WIN, \
			i * SIZE_WIN);
	else if (data->gm->map[i][j] == '0')
		mlx_put_image_to_window
			(data->gm->mlx, data->mlx_win, data->gm->space, j * SIZE_WIN, \
			i * SIZE_WIN);
	else
		mlx_put_image_to_window
			(data->gm->mlx, data->mlx_win, data->gm->empty, j * SIZE_WIN, \
			i * SIZE_WIN);
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