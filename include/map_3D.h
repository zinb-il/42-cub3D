/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:17:27 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/22 20:52:02 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MAP_3D_H
# define MAP_3D_H

void	map_3d(t_data *data);
void	get_walls_dimension(t_data *data, float wallstrip_h, int i);
void	draw_wall(t_data *data, int in, int wallstrip_h);
char	*way(t_data *data, int nb, int t_setx, int t_sety);
void	draw_floor(t_data *data, int in);
void	draw_ceilling(t_data *data, int in);

#	endif