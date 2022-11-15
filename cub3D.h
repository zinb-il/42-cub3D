/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:06:09 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/15 23:05:14 by ziloughm         ###   ########.fr       */
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

// Define Errors Messages
# define ERROR_ALLOCATION "une erreur inconue s\'est produit"
# define ERROR_PARAMETERS "les paramètres passés sont incorrects"
# define ERROR_EXTENTION "\'extension choisie est incorrecte"
# define ERROR_INVALID_MAP "la description de votre map est invalide"
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

//Define Game Struct
typedef struct cub3d
{
	char	**map;
	void	*mlx;
	void	*window;
}t_game;

//Functions to print errors message and exit
void	ft_print_errors(char *msg);
//Functions to validate the parameters
void	ft_check_extension(char *s);
void	ft_valid_map_params(char *file_name, t_game **game);

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