/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:52:08 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/28 20:10:52 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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
	ft_print_game(gm);
	ft_valid_map_elem(&gm);
	return (gm);
}
