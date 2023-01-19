/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:20:50 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/19 20:09:26 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

int			ft_isalpha(int c);
int			ft_isalnum(int c);
size_t		ft_strlen(const char *str);
void		*ft_bzero(void *str, size_t n);
size_t		ft_count_char(char *s, char c);
size_t		ft_strlcpy(void *dest, const void *src, size_t n);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
char		*get_next_line(int fd);
size_t		ft_dstrlen(char **str);
void		free_dstr(char	**str);
int			ft_strcmp(const char *str1, const char *str2);

#endif
