/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:53:21 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/29 15:48:23 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *f, const char *s, size_t n)
{
	size_t			i;
	unsigned char	*cf;
	unsigned char	*cs;

	cf = (unsigned char *)f;
	cs = (unsigned char *)s;
	i = 0;
	while ((cf[i] || cs[i]) && i < n)
	{
		if (cf[i] != cs[i])
			return (cf[i] - cs[i]);
		i++;
	}
	return (0);
}
