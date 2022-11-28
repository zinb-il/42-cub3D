/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_valid_map_elemts.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:14:41 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/28 22:25:36 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_check_map_elemnt(char **map)
{
	int	i;
	int	j;

	i = 0;
	if (!map)
		ft_print_errors(ERROR_INVALID_MAP);
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!ft_strchr(MAP_ELMN, map[i][j]))
				ft_print_errors(ERROR_INVALID_MAP_E);
			j++;
		}
		i++;
	}
}

void	ft_last_first_row(char	**map, int r, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		if ((map[0][i] != '1' && map[0][i] != ' ') \
		|| (map[r][i] != '1' && map[r][i] != ' '))
			ft_print_errors(ERROR_INVALID_WALL);
		i++;
	}
}

void	ft_check_row(char	*map, int l)
{
	if ((map[l] != '1' && map[l] != ' ') \
		|| (map[0] != '1' && map[0] != ' '))
		ft_print_errors(ERROR_INVALID_WALL);
}

void	ft_valid_map_wall(char **map)
{
	int	i;
	int	j;
	int	r;
	int	l;

	r = ft_dstrlen(map) - 1;
	l = ft_strlen(map[0]) - 1;
	ft_last_first_row(map, r, l);
	i = 1;
	while (i < r)
	{
		j = 1;
		ft_check_row(map[i], l);
		while (j < l)
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
				if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' || \
				map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
					ft_print_errors(ERROR_INVALID_WALL);
			j++;
		}
		i++;
	}
}

void	ft_valid_map_elem(t_game **game)
{
	ft_check_map_elemnt((*game)->map);
	ft_valid_map_wall((*game)->map);
	return ;
}
