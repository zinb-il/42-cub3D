/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:03:20 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/29 22:07:37 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3D_bonus.h"

int	main(int ac, char **av)
{
	t_game		*gm;
	t_data		*data;
	t_player	*player;

	gm = first_part_cub3d(ac, av);
	player = malloc(sizeof(t_player));
	if (!player)
		ft_print_errors(strerror(errno));
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_print_errors(strerror(errno));
	init_data(gm, data, player);
	map_2d(data);
	mouve_player(data);
	mlx_loop(data->game->mlx);
	system("leaks cub3D");
	return (0);
}
