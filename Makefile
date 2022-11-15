SRCS = main.c cub3D_utils_1.c cub3D_valid_map_params.c

LIBFT_SRCS  =  libft/ft_strcmp.c libft/ft_strrchr.c libft/ft_strlen.c libft/ft_get_next_line.c

CFLAGS = -Wall -Wextra -Werror

NAME = cub3D

OBJS = $(SRCS:.c=.o)

LIBFT_OBJS = $(SRCS:.c=.o)

CC = cc

INCLUDES =  mlx/

LINKS =  mlx/ -lmlx -framework OpenGL -framework AppKit

$(NAME) :
		$(CC) $(CFLAGS) -I $(INCLUDES) -o $(NAME) $(SRCS) $(LIBFT_SRCS) -L $(LINKS)

all : $(NAME)


clean :
		rm -f $(OBJS) $(LIBFT_OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all	

.PHONY: all clean fclean re
