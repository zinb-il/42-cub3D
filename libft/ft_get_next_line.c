/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:50:28 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/25 17:09:53 by iouazzan         ###   ########.fr       */
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
	int		i;
	int		rd;
	char	*buff;
	char	c;

	i = 0;
	buff = ft_calloc(2, sizeof(char));
	rd = read(fd, &c, 1);
	while (rd > 0)
	{
		if (c == '\n')
			break ;
		i++;
		add_buff(c, &buff);
		rd = read(fd, &c, 1);
	}
	if ((!buff[i] && !rd) || rd == -1)
	{
		free(buff);
		return (0);
	}
	buff[i] = '\0';
	return (buff);
}