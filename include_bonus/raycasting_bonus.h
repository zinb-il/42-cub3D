/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:48:44 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/18 17:16:35 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef RAYCASTING_BONUS_H
# define RAYCASTING_BONUS_H
# define NORTH 4.71
# define SOUTH 1.57
# define WEST PI
# define EAST 0

t_raycast	*init_raycat(void);
float		ft_calc_distance(t_data *data, t_point point);
float		normalize_angle(float angle);
void		ft_ray_cast(t_data *data, float ray_angl, int i);
void		cast_allrays(t_data *data);
void		start_raycast(t_data *data);
int			ft_ray_facing(float ray_ang, char *face);
int			ft_end_win(t_data *data, float x, float y);
int			ft_wall_grid(t_data *data, t_info in, int index);
t_point		ft_distance_coordinat(t_data *data, t_info in, int i, \
int true_if_hor);
t_point		ft_distance_coordinat2(t_data *data, t_info in, int i, \
int true_if_hor);
void		ft_diffrent_hit(t_point point_h, t_point point_v, \
t_data *data, int i);
#	endif