/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:50:32 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/28 22:27:20 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	j;
	char	*d;
	char	*s;

	s = (char *)src;
	d = (char *)dest;
	i = 0;
	j = 0;
	while (s[j])
		j++;
	if ((!dest && n == 0) || n <= 0)
		return (j);
	while (i < n - 1 && s[i])
	{
		d[i] = s[i];
		i++;
	}
	while (i < n - 1)
	{
		d[i] = ' ';
		i++;
	}
	d[i] = 0;
	return (j);
}
