/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:41:20 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/03 19:28:01 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef UTIL_BONUS_H
# define UTIL_BONUS_H

void	print_ray(t_ray ray);
void	print_rays(t_data *data);
void	print_sprite(t_data *data);
int		ft_destroy_window(t_data *data);
int		count_elements(char	**str, char c);

#	endif