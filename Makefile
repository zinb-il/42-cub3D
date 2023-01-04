VRLIBFT= libft/libft.a

SRCS = src/main.c src/parse/cub3D_utils_1.c src/parse/cub3D_utils_2.c src/parse/cub3D_valid_map_params.c src/parse/cub3D_valid_map_description.c \
       src/map_2D/map_2d_1.c src/map_2D/map_2d_2.c src/map_2D/map_2d_3.c src/parse/cub3D_valid_map_elemts_1.c\
	   src/parse/cub3D_valid_map_elemts_2.c src/mouvement/mouvement.c src/mouvement/util_mouv.c src/parse/cub3D_valid_colors.c src/parse/cub3D_valid_walls_img.c \
	   src/raycasting/raycasting_1.c src/raycasting/raycasting_2.c src/raycasting/raycasting_3.c src/map_3D/map_3d_1.c \
	   src/mini_map/mini_map.c src/mini_map/setup_min.c src/util/util_1.c src/map_3D/wall.c $(VRLIBFT)\

SRCS_BONUS = src_bonus/main_bonus.c src_bonus/parse/cub3D_utils_1_bonus.c src_bonus/parse/cub3D_utils_2_bonus.c src_bonus/parse/cub3D_valid_map_params_bonus.c src_bonus/parse/cub3D_valid_map_description_bonus.c \
       src_bonus/map_2D/map_2d_1_bonus.c src_bonus/map_2D/map_2d_2_bonus.c src_bonus/map_2D/map_2d_3_bonus.c src_bonus/parse/cub3D_valid_map_elemts_1_bonus.c\
	   src_bonus/parse/cub3D_valid_map_elemts_2_bonus.c src_bonus/mouvement/mouvement_bonus.c src_bonus/mouvement/util_mouv_bonus.c src_bonus/parse/cub3D_valid_colors_bonus.c src_bonus/parse/cub3D_valid_walls_img_bonus.c \
	   src_bonus/raycasting/raycasting_1_bonus.c src_bonus/raycasting/raycasting_2_bonus.c src_bonus/raycasting/raycasting_3_bonus.c src_bonus/map_3D/map_3d_1_bonus.c \
	   src_bonus/mini_map/mini_map_bonus.c src_bonus/mini_map/setup_min_bonus.c src_bonus/util/util_1_bonus.c src_bonus/map_3D/wall_bonus.c \
	   src_bonus/sprite_doors/* $(VRLIBFT)\

CC = cc

FLAGS = -Wall -Werror -Wextra  -fsanitize=address -g

DEBUG = -fsanitize=address -g

NAME = cub3D

BONUS = cub3D_bonus

INCLUDES =  mlx/

LINKS =  mlx/ -lmlx -framework OpenGL -framework AppKit

$(VRLIBFT):
	@make -C libft
	@cp $(VRLIBFT) $(NAME)
	@make -C libft clean

$(NAME):$(VRLIBFT) $(SRCS)
	@$(CC) $(FLAGS) -I $(INCLUDES) $(SRCS) -L $(LINKS) -o $(NAME)
	@echo "\033[0;32m the library of cub3D is perfectly constructed\033[0;37m"

$(BONUS): $(SRCS_BONUS)
	@make -C libft
	@cp libft/libft.a $(BONUS)
	@make -C libft clean
	@$(CC) $(FLAGS) -I $(INCLUDES) $(SRCS_BONUS) -L $(LINKS) -o $(BONUS)
	@echo "\033[0;32m the library of cub3D_Bonus is perfectly constructed\033[0;37m"

all : $(NAME)

bonus:$(BONUS)

clean:
	@echo "\033[0;34m the .o files deleted\033[0;37m"

fclean:
	@make -C libft fclean
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	@echo "\033[0;34m the library of cub3D is perfectly deconstructed\033[0;37m"

re: fclean all 

.PHONY: all clean fclean re