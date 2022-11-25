VRLIBFT= ./libft/libft.a

SRCS = src/main.c src/parse/cub3D_utils_1.c src/parse/cub3D_valid_map_params.c\
		src/parse/cub3D_valid_map_description.c src/map_2D/map_2d.c\
		src/mouvement/mouvement.c src/mouvement/util_mouv.c\
		src/parse/cub3D_valid_colors.c src/parse/cub3D_valid_walls_img.c $(VRLIBFT)\

CC=cc
FLAGS= -Wall -Werror -Wextra
DEBUG=-fsanitize=address -g
NAME = cub3D

all : $(NAME)

$(VRLIBFT):
	make bonus -C ./libft

INCLUDES =  src/mlx/

LINKS =  src/mlx/ -lmlx -framework OpenGL -framework AppKit

$(NAME):$(VRLIBFT) $(SRCS)
	$(CC) $(FLAGS) -I $(INCLUDES) $(SRCS) -L $(LINKS) -o $(NAME)

debug:$(VRLIBFT)
	$(CC) $(FLAGS) $(DEBUG) $(SRCS) $(VRLIBFT) -L $(LINKS) -o $(NAME)

clean:
	make clean -C libft

fclean:
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re