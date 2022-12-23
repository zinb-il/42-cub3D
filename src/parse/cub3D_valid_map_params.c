/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_valid_map_params.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:54:24 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/23 23:58:35 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_check_empty(t_game *gm)
{
	if (!gm->w_no && !gm->w_so && !gm->w_ea && !gm->w_we && \
	!gm->map && gm->c_c < 0 && gm->c_f < 0)
		ft_print_errors(ERROR_EMPTY_FILE);
	if (!gm->w_no || !gm->w_so || !gm->w_ea || !gm->w_we || \
	gm->c_c < 0 || gm->c_f < 0)
		ft_print_errors(ERROR_INCMP_PARAM);
	if (!gm->map)
		ft_print_errors(ERROR_EMPTY_MAP);
}

int	ft_spaces(char *str)
{
	size_t	c;

	c = ft_count_char(str, ' ');
	c += ft_count_char(str, '\n');
	if (c == ft_strlen(str))
		return (1);
	return (0);
}

void	ft_check_walls_files_colors_map(char *line, int i, t_game **game)
{
	if (i <= 6 && i >= 1 && !ft_spaces(line))
		ft_check_walls_files_colors(line, game);
	if (i > 6)
		ft_check_map(line, game);
}

void	ft_get_line(char **line)
{
	char	*line1;
	int		i;

	i = ft_strlen((*line));
	if ((*line)[i - 1] != '\n')
		return ;
	line1 = (*line);
	(*line) = ft_substr((*line), 0, ft_strlen((*line)) - 1);
	free(line1);
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
	while (line)
	{
		if (ft_strlen(line) && line[0] != '\n')
		{
			i++;
			ft_get_line(&line);
			ft_check_walls_files_colors_map(line, i, game);
		}
		if (ft_strlen(line) == 1 && i > 6 && line[0] == '\n')
			ft_print_errors(ERROR_INVALID_MAP);
		free(line);
		line = get_next_line(fd);
	}
	ft_check_empty(*game);
	close(fd);
}
