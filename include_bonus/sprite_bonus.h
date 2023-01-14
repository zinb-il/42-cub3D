/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:53:50 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/14 21:16:07 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SPRITE_BONUS_H
# define SPRITE_BONUS_H

# define SPRITE1 "./img_cub/sprite_12.xpm"
# define SPRITE2 "./img_cub/sprite_13.xpm"
# define DOOR1 "./img_cub/door_1.xpm"
# define DOOR2  "./img_cub/door_2.xpm"
# define DOOR3 "./img_cub/door_3.xpm"

float	ft_nomlize_arctan(float ang);
void	get_elem_xy(t_sprite *sprite, int i, int j, int index);
void	ft_distance_s(t_data *data, int i);
void	init_sprites(t_data *data);
void	get_visible_sprites(t_data *data);

#	endif