/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:38:27 by iouazzan          #+#    #+#             */
/*   Updated: 2022/12/16 20:32:04 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PART_H
# define PART_H

# define SIZE_WIN 64
# define SCALE 1
# define RECTANGLE 60
# define PI 3.141592
# define MOVE_SPEED 13
# define ROTATION_SPEED .1
# define MAP_W 1500
# define MAP_H 720

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

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	struct s_cub3d	*gm;
	struct s_line	*line;
	struct s_img	*img;
	void			*mlx_win;
	float			pp_x;
	float			pp_y;
	int				c_x;
	int				c_y;
	int				p_p_mini;
	float			retation;
	int				old_x_m;
	int				st_x;
	int				st_y;
	int				keys[3][2];
	t_raycast		*raycat;
}	t_data;

void	map_2d(t_data *data);
void	setup_map(t_data *data, int i, int j);
void	setup_player(t_data *data);
void	setup_line(t_data *data);
void	mouve_player(t_data *data);
void	draw_line(t_data *data, int x2, int y2, int color);
void	ret_left_right(t_data *data, float speed);
void	init_data(t_game *game, t_data *data);
int		check_sides(t_data *data, int x, int y);
int		mouse_hook(int x, int y, t_data *data);
void	draw_line_utl(t_data *data, int x2, int y2);
int		key_hookup(int keycode, t_data *data);
int		key_hookdown(int keycode, t_data *data);
void	mouve(t_data *data, int way, int ang);
void	draw_win(t_data *data, int i, int j, int clr);
void	collisions_wall(t_data *data, int x, int y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#	endif
