/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:38:41 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/03 19:37:57 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3D_bonus.h"

void	print_ray(t_ray ray)
{
	printf("distance %f hitX %f hitY %f angl %f\n", ray.distance, ray.wallhit_x, \
	ray.wallhit_y, ray.ray_angl);
}

void	print_rays(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->raycat->num_rays)
	{
		print_ray(data->raycat->rays[i]);
		i++;
	}
}

void	print_sprite(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_spri)
	{
		printf("Sprite %d: x %d y %d vis %d\n", i, \
		data->sprites[i].x, data->sprites[i].y, data->sprites[i].visible);
		i++;
	}
}

int	count_elements(char	**str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		count += ft_count_char(str[i], c);
		i++;
	}
	return (count);
}

int	ft_destroy_window(t_data *data)
{
	mlx_destroy_window(data->gm->mlx, data->mlx_win);
	exit(0);
}
