/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:50:28 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/15 18:00:54 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	int		i;
	int		rd;
	char	*buff;
	char	c;

	i = 0;
	buff = malloc(10000);
	rd = read(fd, &c, 1);
	while (rd > 0)
	{
		buff[i] = c;
		i++;
		if (c == '\n')
			break ;
		rd = read(fd, &c, 1);
	}
	if ((!buff[i - 1] && !rd) || rd == -1)
	{
		free(buff);
		return (0);
	}
	buff[i] = '\0';
	return (buff);
}
