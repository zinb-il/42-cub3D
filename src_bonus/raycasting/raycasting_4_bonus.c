/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_4_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:22:43 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/18 18:03:46 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3D_bonus.h"

t_point	ft_distance_coordinat2(t_data *data, t_info in, int i, int true_if_hor)
{
	t_point	point;

	point.x = in.xhit - in.xdecre;
	point.y = in.yhit - in.ydecre;
	if (true_if_hor)
		data->raycat->rays[i].was_h = 1;
	else
		data->raycat->rays[i].was_v = 1;
	point.hit = data->raycat->rays[i].hi_type;
	return (point);
}
