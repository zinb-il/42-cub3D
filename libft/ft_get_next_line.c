/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:50:28 by ziloughm          #+#    #+#             */
/*   Updated: 2022/12/11 23:40:19 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_buff(char c, char **buff)
{
	int		i;
	int		j;
	char	*buf;

	i = (int)ft_strlen(*buff) + 1;
	buf = (char *)malloc(sizeof(char ) * (i + 1));
	j = 0;
	while ((*buff) && (*buff)[j])
	{
		buf[j] = (*buff)[j];
		j++;
	}
	if (*buff)
		free(*buff);
	buf[j] = c;
	buf[j + 1] = 0;
	(*buff) = buf;
}

char	*get_next_line(int fd)
{
	int		rd;
	char	*buff;
	char	c;

	buff = ft_calloc(2, sizeof(char));
	rd = read(fd, &c, 1);
	while (rd > 0)
	{
		add_buff(c, &buff);
		if (c == '\n')
			break ;
		rd = read(fd, &c, 1);
	}
	if (buff[0] == 0 || rd == -1)
	{
		free(buff);
		return (0);
	}
	return (buff);
}
