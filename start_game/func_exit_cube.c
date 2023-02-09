/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_exit_cube.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:08:31 by hvardany          #+#    #+#             */
/*   Updated: 2023/02/09 23:08:33 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	search_null_mlx(t_cubd	*cubgame)
{
	if (!cubgame->we || !cubgame->no || !cubgame->so
		|| !cubgame->ea || !cubgame->key1 || !cubgame->key2 || !cubgame->dur)
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
	cubgame->ad[6] = mlx_get_data_addr(cubgame->dur,
			&cubgame->bits_per_pixel[6],
			&cubgame->line_length[6], &cubgame->endian[6]);
	cubgame->ad[7] = mlx_get_data_addr(cubgame->key1,
			&cubgame->bits_per_pixel[7],
			&cubgame->line_length[7], &cubgame->endian[7]);
	cubgame->ad[8] = mlx_get_data_addr(cubgame->key2,
			&cubgame->bits_per_pixel[8],
			&cubgame->line_length[8], &cubgame->endian[8]);
}

void	error_serch_addres(t_cubd	*cubgame)
{
	if (!cubgame->ad[2] || !cubgame->ad[3] || !cubgame->ad[4] || !cubgame->ad[5]
		|| !cubgame->ad[6] || !cubgame->ad[7] || !cubgame->ad[8])
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
