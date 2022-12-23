/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:52:08 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/23 22:27:54 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_get_pview(t_game **gm, char c)
{
	if (c == 'E')
		(*gm)->p_view = 0;
	else if (c == 'W')
		(*gm)->p_view = PI;
	else if (c == 'N')
		(*gm)->p_view = PI * 3 / 2;
	else
		(*gm)->p_view = PI / 2;
}

void	ft_get_info(t_game **gm)
{
	int	i;
	int	j;

	i = 0;
	while ((*gm)->map[i] != 0)
	{
		j = 0;
		while ((*gm)->map[i][j] != 0)
		{
			if (ft_strchr("WENS", (*gm)->map[i][j]))
			{
				(*gm)->p_width = j * S_WIN;
				(*gm)->p_height = i * S_WIN;
				(*gm)->p_x = j;
				(*gm)->p_y = i;
				ft_get_pview(gm, (*gm)->map[i][j]);
			}
			j++;
		}
		i++;
	}
	(*gm)->nb_col = (int) ft_strlen((*gm)->map[0]);
	(*gm)->nb_row = (int) ft_dstrlen((*gm)->map);
	(*gm)->map_w = (*gm)->nb_col * S_WIN;
	(*gm)->map_h = (*gm)->nb_row * S_WIN;
}

t_game	*first_part_cub3d(int ac, char **av)
{
	t_game		*gm;

	if (ac != 2)
		ft_print_errors(ERROR_PARAMETERS);
	ft_check_extension(av[1]);
	gm = (t_game *)malloc(sizeof(t_game));
	if (!gm)
		ft_print_errors(strerror(errno));
	ft_init_game(&gm);
	ft_valid_map_params(av[1], &gm);
	ft_valid_map_elem(&gm);
	ft_get_info(&gm);
	return (gm);
}
