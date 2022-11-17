/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:08:36 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/18 00:52:03 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_dstr(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		printf("%d:'%s'\n", i, str[i]);
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
	t_game	*gm;

	if (ac != 2)
		ft_print_errors(ERROR_PARAMETERS);
	ft_check_extension(av[1]);
	gm = (t_game *)malloc(sizeof(t_game));
	if (!gm)
		ft_print_errors(strerror(errno));
	ft_init_game(&gm);
	ft_valid_map_params(av[1], &gm);
	ft_print_game(gm);
	system("leaks cub3D");
	return (0);
}
