/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:10 by iouazzan          #+#    #+#             */
/*   Updated: 2022/12/01 15:30:16 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	init_data(t_game *game, t_data *data)
{
	data->gm = game;
	data->pp_y = game->p_width + 32;
	data->pp_x = game->p_height + 32;
	data->retation = game->p_view;
	data->mlx_win = mlx_new_window(data->gm->mlx, game->map_w, game->map_h, "CUB3D");
}

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	setup_map(t_data *data, int i, int j)
{
	if (data->gm->map[i][j] == '1')
		mlx_put_image_to_window
			(data->gm->mlx, data->mlx_win, data->gm->wall, j * SIZE_WIN, i * SIZE_WIN);
	else if (data->gm->map[i][j] == '0')
		mlx_put_image_to_window
			(data->gm->mlx, data->mlx_win, data->gm->space, j * SIZE_WIN, i * SIZE_WIN);
	else
		mlx_put_image_to_window
			(data->gm->mlx, data->mlx_win, data->gm->empty, j * SIZE_WIN, i * SIZE_WIN);
}

int	pth(int x, int y)
{
	return (sqrt (pow(x, 2) + pow(y, 2)));
}

void	ft_swap(int *n1, int *n2)
{
	int	tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}
