VRLIBFT= libft/libft.a

SRCS = src/main.c src/parse/cub3D_utils_1.c src/parse/cub3D_utils_2.c src/parse/cub3D_valid_map_params.c\
		src/parse/cub3D_valid_map_description.c src/map_2D/map_2d.c\
		src/mouvement/mouvement.c src/mouvement/util_mouv.c\
		src/parse/cub3D_valid_colors.c src/parse/cub3D_valid_walls_img.c $(VRLIBFT)\

CC = cc

FLAGS = -Wall -Werror -Wextra

DEBUG = -fsanitize=address -g

NAME = cub3D


all : $(NAME)

$(VRLIBFT):
	@make -C libft
	@cp $(VRLIBFT) $(NAME)
	@make -C libft clean

INCLUDES =  src/mlx/

LINKS =  src/mlx/ -lmlx -framework OpenGL -framework AppKit

$(NAME):$(VRLIBFT)
	@$(CC) $(FLAGS) -I $(INCLUDES) $(SRCS) -L $(LINKS) -o $(NAME)
	@echo "\033[0;32m the library of cub3D is perfectly constructed\033[0;37m"

debug:$(VRLIBFT)
	@$(CC) $(FLAGS) $(DEBUG) -I $(INCLUDES) $(SRCS) -L $(LINKS) -o $(NAME)
	@echo "\033[0;32m the library of cub3D is perfectly constructed\033[0;37m"

clean:
	@echo "\033[0;34m the .o files deleted\033[0;37m"

fclean:
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "\033[0;34m the library of cub3D is perfectly deconstructed\033[0;37m"

re: fclean all

.PHONY: all clean fclean re