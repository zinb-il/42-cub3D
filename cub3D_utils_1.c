/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:58:53 by ziloughm          #+#    #+#             */
/*   Updated: 2022/11/15 22:55:01 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_check_extension(char *s)
{
	char	*file_name;

	file_name = ft_strrchr(s, '.');
	if (!file_name || ft_strcmp(file_name, ".cub"))
	{
		printf("%s", ERROR_EXTENTION);
		exit(EXIT_FAILURE);
	}
}

void	ft_print_errors(char *msg)
{
	if (msg)
		printf("ERROR\n: %s\n", msg);
	exit (EXIT_FAILURE);
}
