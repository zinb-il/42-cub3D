/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_valid_map_params.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:54:24 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/15 23:05:55 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_valid_map_params(char *file_name, t_game **game)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_print_errors(strerror(errno));
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line))
		{
			i++;
			if (i <= 5 && i >= 1)
				ft_check_walls_files_colors(line, i, game);
			else
				ft_check_map(game, line);
		}
		if (!ft_strlen(line) && i > 5)
			ft_print_errors(ERROR_INVALID_MAP);
		line = get_next_line(fd);
	}
	close(fd);
}
