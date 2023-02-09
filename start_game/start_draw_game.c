/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:08:17 by hvardany          #+#    #+#             */
/*   Updated: 2023/02/09 23:08:21 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	game_mlx_norm2_for_all(t_cubd	*cubgame)
{
	start_draw_game1(cubgame);
	cubgame->window = mlx_new_window(cubgame->init_mlx,
			cubgame->w_screen, cubgame->h_screen, "CUB3D");
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
	cubgame->dur = mlx_xpm_file_to_image(cubgame->init_mlx,
			"textures/door.xpm", &i, &i);
	cubgame->key1 = mlx_xpm_file_to_image(cubgame->init_mlx,
			"textures/key_left.xpm", &i, &i);
	cubgame->key2 = mlx_xpm_file_to_image(cubgame->init_mlx,
			"textures/key_right.xpm", &i, &i);
}

void	start_draw_game(t_cubd	*cubgame)
{
	dx_dy(cubgame);
	if (cubgame->is_key)
	{
		cubgame->sprite = '1';
		cubgame->is_key = '0';
	}
	cubgame->init_mlx = mlx_init();
	textur_drow_wall(cubgame);
	textur_drov_left_right(cubgame);
	check_walk(cubgame);
	game_mlx_norm2_for_all(cubgame);
}
