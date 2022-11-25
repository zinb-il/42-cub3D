/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_valid_map_description.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:46:05 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/25 17:15:27 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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
	size_t	i;
	int		j;
	char	**map;

	if (!line)
		return ;
	map = (char **)malloc(sizeof(char *) * (ft_dstrlen((*game)->map) + 2));
	j = 0;
	if (!(*game)->map || \
	((*game)->map && ft_strlen((*game)->map[0]) < ft_strlen(line)))
		i = ft_strlen(line) + 1;
	else
		i = ft_strlen((*game)->map[0]) + 1;
	while ((*game)->map && (*game)->map[j])
	{
		map[j] = (char *)malloc(sizeof(char) * i);
		ft_strlcpy(map[j], (*game)->map[j], i);
		j++;
	}
	map[j] = (char *)malloc(sizeof(char) * i);
	ft_strlcpy(map[j], line, i);
	free_dstr((*game)->map);
	map[j + 1] = 0;
	(*game)->map = map;
}
