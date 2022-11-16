/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_valid_map_description.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:46:05 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/17 00:13:36 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_check_colors(char **params, t_game **game)
{
	char	**colors;

	colors = ft_split(params[1], ',');
	if (ft_dstrlen(colors) != 3)
	{
		free_dstr(params);
		free_dstr(colors);
		ft_print_errors(ERROR_INVALID_PCOLORS);
	}
	if (!ft_strcmp(COLOR_F, params[0]))
		(*game)->c_f = colors;
	else
		(*game)->c_c = colors;
}

void	ft_check_walls_files(char **params, t_game **game)
{
	int		w;
	int		y;

	w = 0;
	y = 0;
	if (!ft_strcmp(W_NO, params[0]))
		(*game)->w_no = mlx_xpm_file_to_image((*game)->mlx, params[1], &w, &y);
	else if (!ft_strcmp(W_SO, params[0]))
		(*game)->w_so = mlx_xpm_file_to_image((*game)->mlx, params[1], &w, &y);
	else if (!ft_strcmp(W_WE, params[0]))
		(*game)->w_we = mlx_xpm_file_to_image((*game)->mlx, params[1], &w, &y);
	else if (!ft_strcmp(W_EA, params[0]))
		(*game)->w_ea = mlx_xpm_file_to_image((*game)->mlx, params[1], &w, &y);
}

void	ft_check_walls_files_colors(char *line, t_game **game)
{
	char	**params;

	params = ft_split(line, ' ');
	if (ft_dstrlen(params) != 2)
	{
		free_dstr(params);
		ft_print_errors(ERROR_INVALID_PARAMS);
	}
	if (!ft_strcmp(W_NO, params[0]) || !ft_strcmp(W_SO, params[0]) || \
		!ft_strcmp(W_WE, params[0]) || !ft_strcmp(W_EA, params[0]))
		ft_check_walls_files(params, game);
	else if (!ft_strcmp(COLOR_F, params[0]) || !ft_strcmp(COLOR_C, params[0]))
		ft_check_colors(params, game);
	else
	{
		free_dstr(params);
		ft_print_errors(ERROR_INVALID_PARAMS);
	}
	free_dstr(params);
}

void	ft_check_map(char *line, t_game **game)
{
	int		i;
	int		j;
	char	**map;

	if (!line)
		return ;
	i = (int)ft_dstrlen((*game)->map) + 1;
	map = (char **)malloc(sizeof(char *) * (i + 1));
	j = 0;
	while ((*game)->map && (*game)->map[j])
	{
		map[j] = ft_strdup((*game)->map[j]);
		j++;
	}
	free_dstr((*game)->map);
	map[j] = line;
	map[j + 1] = 0;
	(*game)->map = map;
}
