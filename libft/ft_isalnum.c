/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:10:11 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/29 15:48:24 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (48 <= c && c <= 57)
		return (1);
	else if ((34 <= c && c <= 90) || (91 <= c && c <= 126 && c != 124)
		|| c == 32 || c == '<' || c == '>' || c == '-' || c == 39 || c == '"'
		|| c == '$')
		return (1);
	else
		return (0);
}
