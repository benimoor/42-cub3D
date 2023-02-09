/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_null.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:10:03 by hvardany          #+#    #+#             */
/*   Updated: 2023/02/09 23:10:07 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	func_null1(t_cubd *cubgame)
{
	cubgame->game_player = 0;
	cubgame->timer = 0;
}

void	null_for_norm(t_cubd *cubgame)
{
	cubgame->px = 0;
	cubgame->py = 0;
	cubgame->s = 0;
	cubgame->w = 0;
	cubgame->x = 0;
	cubgame->y = 0;
	cubgame->player_h = 0;
	cubgame->have_zerro = 0;
	cubgame->flag_one = 0;
	cubgame->x_1 = 0;
	cubgame->step_flag = 0;
	func_null1(cubgame);
}

void	norm_null1(t_cubd *cubgame)
{
	cubgame->game_player = '\0';
	cubgame->c[0] = -1;
	cubgame->c[1] = -1;
	cubgame->c[2] = -1;
	cubgame->f[0] = -1;
	cubgame->f[1] = -1;
	cubgame->f[2] = -1;
	cubgame->is_key = '0';
	cubgame->sprite = '0';
	cubgame->sprite_st = '1';
	cubgame->keypy = 1;
	cubgame->keypx = 0;
	cubgame->dx = -1;
	cubgame->dy = -1;
	cubgame->h_screen = 1000;
	cubgame->w_screen = 1000;
	cubgame->a_l = 60.0 / cubgame->w_screen;
}

void	set_null(t_cubd *cubgame)
{
	cubgame->ea = NULL;
	cubgame->no = NULL;
	cubgame->so = NULL;
	cubgame->we = NULL;
	cubgame->create_fon = NULL;
	cubgame->line = NULL;
	cubgame->grafic = NULL;
	cubgame->window = NULL;
	cubgame->dur = NULL;
	cubgame->minimap = NULL;
}

void	func_null(t_cubd *cubgame)
{
	int	i;

	i = 0;
	set_null(cubgame);
	cubgame->key1 = NULL;
	cubgame->key2 = NULL;
	cubgame->init_mlx = NULL;
	while (i < 9)
	{
		cubgame->ad[i] = NULL;
		i++;
	}
	cubgame->height = 0;
	cubgame->width = 0;
	norm_null1(cubgame);
	null_for_norm(cubgame);
}
