/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:38:27 by iouazzan          #+#    #+#             */
/*   Updated: 2022/11/28 20:00:49 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

# define NB_LINE 14
# define NB_COL 34
# define SIZE_WIN 64
# define WIDTH_MAP (NB_COL * 64)
# define HEIGHT_MAP (NB_LINE * 64)
# define RECTANGLE 60
# define PI 3.141592
# define RETATION (PI / 2)
# define MOVE_SPEED 7
# define ROTATION_SPEED .1

typedef struct s_player
{
	int	width;
	int	heght;
	size_t	color;
}	t_player;

typedef struct s_data
{
	struct  s_cub3d *game;
	struct	s_player *player;
	void	*mlx_win;
	float	player_x;
	float	pp_x;
	float	pp_y;
	float	retation;
	float	player_y;
}	t_data;


void	map_2d(t_data *game);
void	setup_map(t_data *data, int i, int j);
int		encode_rgb(int red, int green, int blue);
void	setup_player(t_data *data);
void	setup_line(t_data *data);
void	mouve_player(t_data *data);
int		check_next_step(t_data *data, int x, int y, int x0, int y0);
void	draw_line(t_data *data ,int x1, int y1, int x2, int y2);
int		check_point(t_data *data ,int x1, int y1, int x2, int y2);
int		aspects(t_data *data, int px, int py, int x, int y);
void	walk_right(t_data *data);
void	walk_left(t_data *data);
void	walk_down(t_data *data);
void	walk_up(t_data *data);
void	ret_right(t_data *data);
void	ret_left(t_data *data);
void	init_data(t_game *game, t_data *data, t_player *player);
int		check_sides(t_data *data, int px, int py, int x, int y);
