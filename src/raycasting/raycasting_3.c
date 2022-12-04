/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:40:19 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/03 23:40:44 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_ray_facing(float ray_ang, char *face)
{
	if (!face)
		return (-10);
	if (ft_strcmp(face, "up_do"))
	{
		if (ray_ang > 0 && ray_ang < PI)
			return (SIZE_WIN);
		return (0);
	}
	if (ft_strcmp(face, "le_ri"))
	{
		if (ray_ang < (PI * 0.5) || ray_ang > (PI * 1.5))
			return (1);
		return (0);
	}
	return (-10);
}
