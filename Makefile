VRLIBFT= libft/libft.a

SRCS = src/main.c src/parse/cub3D_utils_1.c src/parse/cub3D_utils_2.c src/parse/cub3D_valid_map_params.c src/parse/cub3D_valid_map_description.c \
       src/map_2D/map_2d_1.c src/map_2D/map_2d_2.c src/map_2D/map_2d_3.c src/parse/cub3D_valid_map_elemts_1.c\
	   src/parse/cub3D_valid_map_elemts_2.c src/mouvement/mouvement.c src/mouvement/util_mouv.c src/parse/cub3D_valid_colors.c src/parse/cub3D_valid_walls_img.c \
	   src/raycasting/raycasting_1.c src/raycasting/raycasting_2.c src/raycasting/raycasting_3.c src/map_3D/map_3d_1.c \
	   src/mini_map/mini_map.c src/mini_map/setup_min.c src/util/util_1.c src/map_3D/wall.c $(VRLIBFT)\

SRCS_BONUS = src/main_bonus.c src/parse/cub3D_utils_1_bonus.c src/parse/cub3D_utils_2_bonus.c src/parse/cub3D_valid_map_params_bonus.c\
		src/parse/cub3D_valid_map_description_bonus.c src/parse/cub3D_valid_map_elemts_1_bonus.c src/parse/cub3D_valid_map_elemts_2_bonus.c \
		src/parse/cub3D_valid_colors_bonus.c src/parse/cub3D_valid_walls_img_bonus.c $(VRLIBFT_BONUS)\

CC = cc

FLAGS = -Wall -Werror -Wextra -fsanitize=address -g

DEBUG = -fsanitize=address -g

NAME = cub3D

BONUS = cub3D_bonus


all : $(NAME)

$(VRLIBFT):
	@make -C libft
	@cp $(VRLIBFT) $(NAME)
	@make -C libft clean

$(VRLIBFT_BONUS):
	@make -C libft
	@cp $(VRLIBFT) $(BONUS)
	@make -C libft clean

INCLUDES =  src/mlx/

LINKS =  src/mlx/ -lmlx -framework OpenGL -framework AppKit

$(NAME):$(VRLIBFT) $(SRCS)
	@$(CC) $(FLAGS) -I $(INCLUDES) $(SRCS) -L $(LINKS) -o $(NAME)
	@echo "\033[0;32m the library of cub3D is perfectly constructed\033[0;37m"

bonus:$(VRLIBFT_BONUS)
	@$(CC) $(FLAGS) -I $(INCLUDES) $(SRCS) -L $(LINKS) -o $(BONUS)
	@echo "\033[0;32m the library of cub3D is perfectly constructed\033[0;37m"

clean:
	@echo "\033[0;34m the .o files deleted\033[0;37m"

fclean:
	@make -C libft fclean
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	@echo "\033[0;34m the library of cub3D is perfectly deconstructed\033[0;37m"

re: fclean all

.PHONY: all clean fclean re