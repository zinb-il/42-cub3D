/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:53:50 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/13 02:41:41 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SPRITE_BONUS_H
# define SPRITE_BONUS_H

# define SPRITE "./img_cub/sprite_black.xpm"
# define DOOR1 "./img_cub/door_1.xpm"
# define DOOR2  "./img_cub/door_2.xpm"
# define DOOR3 "./img_cub/door_3.xpm"

float	ft_nomlize_arctan(float ang);
void	get_elem_xy(t_sprite *sprite, int i, int j, int index);
void	ft_distance_s(t_data *data, int i);
void	init_sprites(t_data *data);
void	get_visible_sprites(t_data *data);

#	endif