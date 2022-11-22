SRCS = main.c cub3D_utils_1.c cub3D_valid_map_params.c cub3D_valid_map_description.c cub3D_valid_colors.c cub3D_valid_walls_img.c

LIBFT_SRCS = libft/ft_strcmp.c libft/ft_strrchr.c libft/ft_strlen.c libft/ft_get_next_line.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_dstrlen.c \
			 libft/ft_split.c libft/ft_strdup.c libft/ft_free_dstr.c libft/ft_strlcpy.c

#CFLAGS = -Wall -Wextra -Werror

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

NAME = cub3D

OBJS = $(SRCS:.c=.o)

LIBFT_OBJS = $(SRCS:.c=.o)

CC = cc

INCLUDES =  mlx/

LINKS =  mlx/ -lmlx -framework OpenGL -framework AppKit

$(NAME) :
		@$(CC) $(CFLAGS) -I $(INCLUDES) -o $(NAME) $(SRCS) $(LIBFT_SRCS) -L $(LINKS)
		@echo "\033[0;32m the library is perfectly constructed\033[0;37m"

all : $(NAME)

clean :
		@rm -f $(OBJS)
		@echo "\033[0;31m the .o files deleted\033[0;37m"

fclean : clean
		@rm -f $(NAME)
		@echo "\033[0;31m the library is perfectly deconstructed\033[0;37m"

re : fclean all	

.PHONY: all clean fclean re
