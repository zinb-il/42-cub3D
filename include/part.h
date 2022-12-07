/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:38:27 by iouazzan          #+#    #+#             */
/*   Updated: 2022/12/07 16:54:48 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PART_H
# define PART_H

# define SIZE_WIN 64
# define S_MIN_WIN 10
# define SCALE 0.5
# define RECTANGLE 60
# define PI 3.141592
# define MOVE_SPEED 100
# define ROTATION_SPEED .1
# define MAP_W 1500
# define MAP_H 900

typedef struct s_point
{
	float	x;
	float	y;
}t_point;

typedef struct s_info
{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	float	xhit;
	float	yhit;
	int		xdecre;
	int		ydecre;
}t_info;

typedef struct ray
{
	float	ray_angl;
	float	wallhit_x;
	float	wallhit_y;
	float	distance;
}t_ray;

typedef struct raycat
{
	float	fov_angl;
	int		num_rays;
	int		wall_strip_width;
	t_ray	*rays;
}t_raycast;

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
	t_raycast		*raycat;
}	t_data;

void	map_2d(t_data *data);
void	setup_map(t_data *data, int i, int j);
void	setup_player(t_data *data);
void	setup_line(t_data *data);
void	mouve_player(t_data *data);
int		check_next_step(t_data *data, int x, int y);
void	draw_line(t_data *data, int x2, int y2, int color);
void	ret_right(t_data *data);
void	ret_left(t_data *data);
void	init_data(t_game *game, t_data *data);
int		check_sides(t_data *data, int x, int y);
int		mouse_hook(int x, int y, t_data *data);
void	draw_line_utl(t_data *data, int x2, int y2);
int		key_hook(int keycode, t_data *data);
void	mouve(t_data *data, int way, int ang);

#	endif
