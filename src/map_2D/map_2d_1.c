/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:10 by iouazzan          #+#    #+#             */
/*   Updated: 2022/11/30 19:57:13 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	init_data(t_game *gm, t_data *data, t_player *player)
{
	data->gm = gm;
	data->pl = player;
	data->player_x = -2;
	data->player_y = -2;
	data->pp_y = (((gm->nb_col) / 2) * 64) + 32;
	data->pp_x = (((gm->nb_row) / 2 + 5) * 64) + 32;
	data->pl->width = gm->nb_col * 64;
	data->pl->heght = gm->nb_row * 64;
	// data->retation = (FOV * (PI / 180) / 2);
	data->retation = PI / 2;
	data->mlx_win = mlx_new_window(gm->mlx, gm->map_w, gm->map_h, "CUB3D");
}

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	setup_map(t_data *data, int i, int j)
{
	if (data->gm->map[i][j] == '1')
		mlx_put_image_to_window(data->gm->mlx, data->mlx_win, \
		data->gm->wall, j * SIZE_WIN, i * SIZE_WIN);
	else if (data->gm->map[i][j] == ' ')
		mlx_put_image_to_window(data->gm->mlx, data->mlx_win, \
		data->gm->empty, j * SIZE_WIN, i * SIZE_WIN);
	else
		mlx_put_image_to_window(data->gm->mlx, data->mlx_win, \
		data->gm->space, j * SIZE_WIN, i * SIZE_WIN);
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
