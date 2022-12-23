/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:10 by iouazzan          #+#    #+#             */
/*   Updated: 2022/12/23 17:16:46 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	int_mouve(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		data->keys[i][0] = -1;
		data->keys[i][1] = -1;
		i++;
	}
}

void	init_data(t_game *game, t_data *data)
{
	t_raycast	*raycast;
	t_line		*line;
	t_img		*img;

	line = (t_line *)malloc(sizeof(t_line));
	if (!line)
		ft_print_errors(strerror(errno));
	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		ft_print_errors(strerror(errno));
	int_mouve(data);
	data->gm = game;
	data->line = line;
	data->img = img;
	data->pp_y = game->p_width + (SIZE_WIN / 2);
	data->old_x_m = -2;
	data->pp_x = game->p_height + (SIZE_WIN / 2);
	data->p_p_mini = ((NB_WIN / 2) * S_MIN_WIN) + S_MIN_WIN / 2;
	data->retation = game->p_view;
	data->mlx_win = mlx_new_window(data->gm->mlx, MAP_W, MAP_H, "CUB3D");
	raycast = init_raycat(data);
	data->raycat = raycast;
}

void	setup_map(t_data *data, int i, int j)
{
	if (data->gm->map[i][j] == '1')
	{
		mlx_put_image_to_window
			(data->gm->mlx, data->mlx_win, data->gm->wall, \
			j * SIZE_WIN, i * SIZE_WIN);
	}
	else if (data->gm->map[i][j] == '0')
		mlx_put_image_to_window
			(data->gm->mlx, data->mlx_win, data->gm->space, \
			j * SIZE_WIN, i * SIZE_WIN);
	else
		mlx_put_image_to_window
			(data->gm->mlx, data->mlx_win, data->gm->empty, \
			j * SIZE_WIN, i * SIZE_WIN);
}

int	check_sides_utl(t_data *data, int x, int y)
{
	if (y > (data->pp_y / SIZE_WIN))
	{
		if (data->gm->map[x][y - 1] == '1' && data->gm->map[x + 1][y] == '1')
			return (1);
	}
	else
		if (data->gm->map[x + 1][y] == '1' && data->gm->map[x][y + 1] == '1')
			return (1);
	return (0);
}

int	check_sides(t_data *data, int x, int y)
{
	if (x > (data->pp_x / SIZE_WIN))
	{
		if (y > (data->pp_y / SIZE_WIN))
		{
			if (data->gm->map[x][y - 1] == '1' && data->gm->map[x - 1][y] \
			== '1')
				return (1);
		}
		else
			if (data->gm->map[x - 1][y] == '1' && \
			data->gm->map[x][y + 1] == '1')
				return (1);
	}
	else
	{
		if (check_sides_utl(data, x, y) == 1)
			return (1);
	}
	return (0);
}
