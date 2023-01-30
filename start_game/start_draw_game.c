#include "../cub3d.h"

void	dx_dy(t_cubd	*cubgame)
{
	cubgame->dx = radian(cubgame->pozition);
	cubgame->dx = cos(cubgame->dx);
	cubgame->dy = radian(cubgame->pozition);
	cubgame->dy = -1 * sin(cubgame->dy);
}

void	search_null_mlx(t_cubd	*cubgame)
{
	if (!cubgame->we || !cubgame->no || !cubgame->so || !cubgame->ea || !cubgame->key1 || !cubgame->key2 || !cubgame->dur)
		exit_game(cubgame, "ERROR :not can mlx draw \n");
}

void	addr_start(t_cubd	*cubgame)
{
	cubgame->ad[2] = mlx_get_data_addr(cubgame->no, &cubgame->bits_per_pixel[2],
			&cubgame->line_length[2], &cubgame->endian[2]);
	cubgame->ad[3] = mlx_get_data_addr(cubgame->so, &cubgame->bits_per_pixel[3],
			&cubgame->line_length[3], &cubgame->endian[3]);
	cubgame->ad[4] = mlx_get_data_addr(cubgame->we, &cubgame->bits_per_pixel[4],
			&cubgame->line_length[4], &cubgame->endian[4]);
	cubgame->ad[5] = mlx_get_data_addr(cubgame->ea, &cubgame->bits_per_pixel[5],
			&cubgame->line_length[5], &cubgame->endian[5]);
	cubgame->ad[6] = mlx_get_data_addr(cubgame->dur, &cubgame->bits_per_pixel[6],
			&cubgame->line_length[6], &cubgame->endian[6]);
	cubgame->ad[7] = mlx_get_data_addr(cubgame->key1, &cubgame->bits_per_pixel[7],
			&cubgame->line_length[7], &cubgame->endian[7]);
	cubgame->ad[8] = mlx_get_data_addr(cubgame->key2, &cubgame->bits_per_pixel[8],
			&cubgame->line_length[8], &cubgame->endian[8]);
}

void	error_serch_addres(t_cubd	*cubgame)
{
	if (!cubgame->ad[2] || !cubgame->ad[3] || !cubgame->ad[4] || !cubgame->ad[5] || !cubgame->ad[6] || !cubgame->ad[7] || !cubgame->ad[8])
		exit_game(cubgame, "ERROR :not addr \n");
}

void	start_draw_game1(t_cubd	*cubgame)
{
	search_null_mlx(cubgame);
	addr_start(cubgame);
	error_serch_addres(cubgame);
}

int	func_exit_cube(t_cubd	*cubgame)
{
	mlx_destroy_window(cubgame->init_mlx, cubgame->window);
	exit(0);
}

void	game_mlx_norm2_for_all(t_cubd	*cubgame)
{
	start_draw_game1(cubgame);
	cubgame->window = mlx_new_window(cubgame->init_mlx, cubgame->w_screen, cubgame->h_screen, "CUB3D");
	mlx_hook(cubgame->window, 17, 0, exit_and_distroy, cubgame);
	mlx_hook(cubgame->window, 2, 0, key, cubgame);
	mlx_loop_hook(cubgame->init_mlx, game_drow, cubgame);
	mlx_loop(cubgame->init_mlx);
}

void	check_walk(t_cubd	*cubgame)
{
	if (!cubgame->we || !cubgame->no || !cubgame->ea || !cubgame->so)
		exit_game(cubgame, "ERROR : not walk mlx\n");
	if (!cubgame->dur || !cubgame->key1 || !cubgame->key2)
		exit_game(cubgame, "   start_draw_game1 dont can render\n");
}

void	textur_drow_wall(t_cubd	*cubgame)
{
	void	*t;
	int		i;

	i = 64;
	t = cubgame->we;
	cubgame->we = mlx_xpm_file_to_image(cubgame->init_mlx, cubgame->we, &i, &i);
	free(t);
	t = cubgame->no;
	cubgame->no = mlx_xpm_file_to_image(cubgame->init_mlx, cubgame->no, &i, &i);
	free(t);
	t = cubgame->ea;
	cubgame->ea = mlx_xpm_file_to_image(cubgame->init_mlx, cubgame->ea, &i, &i);
	free(t);
	t = cubgame->so;
	cubgame->so = mlx_xpm_file_to_image(cubgame->init_mlx, cubgame->so, &i, &i);
	free(t);
}

void	textur_drov_left_right(t_cubd	*cubgame)
{
	int	i;

	i = 64;
	cubgame->keypx = cubgame->keypx + 0.5;
	cubgame->keypy = cubgame->keypy + 0.5;
	printf("\n\n\n<<%d>>\n",cubgame->line_length[0]);
	cubgame->dur = mlx_xpm_file_to_image(cubgame->init_mlx, "textures/door.xpm", &i, &i);
	cubgame->key1 = mlx_xpm_file_to_image(cubgame->init_mlx, "textures/key_left.xpm", &i, &i);
	cubgame->key2 = mlx_xpm_file_to_image(cubgame->init_mlx, "textures/key_right.xpm", &i, &i);
}

void	start_draw_game(t_cubd	*cubgame)
{
	dx_dy(cubgame);
	if (cubgame->symbol)
	{
		cubgame->sprite = '1';
		cubgame->symbol = '0';
	}
	cubgame->init_mlx = mlx_init();
	textur_drow_wall(cubgame);
	textur_drov_left_right(cubgame);
	printf("\n1=%s \n2=%s\n3=%s\n4=%s\ncubgame->dur=%s\ncubgame->key1=%s\ncubgame->dur=%s\n", cubgame->we,cubgame->no,cubgame->ea,cubgame->so,cubgame->dur,cubgame->key1,cubgame->dur);
	check_walk(cubgame);



	game_mlx_norm2_for_all(cubgame);
}