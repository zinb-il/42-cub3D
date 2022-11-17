/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_valid_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:11:00 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/18 00:25:40 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	ft_valid_colors(char **colors, char **params, t_game **game)
{
	int	i;
	int	c;

	i = 0;
	while (colors[i])
	{
		c = ft_get_color(colors[i]);
		if (c == -1)
		{
			free_dstr(params);
			free_dstr(colors);
			ft_print_errors(ERROR_INVALID_PCOLORS);
		}
		if (!ft_strcmp(COLOR_F, params[0]))
			(*game)->c_f[i] = c;
		else
			(*game)->c_c[i] = c;
		i++;
	}
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
