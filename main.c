/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:08:36 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/15 22:45:20 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_game	*gm;

	if (ac != 2)
		ft_print_errors(ERROR_PARAMETERS);
	ft_check_extension(av[1]);
	gm = (t_game *)malloc(sizeof(t_game));
	if (!gm)
		ft_print_errors(strerror(errno));
	ft_valid_map_params(av[1], &gm);
	return (0);
}
