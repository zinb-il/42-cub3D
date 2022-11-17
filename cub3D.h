/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:06:09 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/18 00:47:41 by ziloughm         ###   ########.fr       */
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
void	ft_check_walls_files_colors(char *line, t_game **game);
void	ft_check_walls_files_colors_map(char *line, int i, t_game **game);

//Functions to validate walls images
void	ft_valid_extention(char **params);
void	ft_check_walls_files(char **params, t_game **game);

//Functions to validate colors
int		ft_get_color(char *color);
void	ft_valid_colors(char **colors, char **params, t_game **game);
void	ft_check_colors(char **params, t_game **game);
#	endif