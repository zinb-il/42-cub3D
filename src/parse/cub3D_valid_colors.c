/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_valid_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:11:00 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/13 17:38:29 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_get_color(char *color)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (ft_strlen(color) <= 3 && ft_strlen(color) > 0)
	{
		while (color[i])
		{
			if (color[i] < 48 || color[i] > 57)
				return (-1);
			c = (c * 10) + (color[i] - 48);
			i++;
		}
		return (c);
	}
	return (-1);
}

void	ft_convert_rgb_to_hexa(int	*colors, char **params, t_game **game)
{
	unsigned long	hexa;

	hexa = colors[0] << 16 | colors[1] << 8 | colors[2] << 0;
	if (!ft_strcmp(COLOR_F, params[0]))
		(*game)->c_f = hexa;
	else
		(*game)->c_c = hexa;
}

void	ft_valid_colors(char **colors, char **params, t_game **game)
{
	int	i;
	int	c;
	int	clrs[3];

	i = 0;
	while (colors[i])
	{
		c = ft_get_color(colors[i]);
		if (c < -1 || c > 255)
		{
			free_dstr(params);
			free_dstr(colors);
			ft_print_errors(ERROR_INVALID_PCOLORS);
		}
		clrs[i] = c;
		i++;
	}
	ft_convert_rgb_to_hexa(clrs, params, game);
}

void	ft_check_colors(char **params, t_game **game)
{
	char	**colors;

	(void)game;
	colors = ft_split(params[1], ',');
	if (ft_dstrlen(colors) != 3)
	{
		free_dstr(params);
		free_dstr(colors);
		ft_print_errors(ERROR_INVALID_PCOLORS);
	}
	ft_valid_colors(colors, params, game);
	free_dstr(colors);
}
