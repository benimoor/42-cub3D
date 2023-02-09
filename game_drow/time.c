/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:15:16 by ergrigor          #+#    #+#             */
/*   Updated: 2023/02/09 23:15:17 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	time(t_cubd *cubgame)
{
	cubgame->timer++;
	if (cubgame->timer % 20 == 0)
	{
		if (cubgame->sprite_st == '1')
			cubgame->sprite_st = '2';
		else
			cubgame->sprite_st = '1';
	}
	if (cubgame->timer >= 401)
		cubgame->timer = 1;
}

void	maprender(t_cubd *cubgame)
{
	if (cubgame->create_fon)
		mlx_destroy_image(cubgame->init_mlx, cubgame->create_fon);
	cubgame->create_fon = mlx_new_image(cubgame->init_mlx,
			cubgame->w_screen, cubgame->h_screen);
	if (!cubgame->create_fon)
		exit_and_distroy1(cubgame, "ERROR: mlx1\n");
	cubgame->ad[1] = mlx_get_data_addr(cubgame->create_fon,
			&cubgame->bits_per_pixel[1], &cubgame->line_length[1],
			&cubgame->endian[1]);
	if (!cubgame->ad[1])
		exit_and_distroy1(cubgame, "ERROR: mlx2\n");
}

int	game_drow(t_cubd *cubgame)
{
	time(cubgame);
	maprender(cubgame);
	game_drow1_sprite(cubgame);
	vertical_and_horizontal_check(cubgame);
	return (0);
}
