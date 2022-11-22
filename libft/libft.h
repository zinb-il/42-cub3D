/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:06:38 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/22 22:24:23 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t n, size_t s);
void	free_dstr(char	**str);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char *str);
size_t	ft_dstrlen(char **str);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strrchr(const char *str, int c);
char	*get_next_line(int fd);
char	*ft_strdup(char *s);
size_t	ft_strlcpy(void *dest, const void *src, size_t n);

#	endif