/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_valid_map_params.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:54:24 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/16 23:42:43 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_check_walls_files_colors_map(char *line, int i, t_game **game)
{
	if (i <= 6 && i >= 1)
		ft_check_walls_files_colors(line, game);
	else
		ft_check_map(line, game);
}

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
	if (!line)
		ft_print_errors(ERROR_EMPTY_FILE);
	while (line)
	{
		if (ft_strlen(line) && line[0] != '\n')
		{
			i++;
			ft_check_walls_files_colors_map(line, i, game);
		}
		if (ft_strlen(line) == 1 && i > 6)
			ft_print_errors(ERROR_INVALID_MAP);
		line = get_next_line(fd);
	}
	close(fd);
}
