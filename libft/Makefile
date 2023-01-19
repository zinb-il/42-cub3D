# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/21 03:34:46 by iouazzan          #+#    #+#              #
#    Updated: 2023/01/19 20:10:50 by ziloughm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY = ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_split.c ft_strchr.c ft_strdup.c ft_strlcpy.c \
			ft_strlen.c ft_strrchr.c ft_substr.c \
			ft_get_next_line.c ft_dstrlen.c ft_free_dstr.c ft_strcmp.c ft_count_char.c\

CC = cc

FLAGS = -Wall -Werror -Wextra -c

NAME = libft.a

DEBUG = -fsanitize=address -g

O_MANDATORY = $(MANDATORY:.c=.o)

.c.o:
	@$(CC) $(FLAGS) $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(O_MANDATORY)
	@ar -rc $(NAME) $(O_MANDATORY)
	@echo "\033[0;32m the library of libft is perfectly constructed\033[0;37m"

debug:
	@$(CC) $(FLAGS) $(DEBUG) $(MANDATORY) -o $(NAME)
	@echo "\033[0;32m the library of libft is perfectly constructed\033[0;37m"

clean:
	@rm -rf $(O_MANDATORY)

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;31m the library of libft is perfectly deconstructed\033[0;37m"

re: fclean all