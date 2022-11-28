/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:08:36 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/27 21:20:38 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	print_dstr(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		printf("'%s'\n", str[i]);
		i++;
	}
}

void	ft_print_game(t_game *gm)
{
	printf("/******************/\n");
	printf("NO %s SO %s\n", gm->w_no, gm->w_so);
	printf("WE %s EA %s\n", gm->w_we, gm->w_ea);
	printf("C %d %d %d\n", gm->c_c[0], gm->c_c[1], gm->c_c[2]);
	printf("F %d %d %d\n", gm->c_f[0], gm->c_f[1], gm->c_f[2]);
	print_dstr(gm->map);
	printf("/******************/\n");
}

int	main(int ac, char **av)
{
	t_game		*gm;
	t_data		*data;
	t_player	*player;

	if (ac != 2)
		ft_print_errors(ERROR_PARAMETERS);
	ft_check_extension(av[1]);
	gm = (t_game *)malloc(sizeof(t_game));
	if (!gm)
		ft_print_errors(strerror(errno));
	ft_init_game(&gm);
	ft_valid_map_params(av[1], &gm);
	ft_print_game(gm);
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
