/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:55:18 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/29 15:48:23 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;
	size_t	i;

	s = (char *)str;
	i = ft_strlen(str) + 1;
	while (i--)
	{
		if (s[i] == (char)c)
			return (s + i);
	}
	return (NULL);
}
// int main()
// {
// 	char *p = "qeqeq";
// 	char *i = p;

// 	printf("%s\n",&i[1]);
//  	char str[]="aymen";
//  	printf("%s",ft_strrchr(str, 'y'));
//  }