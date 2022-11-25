#include "../../include/cub3D.h"

void	init_data(t_game *game, t_data *data, t_player *player)
{
	data->game = game;
	data->player = player;
	data->player_x = -2;
	data->player_y = -2;
	data->pp_y = ((NB_COL / 2) * 64) + 32;
	data->pp_x = ((NB_LINE / 2) * 64) + 32;
	data->player->width = 20;
	data->player->heght = 20;
	data->retation = (PI / 2);
	data->mlx_win = mlx_new_window(data->game->mlx, WIDTH_MAP, HEIGHT_MAP, "test");
}

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	setup_map(t_data *data, int i, int j)
{
	if (data->game->map[i][j] == '1')
		mlx_put_image_to_window
			(data->game->mlx, data->mlx_win, data->game->w_no, j * SIZE_WIN, i * SIZE_WIN);
	else if (data->game->map[i][j] == '0')
		mlx_put_image_to_window
			(data->game->mlx, data->mlx_win, data->game->w_so, j * SIZE_WIN, i * SIZE_WIN);
}

int pth (int x,int y)
{ 
    return sqrt (pow(x,2)+pow(y,2)); 
}


void	setup_line(t_data *data)
{
	int x;
	int y;

	x = data->pp_x;
	while (x < (data->pp_x + (sin((data->retation)) * 40)))
	{
		y = data->pp_y;
		while (y < (data->pp_y + (cos((data->retation)) * 40)))
		{
			mlx_pixel_put(data->game->mlx, data->mlx_win, y, x, 0x090060);
			++y;
		}
		++x;
	}
}

void	setup_player(t_data *data)
{
	int x;
	int y;
 
    int width = 5; 
    int length = width * 1.5;
	x = width;
    while (x >= -width)
	{
		y = -length;
        while (y <= length)
		{
            if (pth(x, y) <= width)
				mlx_pixel_put(data->game->mlx, data->mlx_win,
					(y + data->pp_y),
					(x + data->pp_x),
					0x09FF60);
			++y;
        }
		x -= 2;
	}
	setup_line( data);
}

int	key_hook(int keycode, t_data *data)
{
	
	if (keycode == 53)
		mlx_destroy_window(data->game->mlx, data->mlx_win);
	if (keycode == 123)
		ret_left(data);
	if (keycode == 124)
		ret_right(data);
	if (keycode == 0)
		walk_right(data);
	if (keycode == 2)
		walk_left(data);
	if (keycode == 1)
		walk_down(data);
	if (keycode == 13)
		walk_up(data);
	return (0);
}

void	mouve_player(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 0, key_hook, data);
}

void	map_2d(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->game->map[i])
	{
		j = 0;
		while (data->game->map[i][j])
		{
			setup_map(data, i , j);
			j++;
		}
		i++;
	}
	setup_player(data);
}