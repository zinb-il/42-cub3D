/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:38:27 by iouazzan          #+#    #+#             */
/*   Updated: 2022/12/02 22:30:39 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PART_H
# define PART_H

# define NB_LINE 14
# define NB_COL 34
# define SIZE_WIN 64
# define RECTANGLE 60
# define PI 3.141592
# define MOVE_SPEED 7
# define ROTATION_SPEED .1

typedef struct s_line
{
	float		dx;
	float		dy;
	float		step;
}	t_line;

typedef struct s_data
{
	struct s_cub3d	*gm;
	struct s_line	*line;
	void			*mlx_win;
	float			pp_x;
	float			pp_y;
	float			retation;
	int				old_x_m;
}	t_data;

void	map_2d(t_data *game);
void	setup_map(t_data *data, int i, int j);
void	setup_player(t_data *data);
void	setup_line(t_data *data);
void	mouve_player(t_data *data);
int		check_next_step(t_data *data, int x, int y);
void	draw_line(t_data *data, int x2, int y2);
void	ret_right(t_data *data);
void	ret_left(t_data *data);
void	init_data(t_game *game, t_data *data);
int		check_sides(t_data *data, int x, int y);
int		mouse_hook(int x, int y, t_data *data);
void	draw_line_utl(t_data *data, int x2, int y2);
int		key_hook(int keycode, t_data *data);
void	mouve(t_data *data, int way, int ang);

#	endif
