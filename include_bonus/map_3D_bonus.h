/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3D_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:17:27 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/17 17:29:21 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MAP_3D_BONUS_H
# define MAP_3D_BONUS_H

void	map_3d(t_data *data);
char	*sprite_door_t(t_data *data, int nb, int t_setx, int t_sety);
void	get_walls_dimension(t_data *data, float wallstrip_h, int i);
void	draw_wall(t_data *data, int in, int wallstrip_h);
char	*way(t_data *data, int nb, int t_setx, int t_sety);
void	draw_floor(t_data *data, int in);
void	draw_ceilling(t_data *data, int in);

#	endif