/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_valid_walls_img.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:28:36 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/18 22:57:49 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_valid_extention(char **params)
{
	char	*ext;

	ext = ft_strrchr(params[1], '.');
	if (ft_strcmp(ext, EXTEN_IMG))
	{
		free_dstr(params);
		ft_print_errors(ERROR_EXTEN_IMG);
	}
}

void	ft_check_walls_files(char **params, t_game **game)
{
	int		w;
	int		y;
	void	*img;

	w = 0;
	y = 0;
	ft_valid_extention(params);
	img = mlx_xpm_file_to_image((*game)->mlx, params[1], &w, &y);
	if (!img)
	{
		free_dstr(params);
		ft_print_errors("strerror(errno)");
	}
	if (!ft_strcmp(W_NO, params[0]))
		(*game)->w_no = img;
	else if (!ft_strcmp(W_SO, params[0]))
		(*game)->w_so = img;
	else if (!ft_strcmp(W_WE, params[0]))
		(*game)->w_we = img;
	else if (!ft_strcmp(W_EA, params[0]))
		(*game)->w_ea = img;
}
