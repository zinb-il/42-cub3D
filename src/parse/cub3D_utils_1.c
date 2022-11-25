/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:58:53 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/25 17:15:21 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_check_extension(char *s)
{
	char	*file_name;

	file_name = ft_strrchr(s, '.');
	if (!file_name || ft_strcmp(file_name, EXTEN_MAP))
	{
		printf("%s", ERROR_EXTENTION);
		exit(EXIT_FAILURE);
	}
}

void	ft_print_errors(char *msg)
{
	if (msg)
		printf("ERROR\n: %s\n", msg);
	system("leaks cub3D");
	exit (EXIT_FAILURE);
}

void	ft_init_game(t_game **game)
{
	(*game)->map = (void *)0;
	(*game)->mlx = mlx_init();
	(*game)->c_c[0] = -1;
	(*game)->c_f[0] = -1;
}
