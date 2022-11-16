/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:06:09 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/17 00:11:49 by ziloughm         ###   ########.fr       */
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
# include "mlx.h"
# include "libft/libft.h"

//Map Extension
# define EXTEN_MAP ".cub"

// Define Errors Messages
# define ERROR_EMPTY_FILE "votre fichier est vide"
# define ERROR_PARAMETERS "les paramètres passés sont incorrects"
# define ERROR_EXTENTION "\'extension choisie est incorrecte"
# define ERROR_INVALID_MAP "votre map est invalide"
# define ERROR_INVALID_PARAMS "la description de votre map est invalide"
# define ERROR_INVALID_PCOLORS "la description des couleurs est invalide"
# define ERROR_INVALID_WALL "les mures de votre map sont invalides"
# define ERROR_EXIT_MAP "la map doit contenir au moins une sortie"
# define ERROR_COLLECT_MAP "la map doit contenir au moins une item"
# define ERROR_PLAYER_MAP "la map doit contenir au maximum un joueur"

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
typedef struct cub3d
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
void	ft_check_colors(char **params, t_game **game);
void	ft_check_walls_files(char **params, t_game **game);
void	ft_check_walls_files_colors(char *line, t_game **game);
void	ft_check_walls_files_colors_map(char *line, int i, t_game **game);

void	ft_exit_failure1(t_game *g);
void	ft_check_exit(t_game *g);
void	ft_putstr_window(t_game *g);
int		ft_destroy_window(t_game *g);
int		ft_key_press(int key_code, t_game **g);
char	**ft_valid_map(char *file_name);
void	ft_check_map_elemnts(char **map);
t_game	*ft_draw_map(t_game *game);
t_game	*ft_move_up_down(t_game *g, int r, int u);
t_game	*ft_update_map(t_game *g, int i, int j);
void	ft_draw_image(t_game *g, char c, int i, int j);

#	endif