/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:58:53 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/04 14:12:18 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_check_extension(char *s)
{
	char	*file_name;

	file_name = ft_strrchr(s, '.');
	if (!file_name || ft_strcmp(file_name, EXTEN_MAP))
		ft_print_errors(ERROR_EXTENTION);
}

void	ft_print_errors(char *msg)
{
	if (msg)
		printf("ERROR\n: %s\n", msg);
	exit (EXIT_FAILURE);
}

void	ft_init_game(t_game **game)
{
	(*game)->map = (void *)0;
	(*game)->mlx = mlx_init();
	(*game)->c_c = -1;
	(*game)->c_f = -1;
	(*game)->col_c = -1;
	(*game)->col_f = -1;
}

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
	printf("C %lu %lx\n", gm->c_c, gm->c_c);
	printf("F %lu %lx\n", gm->c_f, gm->c_f);
	printf("Player x %d player y %d\n", gm->p_x, gm->p_y);
	printf("Player xw %d player yw %d\n", gm->p_width, gm->p_height);
	printf("Player view %f deg %f \n", gm->p_view, gm->p_view * 180 / PI);
	printf("map width %d  map height %d\n", gm->map_w, gm->map_h);
	printf("map cols %d  map rows %d\n", gm->nb_col, gm->nb_row);
	print_dstr(gm->map);
	printf("/******************/\n");
}
