/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:52:16 by iouazzan          #+#    #+#             */
/*   Updated: 2022/12/27 19:26:18 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINI_MAP_BONUS_H
# define MINI_MAP_BONUS_H

# define S_MIN_WIN 32
# define NB_WIN 11

int		check_des(t_data *data, int x, int y);
void	setup_map(t_data *data, int i, int j);
void	draw_win(t_data *data, int i, int j, int clr);
void	s_m_win(t_data *data, int k, int l);
void	mini_map(t_data *data);
void	setup_player_min(t_data *data);
void	draw_line_utl_m(t_data *data, int x2, int y2);
void	draw_line_m(t_data *data, int x2, int y2, int color);

#	endif