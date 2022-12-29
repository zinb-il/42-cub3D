/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_valid_map_elemts_2_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:35:41 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/27 19:21:29 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3D_bonus.h"

void	ft_check_nsew0123(char **map)
{
	int	i;
	int	p;

	p = 0;
	i = 0;
	while (map[i] != 0)
	{
		p += (int)ft_count_char(map[i], 'W');
		p += (int)ft_count_char(map[i], 'E');
		p += (int)ft_count_char(map[i], 'N');
		p += (int)ft_count_char(map[i], 'S');
		i++;
	}
	if (p != 1)
		ft_print_errors(ERROR_PLAYER_MAP);
}

void	check_doors(char **map, int i, int j)
{
	int	lr;
	int	ud;

	lr = map[i - 1][j] + map[i + 1][j] - 96;
	ud = map[i][j - 1] + map[i][j + 1] - 96;
	printf("%d %d\n", lr, ud);
	if (lr != 2 && ud != 2)
		ft_print_errors(ERROR_DOORS);
}

void	ft_valid_map_door(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '3')
				check_doors(map, i, j);
			j++;
		}
		i++;
	}
}
