/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:52:16 by iouazzan          #+#    #+#             */
/*   Updated: 2022/12/09 02:40:06 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINI_MAP_H
# define MINI_MAP_H

# define S_MIN_WIN 32
# define NB_WIN 11

void	setup_map(t_data *data, int i, int j);
void	draw_win(t_data *data, int i, int j, int clr);
void	s_m_map(t_data *data, int i, int j, int k, int l);
void	mini_map(t_data *data);
void	draw_win_null(t_data *data, int i, int j);
void	setup_player_min(t_data *data);
void	draw_line_utl_m(t_data *data, int x2, int y2);
void	draw_line_m(t_data *data, int x2, int y2, int color);

#	endif