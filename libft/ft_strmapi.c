/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:52:04 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/29 15:48:23 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	sub = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (s[i])
	{
		sub[i] = (*f)(i, s[i]);
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
