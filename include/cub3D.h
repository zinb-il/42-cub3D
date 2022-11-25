/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:06:09 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/26 00:43:22 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
#  include <math.h>
# include "mlx.h"
# include "../libft/libft.h"

//Map Extension
# define EXTEN_MAP ".cub"

//Image Extension
# define EXTEN_IMG ".xpm"

// Define Errors Messages
# define ERROR_EMPTY_FILE "votre fichier est vide"
# define ERROR_PARAMETERS "les paramètres passés sont incorrects"
# define ERROR_EXTENTION "l\'extension choisie est incorrecte"
# define ERROR_EXTEN_IMG "l\'extension choisie pour les images est incorrecte"
# define ERROR_INVALID_MAP "votre carte est invalide"
# define ERROR_INVALID_PARAMS "la description de votre carte est invalide"
# define ERROR_INVALID_PCOLORS "la description des couleurs est invalide"
# define ERROR_INCMP_PARAM "la description de votre carte est complète"
# define ERROR_EMPTY_MAP "votre map est vide"

//Key Code
# define KEY_ESC 53
# define KEY_ESC1 12
# define KEY_UP 13
# define KEY_UP1 126
# define KEY_DOWN 1
# define KEY_DOWN1 125
# define KEY_LEFT 0
# define KEY_LEFT1 123
# define KEY_RIGHT 2
# define KEY_RIGHT1 124

//Map Params
# define W_NO "NO"
# define W_SO "SO"
# define W_WE "WE"
# define W_EA "EA"
# define COLOR_F "F"
# define COLOR_C "C"

//Define Game Struct
typedef struct s_cub3d
{
	char	**map;
	void	*mlx;
	void	*window;
	void	*w_no;
	void	*w_so;
	void	*w_we;
	void	*w_ea;
	int		c_f[3];
	int		c_c[3];
}t_game;

// Function to initialize the struct game 
void	ft_init_game(t_game **game);

//Functions to print errors message and exit
void	ft_print_errors(char *msg);

//Functions to validate the parameters
void	ft_check_extension(char *s);
void	ft_valid_map_params(char *file_name, t_game **game);

//Functions to parse wall files and colors
void	ft_check_map(char *line, t_game **game);
void	ft_check_walls_files_colors(char *line, t_game **game);
void	ft_check_walls_files_colors_map(char *line, int i, t_game **game);

//Functions to validate walls images
void	ft_valid_extention(char **params);
void	ft_check_walls_files(char **params, t_game **game);

//Functions to validate colors
int		ft_get_color(char *color);
void	ft_valid_colors(char **colors, char **params, t_game **game);
void	ft_check_colors(char **params, t_game **game);

/*********************************************************************************************/

# define NB_LINE 14
# define NB_COL 33
# define SIZE_WIN 64
# define WIDTH_MAP NB_COL * 64
# define HEIGHT_MAP NB_LINE * 64
# define NB_COL 33
# define RECTANGLE 60
# define PI 3.141592
# define RETATION (PI / 2)
# define MOVE_SPEED 7
# define ROTATION_SPEED .1
// # define PP_Y ((NB_COL / 2) * 64) + 32
// # define PP_X ((NB_LINE / 2) * 64) + 32
// # define PLAYER_X WIDTh_MAP / 2
// # define PLAYER_Y HEIGHT_MAP / 2

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

void	init_data(t_game *game, t_data *data, t_player *player);
void	map_2d(t_data *game);
void	setup_map(t_data *data, int i, int j);
int		encode_rgb(int red, int green, int blue);
void	setup_player(t_data *data);
void	setup_line(t_data *data);
void	ret_left(t_data *data);
void	ret_right(t_data *data);
void	walk_left(t_data *data);
void	walk_down(t_data *data);
void	walk_right(t_data *data);
void	walk_up(t_data *data);
void	mouve_player(t_data *data);
int		check_player(t_data *data, int x, int y);


#	endif