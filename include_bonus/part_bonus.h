/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:38:27 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/14 21:37:57 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PART_BONUS_H
# define PART_BONUS_H

# define SIZE_WIN 64
# define SCALE 1
# define EPSILON 0.2617
# define RECTANGLE 60
# define PI 3.14159265359
# define MOVE_SPEED 10
# define ROTATION_SPEED .1
# define MAP_W 1500
# define DIS 10
# define MAP_H 720
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

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
	int		was_h;
	int		was_v;
	int		was_h_v;
	int		wl_h;
	int		wl_t;
	int		wl_b;
	int		wl_x;
	int		wl_y;
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

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_sprite
{
	int		x;
	int		y;
	int		visible;
	float	distance;
	float	top_y;
	float	bottom_y;
	float	left_x;
	float	right_x;
	float	h;
	float	angl;
}t_sprite;

typedef struct s_door
{
	int		x;
	int		y;
	int		visible;
	float	distance;
}t_door;

typedef struct s_data
{
	struct s_cub3d	*gm;
	struct s_line	*line;
	struct s_img	*img;
	struct s_img	north;
	struct s_img	west;
	struct s_img	east;
	struct s_img	south;
	struct s_img	sprite1;
	struct s_img	sprite2;
	struct s_img	door;
	void			*mlx_win;
	float			pp_x;
	float			pp_y;
	float			n_p_x;
	float			n_p_y;
	float			distance_pro;
	int				c_x;
	int				c_y;
	int				p_p_mini;
	float			retation;
	int				old_x_m;
	int				keys[3][2];
	int				num_spri;
	int				num_door;
	int				anim;
	t_raycast		*raycat;
	t_sprite		*sprites;
	t_door			*doors;
}	t_data;

int		check_sides(t_data *data, int x, int y);
int		mouse_hook(int x, int y, t_data *data);
int		key_hookup(int keycode, t_data *data);
int		key_hookdown(int keycode, t_data *data);
void	setup_map(t_data *data, int i, int j);
void	setup_player(t_data *data);
void	mouve_player(t_data *data);
void	draw_line(t_data *data, int x2, int y2, int color);
void	init_data(t_game *game, t_data *data);
void	draw_line_utl(t_data *data, int x2, int y2);
void	mouve(t_data *data, int way, int ang);
void	draw_win(t_data *data, int i, int j, int clr);
void	collisions_wall(t_data *data, int x, int y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	map_position(t_data *data);

#	endif
