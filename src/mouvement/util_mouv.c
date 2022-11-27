/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_mouv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:49:40 by iouazzan          #+#    #+#             */
/*   Updated: 2022/11/26 22:47:22 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int		check_next_step(t_data *data, int x, int y, int x0, int y0)
{	
// 	x /= 64;
// 	x0 /= 64;
// 	y /= 64;
// 	y0 /= 64;
	if (check_point(data, x0, y0, x, y) == 1)
		return (1);
	return 0;
}
