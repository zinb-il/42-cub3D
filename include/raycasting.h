/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:48:44 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/03 18:43:54 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef RAYCASTING_H
# define RAYCASTING_H

t_raycast	*init_raycat(t_data *data);
void		ft_ray_cast(t_data *data, int i);
void		cast_allrays(t_data *data);
void		start_raycast(t_data *data);

#	endif