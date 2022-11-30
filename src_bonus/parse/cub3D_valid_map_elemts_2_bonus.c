/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_valid_map_elemts_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:35:41 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/29 16:46:39 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_check_nsew10(char **map)
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
